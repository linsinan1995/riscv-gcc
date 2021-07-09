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