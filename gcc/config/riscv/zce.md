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

(define_insn "decbnez<mode>"
  [(set (match_operand:X 0 "register_operand" "= r")
    (minus:X (match_dup 0)
      (match_operand:X 1 "imm_1_2_4_8_operand" "I")))
  (set (pc)
	(if_then_else
	 (eq:X (match_dup 0) (const_int 0))
	 (label_ref (match_operand 2 "" ""))
	 (pc)))]
  "TARGET_ZCEE"
  "decbnez\t%0,%1,%2"
  [(set_attr "type" "branch")
   (set_attr "mode" "none")])
