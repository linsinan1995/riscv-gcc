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

  4. if there is a valid argument list, then delete mv pattern and hack push rtx
    if not, skip.
*/

static rtx
gen_zce_stack_insn (rtx_insn *push_rtx, rtx_insn *candidates[4], int n_args)
{
  rtx push_pat = PATTERN (push_rtx);
  rtx new_push_insn;
  int n_old_rtx = XVECLEN (push_pat, 0);
  int n_rtx = n_old_rtx + n_args;

  new_push_insn = gen_rtx_PARALLEL (VOIDmode, rtvec_alloc (n_rtx));
  XVECEXP (new_push_insn, 0, n_rtx - 1) = XVECEXP (push_pat, 0, n_old_rtx - 1);
  for (int i = 0; i < n_old_rtx - 1; i ++)
    {
      XVECEXP (new_push_insn, 0, i) = XVECEXP (push_pat, 0, i);
    }

  for (int i = 0; i < n_args; i ++)
    {
      rtx mv_pat = PATTERN (candidates[i]);
      XVECEXP (new_push_insn, 0, n_old_rtx + i) = mv_pat;
    }

  return new_push_insn;
}

static void
replace_insns (rtx_insn *old_insn, rtx_insn *new_insns)
{
  if (new_insns)
    emit_insn_before (new_insns, old_insn);

  delete_insn (old_insn);
}

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

/* Mark every instruction that defines a register value that INSN uses.  */

static void
mark_reg_dependencies (rtx_insn *insn, sbitmap bm)
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

      bitmap_set_bit (bm, regno);

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

      bitmap_set_bit (bm, regno);

      if (dump_file)
	{
	  fprintf (dump_file, "Processing def of ");
	  print_simple_rtl (dump_file, DF_REF_REG (def));
	  fprintf (dump_file, " in insn %d:\n", INSN_UID (insn));
	}
    }
}

static unsigned int
zce_push_argument_list (void)
{
  basic_block bb;
  int total_count;
  rtx set_src;
  sbitmap arg_move;
  rtx_insn *push_rtx = NULL;
  rtx_insn *argument_list_candidates[4] = {NULL, };
  rtx_insn *insn;

  // printf ("func %s\n", IDENTIFIER_POINTER (DECL_NAME (cfun->decl)));
  auto_sbitmap args (4);
  bitmap_clear (args);

  if (dump_file)
    fprintf (dump_file, "-------- seaching for push rtx --------\n");

  FOR_EACH_BB_FN (bb, cfun)
    {
      FOR_BB_INSNS (bb, insn)
	{
	  if (!push_rtx && NOTE_P (insn) && NOTE_KIND (insn) == NOTE_INSN_PROLOGUE_END)
	    {
	      if (dump_file)
		fprintf (dump_file, "-------- no argument list --------\n");
	      return 0;
	    }

	  if (!(NONDEBUG_INSN_P (insn)
	      || CALL_P (insn)))
	    continue;

	  rtx pat = PATTERN (insn);

	  if (!push_rtx
	      && GET_CODE (pat) == PARALLEL
	      && riscv_valid_stack_push_pop_p (pat, false))
	    {
	      push_rtx = insn;
	      /* ignore sp adjust insn  */
	      total_count = XVECLEN (pat, 0) - 1;

	      /* check first saved register is ra or not  */
	      set_src = SET_SRC (XVECEXP (pat, 0, 1));
	      if (REGNO (set_src) == RETURN_ADDR_REGNUM)
		total_count --;

	      if (total_count <= 0)
		{
		  if (dump_file)
		    fprintf (dump_file, "Saved 0 s-register, stop tracking move pattern.\n", total_count);
		  return 0;
		}

	      total_count = total_count > 4 ? 4 : total_count;
	      arg_move = sbitmap_alloc (total_count);
	      bitmap_clear (arg_move);

	      if (dump_file)
		fprintf (dump_file, "-------- Saved s-register %d --------\n", total_count);
	      continue;
	    }

	  if (!push_rtx)
	    continue;

	  /* analyse mv info */
	  if (GET_CODE (pat) == SET
	      && REG_P (SET_SRC (pat))
	      && REG_P (SET_DEST (pat)))
	    {
	      unsigned src_regno = to_a_regno (REGNO (SET_SRC (pat)));
	      unsigned dst_regno = to_s_regno (REGNO (SET_DEST (pat)));

	      if (src_regno != -1
		  && dst_regno == src_regno
		  && dst_regno < total_count
		  && !bitmap_bit_p (args, src_regno))
		{
		  // valid
		  bitmap_set_bit (args, src_regno);
		  argument_list_candidates[src_regno] = insn;
		  if (dump_file)
		    fprintf (dump_file, "find pattern mv s%d,a%d\n", dst_regno, dst_regno);
		}
	    }

	  mark_reg_dependencies (insn, arg_move);
	}

      if (push_rtx)
	{
	  int i;
	  for (i = 0; i < arg_move->n_bits; i ++)
	      if (!argument_list_candidates[i])
		break;

	  if (dump_file)
	    {
	      fprintf (dump_file, "-------- bitmap release --------\npossible list: ");
	      if (i == 0)
		fprintf (dump_file, "null\n");
	      else if (i == 1)
		fprintf (dump_file, "a0\n");
	      else
		fprintf (dump_file, "a0-a%d\n", i - 1);
	    }

	  if (i > 0)
	    {
	      rtx new_push_insn = gen_zce_stack_insn (push_rtx, argument_list_candidates, i);
	      emit_insn_before (new_push_insn, push_rtx);
	      delete_insn (push_rtx);
	    }

	  while (i--)
	    delete_insn (argument_list_candidates[i]);

	  /* free bitmap */
	  sbitmap_free (arg_move);
	  return 0;
	}
    }

  return 0;
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
    { return zce_push_argument_list ();}
}; // class pass_zce_push

} // anon namespace

rtl_opt_pass *
make_pass_zce_push (gcc::context *ctxt)
{
  return new pass_zce_push (ctxt);
}
