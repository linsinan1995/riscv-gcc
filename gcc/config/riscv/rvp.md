;; Machine description for P extension.
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

;; A list of the modes that are up to one word long vector.
(define_mode_iterator VECI [(V4QI "!TARGET_64BIT") (V2HI "!TARGET_64BIT")
                            (V8QI "TARGET_64BIT") (V4HI "TARGET_64BIT")
			                      (V2SI "TARGET_64BIT")])
(define_mode_iterator VQIHI [(V4QI "!TARGET_64BIT") (V2HI "!TARGET_64BIT")
                             (V8QI "TARGET_64BIT") (V4HI "TARGET_64BIT")])
(define_mode_iterator VSHI [(V2HI "!TARGET_64BIT") (V2SI "TARGET_64BIT")])
(define_mode_attr VNHALF [(V2SI "SI") (V2HI "HI")])
(define_mode_attr VSH_EXT [(V2SI "DI") (V2HI "HI")])

;; <uk> expands to (un)signed (saturating) arithmetic operations
(define_code_attr uk
  [(plus "") (ss_plus "k") (us_plus "uk")
   (minus "") (ss_minus "k") (us_minus "uk")])

;; <bits> for specific bit number in 'simd' type instruction
(define_mode_attr bits [(V8QI "8") (V4QI "8") (QI "8") (V4HI "16") (V2HI "16")
			            (HI "16") (V2SI "32") (DI "64")])

;; <all_plus> and <all_minus> for all types of addtion and subtraction
(define_code_iterator all_plus [plus ss_plus us_plus])
(define_code_iterator all_minus [minus ss_minus us_minus])

;; clz and clrs
(define_code_iterator unop [clrsb clz])

;; <rvp_optab> expands to the name of the optab for a particular code.
(define_code_attr rvp_optab [(clrsb "clrsb") 
       (clz "clz")])

;; <rvp_insn> expands to the name of the insn that implements a particular code.
(define_code_attr rvp_insn [(clrsb "clrs")
			(clz "clz")])

;; k|(uk)|? add
;; zpn is a mandatory subset for p extension, thus add32 (zprv subset) can also be matched
(define_insn "<uk>add<mode>3"
  [(set (match_operand:VECI 0 "register_operand"                "=r")
	(all_plus:VECI (match_operand:VECI 1 "register_operand" " r")
		       (match_operand:VECI 2 "register_operand" " r")))]
  "TARGET_ZPN"
  "<uk>add<bits>\t%0, %1, %2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "rvp_<uk>adddi3"
  [(set (match_operand:DI 0 "register_operand"              "=r")
	(all_plus:DI (match_operand:DI 1 "register_operand" " r")
		     (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_ZPSF"
  "<uk>add64 %0, %1, %2"
  [(set_attr "type" "dsp64")
   (set_attr "mode" "DI")])

;; k|(uk)|? sub
(define_insn "<uk>sub<mode>3"
  [(set (match_operand:VECI 0 "register_operand"                  "=r")
	(all_minus:VECI (match_operand:VECI 1 "register_operand" " r")
			(match_operand:VECI 2 "register_operand" " r")))]
  "TARGET_ZPN"
  "<uk>sub<bits> %0, %1, %2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "rvp_<uk>subdi3"
  [(set (match_operand:DI 0 "register_operand"               "=r")
	(all_minus:DI (match_operand:DI 1 "register_operand" " r")
		      (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_ZPSF"
  "<uk>sub64 %0, %1, %2"
  [(set_attr "type" "dsp64")
   (set_attr "mode" "DI")])

;; uk|k add|sub w|h
(define_insn "kaddw"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:SI 2 "register_operand" "r")] UNSPEC_KADDW))]
  "TARGET_ZPN && !TARGET_64BIT"
  "kaddw\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "SI")])

(define_insn "kaddw64"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI (unspec:SI [(match_operand:SI 1 "register_operand" "r")
				    (match_operand:SI 2 "register_operand" "r")] UNSPEC_KADDW)))]
  "TARGET_ZPN && TARGET_64BIT"
  "kaddw\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "DI")])

(define_insn "ksubw"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:SI 2 "register_operand" "r")] UNSPEC_KSUBW))]
  "TARGET_ZPN && !TARGET_64BIT"
  "ksubw\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "SI")])

