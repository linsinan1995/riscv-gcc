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

#define IN_TARGET_CODE 1

namespace {


/* Function to check whether the OP is a valid stack push/pop operation.
   For a valid stack operation, it must satisfy following conditions:
     1. Consecutive registers push/pop operations.
     2. Valid $fp/$gp/$lp push/pop operations.
     3. The last element must be stack adjustment rtx.
   See the prologue/epilogue implementation for details.  */
bool
riscv_valid_stack_push_pop_p (rtx op, bool push_p)
{
  int index;
  int total_count;
  rtx elt;
  rtx elt_reg;
  rtx elt_plus;

  if (!riscv_mzce_push_pop)
    return false;

  /* Get the counts of elements in the parallel rtx.  */
  total_count = XVECLEN (op, 0);

  /* at least sp + one callee save register rtx */
  if (total_count < 2)
    return false;

  /* Perform some quick check for that every element should be 'set'.  */
  for (index = 0; index < total_count; index++)
    {
      elt = XVECEXP (op, 0, index);
      if (GET_CODE (elt) != SET)
	return false;
    }

  elt = XVECEXP (op, 0, 0);

  /* Extract its destination and source rtx.  */
  elt_reg  = SET_DEST (elt);
  elt_plus = SET_SRC (elt);

  /* Check this is (set (stack_reg) (plus stack_reg const)) pattern.  */
  if (GET_CODE (elt_reg) != REG
      || GET_CODE (elt_plus) != PLUS
      || REGNO (elt_reg) != STACK_POINTER_REGNUM)
    return false;

  /* Pass all test, this is a valid rtx.  */
  return true;
}

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
    pushed s-registers.

  push rtx should be find before NOTE_INSN_PROLOGUE_END tag

  2. use analysis => mv s0,a0 ...
    if match, delete mv pattern and hack push rtx
    if not, skip
*/

static unsigned int
zce_push_argument_list (void)
{
  basic_block bb;
  bool find_push_rtx = false;
  int total_count;
  rtx elt_plus;
//   printf ("func %s\n", IDENTIFIER_POINTER (DECL_NAME (cfun->decl)));

  FOR_EACH_BB_FN (bb, cfun)
    {
      if (dump_file)
	fprintf (dump_file, "-------- seaching for push rtx --------\n");

      rtx_insn *insn;
      rtx pat;

      FOR_BB_INSNS (bb, insn)
	{
	  pat = PATTERN (insn);

	  if (NOTE_P (insn) && NOTE_KIND (insn) == NOTE_INSN_PROLOGUE_END)
	    {
	      if (dump_file)
		fprintf (dump_file, "-------- push rtx not found --------\n");
	      return 0;
	    }

	  if (GET_CODE (pat) == PARALLEL
	      && riscv_valid_stack_push_pop_p (pat, false))
	    {
	      total_count = XVECLEN (pat, 0);
	      /* check first saved register is ra or not  */
	      elt_plus = SET_SRC (XVECEXP (pat, 0, 1));
	      if (REGNO (elt_plus) == RETURN_ADDR_REGNUM)
		total_count --;
	      if (dump_file)
		fprintf (dump_file, "-------- Saved s-register %d --------\n", total_count - 1);
	      return 0;
	    }
	}
    }

  if (dump_file)
    fprintf (dump_file, "-------- Finish initializing --------\n");
  return 0;
}

const pass_data pass_data_zce_push =
{
  RTL_PASS, /* type */
  "zce_push", /* name */
  OPTGROUP_NONE, /* optinfo_flags */
  TV_NONE, /* tv_id */
  PROP_gimple_any, /* properties_required */
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
