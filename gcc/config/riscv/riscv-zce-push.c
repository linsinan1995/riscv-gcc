#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "backend.h"
#include "regs.h"
#include "target.h"
#include "memmodel.h"
#include "emit-rtl.h"
#include "df.h"
#include "predict.h"
#include "tree-pass.h"
#include "tree.h"
#include "tm_p.h"
#include "optabs.h"
#include "recog.h"
#include "cfgrtl.h"

#define IN_TARGET_CODE 1

namespace {
static const int INVALID_RETVAL = 99;

/*
  1. preprocessing:
    1.1. if there is no push rtx, then just return. e.g.
    (note 5 1 22 2 [bb 2] NOTE_INSN_BASIC_BLOCK)
    (insn/f 22 5 23 2 (set (reg/f:SI 2 sp)
      (plus:SI (reg/f:SI 2 sp)
	(const_int -32 [0xffffffffffffffe0])))
    (nil))
    (note 23 22 2 2 NOTE_INSN_PROLOGUE_END)
    1.2. if push rtx exists, then we compute the number of
    pushed s-registers, n_sreg.

  push rtx should be find before NOTE_INSN_PROLOGUE_END tag

  [2 and 3 happend simultaneously]
  2. find valid move pattern, mv sN, aN, where N < n_sreg,
    and aN is not used the move pattern, and sN is not
    defined before the move pattern (from prologue to the
    position of move pattern).
  3. analysis use and reach of every instruction from prologue
    to the position of move pattern.
    if any sN is used, then we mark the corresponding argument list
    candidate as invalid.
    e.g.
	push  {ra,s0-s3}, {}, -32
	sw	s0,44(sp) # s0 is used, then argument list is invalid
	mv	a0,a5     # a0 is defined, then argument list is invalid
	...
	mv	s0,a0
	mv	s1,a1
	mv	s2,a2

  4. if there is a valid argument list, then replace the old
    push parallel insn, and delete mv pattern.
     if not, skip.
*/

static int
to_a_regno (int regno)
{
  return IN_RANGE (regno, 10, 17) ? regno - 10 : -1;
}

static int
to_s_regno (int regno)
{
  return CALLEE_SAVED_REG_NUMBER (regno);
}

void
emit_zce_stack_insn (rtx_insn *old_rtx, rtx_insn **candidates, unsigned n_args, bool push_p)
{
  rtx old_pat = PATTERN (old_rtx);
  rtx new_insn;
  rtx_insn *insn;
  unsigned old_idx = 0, new_idx = 0, can_idx = 0;
  unsigned n_old = XVECLEN (old_pat, 0);
  unsigned n_new = n_old + n_args;

  if (n_args == 0)
    return;

  new_insn = gen_rtx_PARALLEL (VOIDmode, rtvec_alloc (n_new));

  /* return value insn in pop */
  if (!push_p)
    {
      if (candidates[0])
	{
	  XVECEXP (new_insn, 0, 0) = PATTERN (candidates[0]);
	  XVECEXP (new_insn, 0, 1) = PATTERN (candidates[1]);
	  delete_insn (candidates[0]);
	  delete_insn (candidates[1]);
	  new_idx += 2;
	}
      can_idx += 2;
    }

  /* Copy old insns.  */
  for (; old_idx < n_old && new_idx < n_new; old_idx ++, new_idx ++)
    XVECEXP (new_insn, 0, new_idx) = XVECEXP (old_pat, 0, old_idx);

  /* Add additional rtx.  */
  for (;new_idx < n_new; new_idx ++, can_idx ++)
    {
      rtx new_pat = PATTERN (candidates[can_idx]);
      XVECEXP (new_insn, 0, new_idx) = new_pat;
      delete_insn (candidates[can_idx]);
    }

  if (dump_file)
    {
      fprintf(dump_file, "New insn:\n");
      print_rtl (dump_file, new_insn);
    }

  insn = emit_insn_after (new_insn, old_rtx);
  RTX_FRAME_RELATED_P (insn) = 1;
  delete_insn (old_rtx);
}

static void
mark_reg_dependencies (rtx_insn *insn, sbitmap bm, int *not_avail_mv_count)
{
  df_ref use, def;
  int regno;
  int regno_pushed = bm->n_bits;

  FOR_EACH_INSN_USE (use, insn)
    {
      regno = DF_REF_REGNO (use);
      if (CALLEE_SAVED_REG_NUMBER (regno) != -1)
	regno = CALLEE_SAVED_REG_NUMBER (regno);
      else
	continue;

      if (regno >= regno_pushed)
	continue;

      if (!bitmap_bit_p (bm, regno))
	{
	  bitmap_set_bit (bm, regno);
	  (*not_avail_mv_count) ++;
	}

      if (dump_file)
	{
	  fprintf (dump_file, "Processing use of ");
	  print_simple_rtl (dump_file, DF_REF_REG (use));
	  fprintf (dump_file, " in insn %d:\n", INSN_UID (insn));
	}
    }

  FOR_EACH_INSN_DEF (def, insn)
    {
      regno = DF_REF_REGNO (def);
      if (IN_RANGE (regno, 10, 17))
	regno -= 10;
      else
	continue;

      if (regno >= regno_pushed)
	continue;

      if (!bitmap_bit_p (bm, regno))
	{
	  bitmap_set_bit (bm, regno);
	  (*not_avail_mv_count) ++;
	}

      if (dump_file)
	{
	  fprintf (dump_file, "Processing def of ");
	  print_simple_rtl (dump_file, DF_REF_REG (def));
	  fprintf (dump_file, " in insn %d:\n", INSN_UID (insn));
	}
    }
}

static void
zce_push_argument_list (void)
{
  basic_block bb;
  int total_count = 0, not_avail_mv_count = 0;
  rtx_insn *push_rtx = NULL;
  rtx_insn *argument_list_candidates[4] = {NULL, };
  rtx_insn *insn;

  auto_sbitmap args (4);
  bitmap_clear (args);

  if (dump_file)
    fprintf (dump_file, "Seaching for push rtx\n");

  FOR_EACH_BB_FN (bb, cfun)
    {
      FOR_BB_INSNS (bb, insn)
	{
	  if (!push_rtx
	      && NOTE_P (insn)
	      && NOTE_KIND (insn) == NOTE_INSN_PROLOGUE_END)
	    {
	      if (dump_file)
		fprintf (dump_file, "Push rtx not found.\n");
	      return;
	    }

	  if (!(NONDEBUG_INSN_P (insn)
	      || CALL_P (insn)))
	    continue;

	  rtx pat = PATTERN (insn);

	  if (!push_rtx
	      && GET_CODE (pat) == PARALLEL
	      && riscv_valid_stack_push_pop_p (pat, true))
	    {
	      if (dump_file)
		fprintf (dump_file, "Found push rtx\n");

	      push_rtx = insn;
	      /* ignore ra save and sp adjust insn  */
	      total_count = XVECLEN (pat, 0) - 2;

	      if (total_count <= 0)
		{
		  if (dump_file)
		    fprintf (dump_file, "Saved 0 s-register, stop tracking move pattern.\n");
		  return;
		}

	      total_count = total_count > 4 ? 4 : total_count;
	      if (dump_file)
		fprintf (dump_file, "Saved s-register %d\n", total_count);
	      continue;
	    }

	  if (!push_rtx)
	    continue;

	  /* analyse mv info */
	  if (GET_CODE (pat) == SET
	      && REG_P (SET_SRC (pat))
	      && REG_P (SET_DEST (pat)))
	    {
	      int src_regno = to_a_regno (REGNO (SET_SRC (pat)));
	      int dst_regno = to_s_regno (REGNO (SET_DEST (pat)));

	      if (src_regno != -1
		  && dst_regno == src_regno
		  && dst_regno < total_count
		  && !bitmap_bit_p (args, src_regno))
		{
		  bitmap_set_bit (args, src_regno);
		  not_avail_mv_count++;
		  argument_list_candidates[src_regno] = insn;
		  if (dump_file)
		    fprintf (dump_file, "Find pattern mv s%d,a%d\n", dst_regno, dst_regno);
		  continue;
		}
	    }

	  if (not_avail_mv_count == total_count)
	    break;
	  mark_reg_dependencies (insn, args, &not_avail_mv_count);
	}

      if (push_rtx)
	{
	  int i;
	  for (i = 0; i < total_count; i ++)
	      if (!argument_list_candidates[i])
		break;

	  if (dump_file
	      && total_count != i)
	    fprintf (dump_file, "No argument list or argument list is invalid for push.\n");

	  if (i > 0 && total_count == i)
	    emit_zce_stack_insn (push_rtx, argument_list_candidates, i, TRUE);

	  return;
	}
    }
}

int get_retval (rtx pat)
{
  rtx dest = SET_SRC (pat);

  if (CONST_INT_P (dest)
      && (INTVAL (dest) == -1
       || INTVAL (dest) == 0
       || INTVAL (dest) == 1))
    return INTVAL (dest);

  return INVALID_RETVAL;
}

void zce_pop_ret_val (void)
{
  basic_block bb;
  rtx_insn *insn = NULL, *pop_rtx = NULL;
  rtx_insn *pop_candidates[2] = {NULL, };

  if (dump_file)
    fprintf (dump_file, "Seaching for pop rtx\n");

  FOR_EACH_BB_REVERSE_FN (bb, cfun)
  {
    unsigned n_args = 0;
    FOR_BB_INSNS_REVERSE (bb, insn)
      {
	if (!pop_rtx
	    && NOTE_P (insn)
	    && NOTE_KIND (insn) == NOTE_INSN_EPILOGUE_BEG)
	  return;

	if (NOTE_P (insn)
	    && NOTE_KIND (insn) == NOTE_INSN_FUNCTION_BEG)
	  {
	    emit_zce_stack_insn (pop_rtx, pop_candidates, n_args, FALSE);
	    return;
	  };

	if (!(NONDEBUG_INSN_P (insn)))
	  continue;

	rtx pop_pat = PATTERN (insn);

	if (GET_CODE (pop_pat) == PARALLEL
	    && riscv_valid_stack_push_pop_p (pop_pat, false))
	  {
	    pop_rtx = insn;
	    continue;
	  }

	if (!pop_rtx)
	  continue;

	/* pattern for return value.  */
	if (!pop_candidates [0]
	    && GET_CODE (pop_pat) == USE)
	  {
	    rtx_insn *set_insn = PREV_INSN (insn);

	    if (regno_p (XEXP (pop_pat, 0), RETURN_VALUE_REGNUM)
		&& insn
		&& GET_CODE (PATTERN (set_insn)) == SET
		&& regno_p (SET_DEST (PATTERN (set_insn)), RETURN_VALUE_REGNUM))
	      {
		int retval = get_retval (PATTERN (set_insn));
		if (retval != INVALID_RETVAL)
		  {
		    pop_candidates [0] = set_insn;
		    pop_candidates [1] = insn;
		    n_args += 2;
		  }
		break;
	      }
	  }
      }

    if (pop_rtx)
      {
	emit_zce_stack_insn (pop_rtx, pop_candidates, n_args, FALSE);
	return;
      }
  }
}

const pass_data pass_data_zce_push =
{
  RTL_PASS, /* type */
  "zce-push", /* name */
  OPTGROUP_NONE, /* optinfo_flags */
  TV_NONE, /* tv_id */
  0, /* properties_required */
  0, /* properties_provided */
  0, /* properties_destroyed */
  0, /* todo_flags_start */
  0, /* todo_flags_finish */
};

class pass_zce_push : public rtl_opt_pass
{
public:
  pass_zce_push (gcc::context *ctxt)
    : rtl_opt_pass (pass_data_zce_push, ctxt)
  {}

  /* opt_pass methods: */
  virtual bool gate (function *)
    { return riscv_mzce_push_pop; }
  virtual unsigned int execute (function *)
    {
      zce_push_argument_list ();
      zce_pop_ret_val ();
      return 0;
    }
}; // class pass_zce_push

} // anon namespace

rtl_opt_pass *
make_pass_zce_push (gcc::context *ctxt)
{
  return new pass_zce_push (ctxt);
}