(define_insn "ksubw64"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI (unspec:SI [(match_operand:SI 1 "register_operand" "r")
				(match_operand:SI 2 "register_operand" "r")] UNSPEC_KSUBW)))]
  "TARGET_ZPN && TARGET_64BIT"
  "ksubw\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "DI")])

(define_insn "kaddh"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(sign_extend:SI (unspec:SI [(match_operand:SI 1 "register_operand" "r")
				    (match_operand:SI 2 "register_operand" "r")] UNSPEC_KADDH)))]
  "TARGET_ZPN"
  "kaddh\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "SI")])

(define_insn "ksubh"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(sign_extend:SI (unspec:SI [(match_operand:SI 1 "register_operand" "r")
				    (match_operand:SI 2 "register_operand" "r")] UNSPEC_KSUBH)))]
  "TARGET_ZPN"
  "ksubh\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "SI")])

(define_insn "ukaddw"
  [(set (match_operand:SI 0 "register_operand"             "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:SI 2 "register_operand" "r")] UNSPEC_UKADDW))]
  "TARGET_ZPN && !TARGET_64BIT"
  "ukaddw\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "SI")])

(define_insn "ukaddw64"
  [(set (match_operand:DI 0 "register_operand"             "=r")
	(sign_extend:DI (unspec:SI [(match_operand:SI 1 "register_operand" "r")
				    (match_operand:SI 2 "register_operand" "r")] UNSPEC_UKADDW)))]
  "TARGET_ZPN && TARGET_64BIT"
  "ukaddw\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "DI")])

(define_insn "uksubw"
  [(set (match_operand:SI 0 "register_operand"             "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:SI 2 "register_operand" "r")] UNSPEC_UKSUBW))]
  "TARGET_ZPN && !TARGET_64BIT"
  "uksubw\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "SI")])

(define_insn "uksubw64"
  [(set (match_operand:DI 0 "register_operand"             "=r")
	(sign_extend:DI (unspec:SI [(match_operand:SI 1 "register_operand" "r")
				    (match_operand:SI 2 "register_operand" "r")] UNSPEC_UKSUBW)))]
  "TARGET_ZPN && TARGET_64BIT"
  "uksubw\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "DI")])

(define_insn "ukaddh"
  [(set (match_operand:SI 0 "register_operand"             "=r")
	(sign_extend:SI (unspec:SI [(match_operand:SI 1 "register_operand" "r")
				    (match_operand:SI 2 "register_operand" "r")] UNSPEC_UKADDH)))]
  "TARGET_ZPN && !TARGET_64BIT"
  "ukaddh\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "SI")])

(define_insn "ukaddh64"
  [(set (match_operand:DI 0 "register_operand"             "=r")
	(sign_extend:DI (unspec:SI [(match_operand:SI 1 "register_operand" "r")
				    (match_operand:SI 2 "register_operand" "r")] UNSPEC_UKADDH)))]
  "TARGET_ZPN && TARGET_64BIT"
  "ukaddh\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "DI")])

(define_insn "uksubh"
  [(set (match_operand:SI 0 "register_operand"             "=r")
	(sign_extend:SI (unspec:SI [(match_operand:SI 1 "register_operand" "r")
				    (match_operand:SI 2 "register_operand" "r")] UNSPEC_UKSUBH)))]
  "TARGET_ZPN && !TARGET_64BIT"
  "uksubh\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "SI")])

(define_insn "uksubh64"
  [(set (match_operand:DI 0 "register_operand"             "=r")
	(sign_extend:DI (unspec:SI [(match_operand:SI 1 "register_operand" "r")
				    (match_operand:SI 2 "register_operand" "r")] UNSPEC_UKSUBH)))]
  "TARGET_ZPN && TARGET_64BIT"
  "uksubh\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "DI")])

;; kabs
(define_insn "kabsw"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")] UNSPEC_KABS))]
  "TARGET_ZPN"
  "kabsw\t%0, %1"
  [(set_attr "type" "dsp")
   (set_attr "mode" "SI")])

(define_insn "kabs<mode>2"
  [(set (match_operand:VECI 0 "register_operand"              "=r")
	(ss_abs:VECI (match_operand:VECI 1 "register_operand" " r")))]
  "TARGET_ZPN"
  "kabs<bits>\t%0, %1"
  [(set_attr "type"   "simd")
   (set_attr "mode" "<MODE>")])

;; ave 
(define_insn "ave"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(truncate:SI
	  (ashiftrt:DI
	    (plus:DI
	      (plus:DI
		(sign_extend:DI (match_operand:SI 1 "register_operand" "r"))
		(sign_extend:DI (match_operand:SI 2 "register_operand" "r")))
	      (const_int 1))
	  (const_int 1))))]
  "TARGET_ZPN && !TARGET_64BIT"
  "ave\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "SI")])

(define_insn "avedi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(truncate:DI
	  (ashiftrt:TI
	    (plus:TI
	      (plus:TI
		(sign_extend:TI (match_operand:DI 1 "register_operand" "r"))
		(sign_extend:TI (match_operand:DI 2 "register_operand" "r")))
	      (const_int 1))
	  (const_int 1))))]
  "TARGET_ZPN && TARGET_64BIT"
  "ave\t%0, %1, %2"
  [(set_attr "type" "dsp")
   (set_attr "mode" "DI")])

;; bitrev
(define_insn "bitrev"
  [(set (match_operand:SI 0 "register_operand"             "=r,   r")
	(unspec:SI [(match_operand:SI 1 "register_operand" " r,   r")
		    (match_operand:SI 2 "rimm5u_operand"   " r, u05")]
		   UNSPEC_BITREV))]
  "TARGET_ZPN && !TARGET_64BIT"
  "@
   bitrev\t%0, %1, %2
   bitrevi\t%0, %1, %2"
  [(set_attr "type"   "dsp")
   (set_attr "mode"   "SI")])

(define_insn "bitrev64"
  [(set (match_operand:DI 0 "register_operand"             "=r,   r")
	(unspec:DI [(match_operand:DI 1 "register_operand" " r,   r")
		    (match_operand:SI 2 "rimm6u_operand"   " r, u06")]
		   UNSPEC_BITREV))]
  "TARGET_ZPN && TARGET_64BIT"
  "@
   bitrev\t%0, %1, %2
   bitrevi\t%0, %1, %2"
  [(set_attr "type"   "dsp")
   (set_attr "mode"   "SI")])

;; bpick
(define_insn "bpick<X:mode>"
  [(set (match_operand:X 0 "register_operand"       "=r")
	  (ior:X
	    (and:X
	      (match_operand:X 1 "register_operand" " r")
	      (match_operand:X 3 "register_operand" " r"))
	    (and:X
	      (match_operand:X 2 "register_operand" " r")
	      (not:X (match_dup 3)))))]
  "TARGET_ZPN"
  "bpick\t%0, %1, %2, %3"
  [(set_attr "type"   "dsp")
   (set_attr "mode"   "<MODE>")])

;; clrov
(define_insn "clrov<X:mode>"
  [(unspec_volatile:X [(const_int 0)] UNSPEC_CLROV)]
  "TARGET_ZPN"
  "csrrci zero, vxsat, 1"
  [(set_attr "mode" "<MODE>")])

;; clrs, clz
(define_insn "<rvp_optab><mode>2"
  [(set (match_operand:VECI 0 "register_operand" "=r")
        (unop:VECI (match_operand:VECI 1 "register_operand" "r")))]
  "TARGET_ZPN"
  "<rvp_insn><bits>\t%0, %1"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "<rvp_optab>si2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unop:SI (match_operand:SI 1 "register_operand" "r")))]
  "TARGET_ZPN && !TARGET_64BIT"
  "<rvp_insn>32\t%0, %1"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

;; clo
(define_insn "clo<mode>2"
  [(set (match_operand:VECI 0 "register_operand"               "=r")
	(unspec:VECI [(match_operand:VECI 1 "register_operand" " r")]
		      UNSPEC_CLO))]
  "TARGET_ZPN"
  "clo<bits>\t%0, %1"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "closi2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r")]
		    UNSPEC_CLO))]
  "TARGET_ZPN && !TARGET_64BIT"
  "clo32\t%0, %1"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

;; simd integer compare equal
(define_insn "cmpeq<mode>"
  [(set (match_operand:VQIHI 0 "register_operand"                          "=r")
	(unspec:VQIHI [(eq:VQIHI (match_operand:VQIHI 1 "register_operand" " r")
				 (match_operand:VQIHI 2 "register_operand" " r"))]
		       UNSPEC_CMPEQ))]
  "TARGET_ZPN"
  "cmpeq<bits>\t%0, %1, %2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")]) 
