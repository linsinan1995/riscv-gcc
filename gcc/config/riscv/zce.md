;; Machine description for ZCE extension.
;; Copyright (C) 2021 Free Software Foundation, Inc.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.

;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

(define_insn "*zcea_branching<mode>"
  [(set (pc)
	(if_then_else
	 (match_operator 1 "zcea_branching_operator"
			 [(match_operand:X 2 "register_operand" "r")
			  (match_operand:X 3 "imm5u_operand" "u05")])
	 (label_ref (match_operand 0 "" ""))
	 (pc)))]
  "TARGET_ZCEA"
  "b%C1i\t%2,%z3,%0"
  [(set_attr "type" "branch")
   (set_attr "mode" "none")])

(define_insn "*mul<mode>3_zcea"
  [(set (match_operand:X          0 "register_operand" "=r")
	(mult:X (match_operand:X 1 "register_operand" " r")
		 (match_operand:X 2 "const_arith_operand" " I")))]
  "TARGET_MUL && TARGET_ZCEA && riscv_mzce_muli"
  "muli\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "<MODE>")])

(define_insn "*stack_push<mode>"
  [(match_parallel 0 "riscv_stack_push_operation"
    [(set (reg:X SP_REGNUM) (plus:X (reg:X SP_REGNUM)
      (match_operand:X 1 "const_int_operand" "")))])]
  "TARGET_ZCEA"
  {
    static char push_templ[64];
    unsigned total_count = 0;

    /* ignore register list. */
    for (int idx = XVECLEN (operands[0], 0) - 1; idx >= 0; --idx)
      {
	rtx ele = XVECEXP (operands[0], 0, idx);
	if (!(GET_CODE (ele) == SET
	    && REG_P (SET_SRC (ele))
	    && REG_P (SET_DEST (ele))))
	  break;
	++total_count;
      }

    if (total_count > 1)
      sprintf(push_templ, "push\t{%%L0},{a0-a%u},%%1", total_count - 1);
    else if (total_count == 1)
      sprintf(push_templ, "push\t{%%L0},{a0},%%1");
    else
      sprintf(push_templ, "push\t{%%L0},%%1");

    return push_templ;
  })

(define_insn "*stack_pop<mode>"
  [(match_parallel 0 "riscv_stack_pop_operation"
    [(set (match_operand:X 1 "register_operand" "")
      (mem:X (plus:X (reg:X SP_REGNUM)
	(match_operand:X 2 "const_int_operand" ""))))])]
  "TARGET_ZCEA"
  {
    return riscv_output_popret_p (operands[0]) ?
	"popret\t{%L0},%S0" :
	"pop\t{%L0},%S0";
  })

(define_insn "*stack_pop_with_return_value<mode>"
  [(match_parallel 0 "riscv_stack_pop_operation"
    [(set (reg:X A0_REGNUM)
      (match_operand:X 1 "pop_return_value_constant" ""))])]
  "TARGET_ZCEA"
  {
    return riscv_output_popret_p (operands[0]) ?
	"popret\t{%L0},{%1},%S0" :
	"pop\t{%L0},{%1},%S0";
  })
