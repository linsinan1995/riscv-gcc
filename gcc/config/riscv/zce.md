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

(define_insn "cmva01s07<mode>"
  [(set (match_operand:X 0 "a0_register")
	(match_operand:X 1 "s0s7_register"))
   (set (match_operand:X 2 "a1_register")
	(match_operand:X 3 "s0s7_register"))]
  "TARGET_ZCEE"
  "c.mva01s07\t%2, %3"
  [(set_attr "type" "zce")
   (set_attr "mode" "<MODE>")])
