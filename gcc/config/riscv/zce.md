;; Machine description for K extension.
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




;;ZCEE SEXT
(define_insn "*sign_extendqi<GPR:mode>2_zce"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(sign_extend:GPR (match_operand:QI 1 "nonimmediate_operand" "r")))]
  "TARGET_ZCEE"
  "sext.h\t%0,%1"
  [(set_attr "type" "zce")])

(define_insn "*sign_extendhi<GPR:mode>2_zce"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(sign_extend:GPR (match_operand:HI 1 "nonimmediate_operand" "r")))]
  "TARGET_ZCEE"
  "sext.h\t%0,%1"
  [(set_attr "type" "zce")])

(define_insn "*sign_extendsidi2_zce"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI (match_operand:SI 1 "nonimmediate_operand" "r")))]
  "TARGET_64BIT && TARGET_ZCEE"
  "sext.w\t%0,%1"
  [(set_attr "type" "zce")])

;;ZCEE ZEXT
(define_insn "*zero_extendqi<GPR:mode>2_zce"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(zero_extend:GPR (match_operand:QI 1 "nonimmediate_operand" "r")))]
  "TARGET_ZCEE"
  "zext.h\t%0,%1"
  [(set_attr "type" "zce")])

(define_insn "*zero_extendhi<GPR:mode>2_zce"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(zero_extend:GPR (match_operand:HI 1 "nonimmediate_operand" "r")))]
  "TARGET_ZCEE"
  "zext.h\t%0,%1"
  [(set_attr "type" "zce")])

(define_insn "*zero_extendsidi2_zce"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(zero_extend:DI (match_operand:SI 1 "nonimmediate_operand" "r")))]
  "TARGET_64BIT && TARGET_ZCEE"
  "zext.w\t%0,%1"
  [(set_attr "type" "zce")])

;;ZCEE C.MUL
(define_insn "riscv_c_mul_<mode>"
  [(set (match_operand:X                       0 "register_operand" "=r")
	(sign_extend:X
	  (subreg:QI (mult:QI (match_operand:DI 1 "register_operand" " r")
			      (match_operand:DI 2 "register_operand" " r"))
		     0)))]
  "TARGET_ZCEE"
  "c.mul\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "QI")])

;;ZCEA MULI

(define_insn "riscv_muli_<mode>"
  [(set (match_operand:X                       0 "register_operand" "=r")
	(sign_extend:X
	  (subreg:QI (mult:QI (match_operand:DI 1 "register_operand" " r")
			      (match_operand:DI 2 "immediate_operand" " i"))
		     0)))]
  "TARGET_ZCEA"
  "c.mul\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "QI")])


;;ZCEA NOT && NEG
(define_insn "riscv_c_not_<mode>"
  [(set (match_operand:X         0 "register_operand" "=r")
	(not:X (match_operand:QI 1 "register_operand" " r")))]
  "TARGET_ZCEA"
  "not\t%0,%1"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "riscv_c_neg_<mode>"
  [(set (match_operand:X         0 "register_operand" "=r")
	(neg:X (match_operand:QI 1 "register_operand" " r")))]
  "TARGET_ZCEA"
  "neg\t%0,%1"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])


;;ZCEA  POP
(define_insn "pop"
  [(set (match_operand:HI 0 "register_operand" "=r")
	(mem:HI (post_inc:HI (reg:HI S2_REGNUM))))]
  "TARGET_ZCEA"
  "POP\t%0"
  )

;;ZCEA  PUSH
(define_insn "push"
  [(set (mem:HI (pre_dec:HI (reg:HI S2_REGNUM)))
	(match_operand:HI 0 "register_operand" "r"))]
  "TARGET_ZCEA"
  "PUSH\t%0"
  )

;;ZCEA BEQ、BNE
(define_insn "*beq"
  [(set (pc)
        (if_then_else (eq:SI (match_operand:SI 0 "reg_or_0_operand" "rJ")
                             (match_operand:SI 1 "reg_or_0_operand" "rJ"))
                      (label_ref (match_operand 2 "" ""))
                      (pc)))]
  "TARGET_ZCEA"
{
  return get_attr_length (insn) == 4
        ? "beqi     %z0,%z1,%2"
        : "bnei    %z0,%z1,8\n\tbi     %2";
}  
  [(set_attr "type" "branch")])

(define_insn "*bne"
  [(set (pc)
        (if_then_else (ne:SI (match_operand:SI 0 "reg_or_0_operand" "rJ")
                             (match_operand:SI 1 "reg_or_0_operand" "rJ"))
                      (label_ref (match_operand 2 "" ""))
                      (pc)))]
  "TARGET_ZCEA"
{
  return get_attr_length (insn) == 4
        ? "bnei    %z0,%z1,%2"
        : "beqi     %z0,%z1,8\n\tbi     %2";
}  
  [(set_attr "type" "branch")])


