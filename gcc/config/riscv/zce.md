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

;;ZCEE C.MUL
(define_insn "riscv_c_mul_<X:mode>"
  [(set (match_operand:X                       0 "register_operand" "=Z")
	(sign_extend:X
	  (subreg:QI (mult:QI (match_operand:DI 1 "register_operand" " Z")
			      (match_operand:DI 2 "register_operand" " Z"))
		     0)))]
  "TARGET_ZCEE"
  "c.mul\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "<X:MODE>")])
