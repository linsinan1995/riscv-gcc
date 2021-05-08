/* Builtin definitions for P extension
   Copyright (C) 2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef _RISCV_RVP_INTRINSIC_H
#define _RISCV_RVP_INTRINSIC_H

typedef signed char int8x4_t __attribute ((vector_size(4)));
typedef signed char int8x8_t __attribute ((vector_size(8)));
typedef short int16x2_t __attribute ((vector_size(4)));
typedef short int16x4_t __attribute__((vector_size (8)));
typedef short int16x8_t __attribute__((vector_size (16)));
typedef int int32x2_t __attribute__((vector_size(8)));
typedef int int32x4_t __attribute__((vector_size(16)));
typedef unsigned char uint8x4_t __attribute__ ((vector_size (4)));
typedef unsigned char uint8x8_t __attribute__ ((vector_size (8)));
typedef unsigned short uint16x2_t __attribute__ ((vector_size (4)));
typedef unsigned short uint16x4_t __attribute__((vector_size (8)));
typedef unsigned short uint16x8_t __attribute__((vector_size (16)));
typedef unsigned int uint32x2_t __attribute__((vector_size(8)));
typedef unsigned int uint32x4_t __attribute__((vector_size(16)));

// zpn
#define __rv__kabsw(a) \
  (__builtin_riscv_kabsw ((a)))
#define __rv__add16(a, b) \
  (__builtin_riscv_add16 ((a), (b)))
#define __rv__radd16(a, b) \
  (__builtin_riscv_radd16 ((a), (b)))
#define __rv__uradd16(a, b) \
  (__builtin_riscv_uradd16 ((a), (b)))
#define __rv__kadd16(a, b) \
  (__builtin_riscv_kadd16 ((a), (b)))
#define __rv__ukadd16(a, b) \
  (__builtin_riscv_ukadd16 ((a), (b)))
#define __rv__sub16(a, b) \
  (__builtin_riscv_sub16 ((a), (b)))
#define __rv__rsub16(a, b) \
  (__builtin_riscv_rsub16 ((a), (b)))
#define __rv__ursub16(a, b) \
  (__builtin_riscv_ursub16 ((a), (b)))
#define __rv__ksub16(a, b) \
  (__builtin_riscv_ksub16 ((a), (b)))
#define __rv__uksub16(a, b) \
  (__builtin_riscv_uksub16 ((a), (b)))
#define __rv__cras16(a, b) \
  (__builtin_riscv_cras16 ((a), (b)))
#define __rv__rcras16(a, b) \
  (__builtin_riscv_rcras16 ((a), (b)))
#define __rv__urcras16(a, b) \
  (__builtin_riscv_urcras16 ((a), (b)))
#define __rv__kcras16(a, b) \
  (__builtin_riscv_kcras16 ((a), (b)))
#define __rv__ukcras16(a, b) \
  (__builtin_riscv_ukcras16 ((a), (b)))
#define __rv__crsa16(a, b) \
  (__builtin_riscv_crsa16 ((a), (b)))
#define __rv__rcrsa16(a, b) \
  (__builtin_riscv_rcrsa16 ((a), (b)))
#define __rv__urcrsa16(a, b) \
  (__builtin_riscv_urcrsa16 ((a), (b)))
#define __rv__kcrsa16(a, b) \
  (__builtin_riscv_kcrsa16 ((a), (b)))
#define __rv__ukcrsa16(a, b) \
  (__builtin_riscv_ukcrsa16 ((a), (b)))
#define __rv__stas16(a, b) \
  (__builtin_riscv_stas16 ((a), (b)))
#define __rv__rstas16(a, b) \
  (__builtin_riscv_rstas16 ((a), (b)))
#define __rv__urstas16(a, b) \
  (__builtin_riscv_urstas16 ((a), (b)))
#define __rv__kstas16(a, b) \
  (__builtin_riscv_kstas16 ((a), (b)))
#define __rv__ukstas16(a, b) \
  (__builtin_riscv_ukstas16 ((a), (b)))
#define __rv__stsa16(a, b) \
  (__builtin_riscv_stsa16 ((a), (b)))
#define __rv__rstsa16(a, b) \
  (__builtin_riscv_rstsa16 ((a), (b)))
#define __rv__urstsa16(a, b) \
  (__builtin_riscv_urstsa16 ((a), (b)))
#define __rv__kstsa16(a, b) \
  (__builtin_riscv_kstsa16 ((a), (b)))
#define __rv__ukstsa16(a, b) \
  (__builtin_riscv_ukstsa16 ((a), (b)))
#define __rv__add8(a, b) \
  (__builtin_riscv_add8 ((a), (b)))
#define __rv__radd8(a, b) \
  (__builtin_riscv_radd8 ((a), (b)))
#define __rv__uradd8(a, b) \
  (__builtin_riscv_uradd8 ((a), (b)))
#define __rv__kadd8(a, b) \
  (__builtin_riscv_kadd8 ((a), (b)))
#define __rv__ukadd8(a, b) \
  (__builtin_riscv_ukadd8 ((a), (b)))
#define __rv__sub8(a, b) \
  (__builtin_riscv_sub8 ((a), (b)))
#define __rv__rsub8(a, b) \
  (__builtin_riscv_rsub8 ((a), (b)))
#define __rv__ursub8(a, b) \
  (__builtin_riscv_ursub8 ((a), (b)))
#define __rv__ksub8(a, b) \
  (__builtin_riscv_ksub8 ((a), (b)))
#define __rv__uksub8(a, b) \
  (__builtin_riscv_uksub8 ((a), (b)))
#define __rv__sra16(a, b) \
  (__builtin_riscv_sra16 ((a), (b)))
#define __rv__sra16_u(a, b) \
  (__builtin_riscv_sra16_u ((a), (b)))
#define __rv__srl16(a, b) \
  (__builtin_riscv_srl16 ((a), (b)))
#define __rv__srl16_u(a, b) \
  (__builtin_riscv_srl16_u ((a), (b)))
#define __rv__sll16(a, b) \
  (__builtin_riscv_sll16 ((a), (b)))
#define __rv__ksll16(a, b) \
  (__builtin_riscv_ksll16 ((a), (b)))
#define __rv__kslra16(a, b) \
  (__builtin_riscv_kslra16 ((a), (b)))
#define __rv__kslra16_u(a, b) \
  (__builtin_riscv_kslra16_u ((a), (b)))
#define __rv__cmpeq16(a, b) \
  (__builtin_riscv_cmpeq16 ((a), (b)))
#define __rv__scmplt16(a, b) \
  (__builtin_riscv_scmplt16 ((a), (b)))
#define __rv__scmple16(a, b) \
  (__builtin_riscv_scmple16 ((a), (b)))
#define __rv__ucmplt16(a, b) \
  (__builtin_riscv_ucmplt16 ((a), (b)))
#define __rv__ucmple16(a, b) \
  (__builtin_riscv_ucmple16 ((a), (b)))
#define __rv__cmpeq8(a, b) \
  (__builtin_riscv_cmpeq8 ((a), (b)))
#define __rv__scmplt8(a, b) \
  (__builtin_riscv_scmplt8 ((a), (b)))
#define __rv__scmple8(a, b) \
  (__builtin_riscv_scmple8 ((a), (b)))
#define __rv__ucmplt8(a, b) \
  (__builtin_riscv_ucmplt8 ((a), (b)))
#define __rv__ucmple8(a, b) \
  (__builtin_riscv_ucmple8 ((a), (b)))
#define __rv__smin16(a, b) \
  (__builtin_riscv_smin16 ((a), (b)))
#define __rv__umin16(a, b) \
  (__builtin_riscv_umin16 ((a), (b)))
#define __rv__smax16(a, b) \
  (__builtin_riscv_smax16 ((a), (b)))
#define __rv__umax16(a, b) \
  (__builtin_riscv_umax16 ((a), (b)))
#define __rv__sclip16(a, b) \
  (__builtin_riscv_sclip16 ((a), (b)))
#define __rv__uclip16(a, b) \
  (__builtin_riscv_uclip16 ((a), (b)))
#define __rv__khm16(a, b) \
  (__builtin_riscv_khm16 ((a), (b)))
#define __rv__khmx16(a, b) \
  (__builtin_riscv_khmx16 ((a), (b)))
#define __rv__khm8(a, b) \
  (__builtin_riscv_khm8 ((a), (b)))
#define __rv__khmx8(a, b) \
  (__builtin_riscv_khmx8 ((a), (b)))
#define __rv__kabs16(a) \
  (__builtin_riscv_kabs16 ((a)))
#define __rv__smin8(a, b) \
  (__builtin_riscv_smin8 ((a), (b)))
#define __rv__umin8(a, b) \
  (__builtin_riscv_umin8 ((a), (b)))
#define __rv__smax8(a, b) \
  (__builtin_riscv_smax8 ((a), (b)))
#define __rv__umax8(a, b) \
  (__builtin_riscv_umax8 ((a), (b)))
#define __rv__kabs8(a) \
  (__builtin_riscv_kabs8 ((a)))
#define __rv__sunpkd810(a) \
  (__builtin_riscv_sunpkd810 ((a)))
#define __rv__sunpkd820(a) \
  (__builtin_riscv_sunpkd820 ((a)))
#define __rv__sunpkd830(a) \
  (__builtin_riscv_sunpkd830 ((a)))
#define __rv__sunpkd831(a) \
  (__builtin_riscv_sunpkd831 ((a)))
#define __rv__sunpkd832(a) \
  (__builtin_riscv_sunpkd832 ((a)))
#define __rv__zunpkd810(a) \
  (__builtin_riscv_zunpkd810 ((a)))
#define __rv__zunpkd820(a) \
  (__builtin_riscv_zunpkd820 ((a)))
#define __rv__zunpkd830(a) \
  (__builtin_riscv_zunpkd830 ((a)))
#define __rv__zunpkd831(a) \
  (__builtin_riscv_zunpkd831 ((a)))
#define __rv__zunpkd832(a) \
  (__builtin_riscv_zunpkd832 ((a)))
#define __rv__raddw(a, b) \
  (__builtin_riscv_raddw ((a), (b)))
#define __rv__uraddw(a, b) \
  (__builtin_riscv_uraddw ((a), (b)))
#define __rv__rsubw(a, b) \
  (__builtin_riscv_rsubw ((a), (b)))
#define __rv__ursubw(a, b) \
  (__builtin_riscv_ursubw ((a), (b)))
#define __rv__sra_u(a, b) \
  (__builtin_riscv_sra_u ((a), (b)))
#define __rv__ksllw(a, b) \
  (__builtin_riscv_ksllw ((a), (b)))
#define __rv__pkbb16(a, b) \
  (__builtin_riscv_pkbb16 ((a), (b)))
#define __rv__pkbt16(a, b) \
  (__builtin_riscv_pkbt16 ((a), (b)))
#define __rv__pktb16(a, b) \
  (__builtin_riscv_pktb16 ((a), (b)))
#define __rv__pktt16(a, b) \
  (__builtin_riscv_pktt16 ((a), (b)))
#define __rv__smmul(a, b) \
  (__builtin_riscv_smmul ((a), (b)))
#define __rv__smmul_u(a, b) \
  (__builtin_riscv_smmul_u ((a), (b)))
#define __rv__kmmac(r, a, b) \
  (__builtin_riscv_kmmac ((r), (a), (b)))
#define __rv__kmmac_u(r, a, b) \
  (__builtin_riscv_kmmac_u ((r), (a), (b)))
#define __rv__kmmsb(r, a, b) \
  (__builtin_riscv_kmmsb ((r), (a), (b)))
#define __rv__kmmsb_u(r, a, b) \
  (__builtin_riscv_kmmsb_u ((r), (a), (b)))
#define __rv__kwmmul(a, b) \
  (__builtin_riscv_kwmmul ((a), (b)))
#define __rv__kwmmul_u(a, b) \
  (__builtin_riscv_kwmmul_u ((a), (b)))
#define __rv__smmwb(a, b) \
  (__builtin_riscv_smmwb ((a), (b)))
#define __rv__smmwb_u(a, b) \
  (__builtin_riscv_smmwb_u ((a), (b)))
#define __rv__smmwt(a, b) \
  (__builtin_riscv_smmwt ((a), (b)))
#define __rv__smmwt_u(a, b) \
  (__builtin_riscv_smmwt_u ((a), (b)))
#define __rv__kmmwb2(a, b) \
  (__builtin_riscv_kmmwb2 ((a), (b)))
#define __rv__kmmwb2_u(a, b) \
  (__builtin_riscv_kmmwb2_u ((a), (b)))
#define __rv__kmmwt2(a, b) \
  (__builtin_riscv_kmmwt2 ((a), (b)))
#define __rv__kmmwt2_u(a, b) \
  (__builtin_riscv_kmmwt2_u ((a), (b)))
#define __rv__kmmawb(r, a, b) \
  (__builtin_riscv_kmmawb ((r), (a), (b)))
#define __rv__kmmawb_u(r, a, b) \
  (__builtin_riscv_kmmawb_u ((r), (a), (b)))
#define __rv__kmmawt(r, a, b) \
  (__builtin_riscv_kmmawt ((r), (a), (b)))
#define __rv__kmmawt_u(r, a, b) \
  (__builtin_riscv_kmmawt_u ((r), (a), (b)))
#define __rv__kmmawb2(r, a, b) \
  (__builtin_riscv_kmmawb2 ((r), (a), (b)))
#define __rv__kmmawb2_u(r, a, b) \
  (__builtin_riscv_kmmawb2_u ((r), (a), (b)))
#define __rv__kmmawt2(r, a, b) \
  (__builtin_riscv_kmmawt2 ((r), (a), (b)))
#define __rv__kmmawt2_u(r, a, b) \
  (__builtin_riscv_kmmawt2_u ((r), (a), (b)))
#define __rv__smbb16(a, b) \
  (__builtin_riscv_smbb16 ((a), (b)))
#define __rv__smbt16(a, b) \
  (__builtin_riscv_smbt16 ((a), (b)))
#define __rv__smtt16(a, b) \
  (__builtin_riscv_smtt16 ((a), (b)))
#define __rv__kmda(a, b) \
  (__builtin_riscv_kmda ((a), (b)))
#define __rv__kmxda(a, b) \
  (__builtin_riscv_kmxda ((a), (b)))
#define __rv__smds(a, b) \
  (__builtin_riscv_smds ((a), (b)))
#define __rv__smdrs(a, b) \
  (__builtin_riscv_smdrs ((a), (b)))
#define __rv__smxds(a, b) \
  (__builtin_riscv_smxds ((a), (b)))
#define __rv__kmabb(r, a, b) \
  (__builtin_riscv_kmabb ((r), (a), (b)))
#define __rv__kmabt(r, a, b) \
  (__builtin_riscv_kmabt ((r), (a), (b)))
#define __rv__kmatt(r, a, b) \
  (__builtin_riscv_kmatt ((r), (a), (b)))
#define __rv__kmada(r, a, b) \
  (__builtin_riscv_kmada ((r), (a), (b)))
#define __rv__kmaxda(r, a, b) \
  (__builtin_riscv_kmaxda ((r), (a), (b)))
#define __rv__kmads(r, a, b) \
  (__builtin_riscv_kmads ((r), (a), (b)))
#define __rv__kmadrs(r, a, b) \
  (__builtin_riscv_kmadrs ((r), (a), (b)))
#define __rv__kmaxds(r, a, b) \
  (__builtin_riscv_kmaxds ((r), (a), (b)))
#define __rv__kmsda(r, a, b) \
  (__builtin_riscv_kmsda ((r), (a), (b)))
#define __rv__kmsxda(r, a, b) \
  (__builtin_riscv_kmsxda ((r), (a), (b)))
#define __rv__bitrev(a, b) \
  (__builtin_riscv_bitrev ((a), (b)))
#define __rv__bpick(r, a, b) \
  (__builtin_riscv_bpick ((r), (a), (b)))
#define __rv__insb(r, a, b) \
  (__builtin_riscv_insb ((r), (a), (b)))
#define __rv__kaddw(a, b) \
  (__builtin_riscv_kaddw ((a), (b)))
#define __rv__kaddh(a, b) \
  (__builtin_riscv_kaddh ((a), (b)))
#define __rv__ksubw(a, b) \
  (__builtin_riscv_ksubw ((a), (b)))
#define __rv__ksubh(a, b) \
  (__builtin_riscv_ksubh ((a), (b)))
#define __rv__ukaddw(a, b) \
  (__builtin_riscv_ukaddw ((a), (b)))
#define __rv__ukaddh(a, b) \
  (__builtin_riscv_ukaddh ((a), (b)))
#define __rv__uksubw(a, b) \
  (__builtin_riscv_uksubw ((a), (b)))
#define __rv__uksubh(a, b) \
  (__builtin_riscv_uksubh ((a), (b)))
#define __rv__kdmbb(a, b) \
  (__builtin_riscv_kdmbb ((a), (b)))
#define __rv__kdmbt(a, b) \
  (__builtin_riscv_kdmbt ((a), (b)))
#define __rv__kdmtt(a, b) \
  (__builtin_riscv_kdmtt ((a), (b)))
#define __rv__khmbb(a, b) \
  (__builtin_riscv_khmbb ((a), (b)))
#define __rv__khmbt(a, b) \
  (__builtin_riscv_khmbt ((a), (b)))
#define __rv__khmtt(a, b) \
  (__builtin_riscv_khmtt ((a), (b)))
#define __rv__kslraw(a, b) \
  (__builtin_riscv_kslraw ((a), (b)))
#define __rv__kslraw_u(a, b) \
  (__builtin_riscv_kslraw_u ((a), (b)))
#define __rv__ave(a, b) \
  (__builtin_riscv_ave ((a), (b)))
#define __rv__maxw(a, b) \
  (__builtin_riscv_maxw ((a), (b)))
#define __rv__minw(a, b) \
  (__builtin_riscv_minw ((a), (b)))
#define __rv__sra8(a, b) \
  (__builtin_riscv_sra8 ((a), (b)))
#define __rv__sra8_u(a, b) \
  (__builtin_riscv_sra8_u ((a), (b)))
#define __rv__srl8(a, b) \
  (__builtin_riscv_srl8 ((a), (b)))
#define __rv__srl8_u(a, b) \
  (__builtin_riscv_srl8_u ((a), (b)))
#define __rv__sll8(a, b) \
  (__builtin_riscv_sll8 ((a), (b)))
#define __rv__ksll8(a, b) \
  (__builtin_riscv_ksll8 ((a), (b)))
#define __rv__kslra8(a, b) \
  (__builtin_riscv_kslra8 ((a), (b)))
#define __rv__kslra8_u(a, b) \
  (__builtin_riscv_kslra8_u ((a), (b)))
#define __rv__pbsad(a, b) \
  (__builtin_riscv_pbsad ((a), (b)))
#define __rv__pbsada(acc, a, b) \
  (__builtin_riscv_pbsada ((acc), (a), (b)))
#define __rv__swap8(a) \
  (__builtin_riscv_swap8 ((a)))
#define __rv__swap16(a) \
  (__builtin_riscv_pkbt16 ((a), (a)))
#define __rv__sclip8(a, b) \
  (__builtin_riscv_sclip8 ((a), (b)))
#define __rv__uclip8(a, b) \
  (__builtin_riscv_uclip8 ((a), (b)))
#define __rv__rdov() \
  (__builtin_riscv_rdov())
#define __rv__clrov() \
  (__builtin_riscv_clrov())
#define __rv__kdmabb(r, a, b) \
  (__builtin_riscv_kdmabb ((r), (a), (b)))
#define __rv__kdmabt(r, a, b) \
  (__builtin_riscv_kdmabt ((r), (a), (b)))
#define __rv__kdmatt(r, a, b) \
  (__builtin_riscv_kdmatt ((r), (a), (b)))
#define __rv__smaqa(r, a, b) \
  (__builtin_riscv_smaqa ((r), (a), (b)))
#define __rv__umaqa(r, a, b) \
  (__builtin_riscv_umaqa ((r), (a), (b)))
#define __rv__smaqa_su(r, a, b) \
  (__builtin_riscv_smaqa_su ((r), (a), (b)))
#define __rv__clrs8(a) \
  (__builtin_riscv_clrs8 ((a)))
#define __rv__clrs16(a) \
  (__builtin_riscv_clrs16 ((a)))
#define __rv__clrs32(a) \
  (__builtin_riscv_clrs32 ((a)))
#define __rv__clo8(a) \
  (__builtin_riscv_clo8 ((a)))
#define __rv__clo16(a) \
  (__builtin_riscv_clo16 ((a)))
#define __rv__clo32(a) \
  (__builtin_riscv_clo32 ((a)))
#define __rv__clz8(a) \
  (__builtin_riscv_clz8 ((a)))
#define __rv__clz16(a) \
  (__builtin_riscv_clz16 ((a)))
#define __rv__clz32(a) \
  (__builtin_riscv_clz32 ((a)))
#define __rv__uclip32(a, imm) \
  (__builtin_riscv_uclip32 ((a), (imm)))
#define __rv__sclip32(a, imm) \
  (__builtin_riscv_sclip32 ((a), (imm)))
#if __riscv_xlen == 32
#define __rv__v_uadd16(a, b) \
  (__builtin_riscv_v_uadd16 ((a), (b)))
#define __rv__v_sadd16(a, b) \
  (__builtin_riscv_v_sadd16 ((a), (b)))
#define __rv__v_radd16(a, b) \
  (__builtin_riscv_v_radd16 ((a), (b)))
#define __rv__v_uradd16(a, b) \
  (__builtin_riscv_v_uradd16 ((a), (b)))
#define __rv__v_kadd16(a, b) \
  (__builtin_riscv_v_kadd16 ((a), (b)))
#define __rv__v_ukadd16(a, b) \
  (__builtin_riscv_v_ukadd16 ((a), (b)))
#define __rv__v_usub16(a, b) \
  (__builtin_riscv_v_usub16 ((a), (b)))
#define __rv__v_ssub16(a, b) \
  (__builtin_riscv_v_ssub16 ((a), (b)))
#define __rv__v_rsub16(a, b) \
  (__builtin_riscv_v_rsub16 ((a), (b)))
#define __rv__v_ursub16(a, b) \
  (__builtin_riscv_v_ursub16 ((a), (b)))
#define __rv__v_ksub16(a, b) \
  (__builtin_riscv_v_ksub16 ((a), (b)))
#define __rv__v_uksub16(a, b) \
  (__builtin_riscv_v_uksub16 ((a), (b)))
#define __rv__v_ucras16(a, b) \
  (__builtin_riscv_v_ucras16 ((a), (b)))
#define __rv__v_scras16(a, b) \
  (__builtin_riscv_v_scras16 ((a), (b)))
#define __rv__v_rcras16(a, b) \
  (__builtin_riscv_v_rcras16 ((a), (b)))
#define __rv__v_urcras16(a, b) \
  (__builtin_riscv_v_urcras16 ((a), (b)))
#define __rv__v_kcras16(a, b) \
  (__builtin_riscv_v_kcras16 ((a), (b)))
#define __rv__v_ukcras16(a, b) \
  (__builtin_riscv_v_ukcras16 ((a), (b)))
#define __rv__v_ucrsa16(a, b) \
  (__builtin_riscv_v_ucrsa16 ((a), (b)))
#define __rv__v_scrsa16(a, b) \
  (__builtin_riscv_v_scrsa16 ((a), (b)))
#define __rv__v_rcrsa16(a, b) \
  (__builtin_riscv_v_rcrsa16 ((a), (b)))
#define __rv__v_urcrsa16(a, b) \
  (__builtin_riscv_v_urcrsa16 ((a), (b)))
#define __rv__v_kcrsa16(a, b) \
  (__builtin_riscv_v_kcrsa16 ((a), (b)))
#define __rv__v_ukcrsa16(a, b) \
  (__builtin_riscv_v_ukcrsa16 ((a), (b)))
#define __rv__v_ustas16(a, b) \
  (__builtin_riscv_v_ustas16 ((a), (b)))
#define __rv__v_sstas16(a, b) \
  (__builtin_riscv_v_sstas16 ((a), (b)))
#define __rv__v_rstas16(a, b) \
  (__builtin_riscv_v_rstas16 ((a), (b)))
#define __rv__v_urstas16(a, b) \
  (__builtin_riscv_v_urstas16 ((a), (b)))
#define __rv__v_kstas16(a, b) \
  (__builtin_riscv_v_kstas16 ((a), (b)))
#define __rv__v_ukstas16(a, b) \
  (__builtin_riscv_v_ukstas16 ((a), (b)))
#define __rv__v_ustsa16(a, b) \
  (__builtin_riscv_v_ustsa16 ((a), (b)))
#define __rv__v_sstsa16(a, b) \
  (__builtin_riscv_v_sstsa16 ((a), (b)))
#define __rv__v_rstsa16(a, b) \
  (__builtin_riscv_v_rstsa16 ((a), (b)))
#define __rv__v_urstsa16(a, b) \
  (__builtin_riscv_v_urstsa16 ((a), (b)))
#define __rv__v_kstsa16(a, b) \
  (__builtin_riscv_v_kstsa16 ((a), (b)))
#define __rv__v_ukstsa16(a, b) \
  (__builtin_riscv_v_ukstsa16 ((a), (b)))
#define __rv__v_uadd8(a, b) \
  (__builtin_riscv_v_uadd8 ((a), (b)))
#define __rv__v_sadd8(a, b) \
  (__builtin_riscv_v_sadd8 ((a), (b)))
#define __rv__v_radd8(a, b) \
  (__builtin_riscv_v_radd8 ((a), (b)))
#define __rv__v_uradd8(a, b) \
  (__builtin_riscv_v_uradd8 ((a), (b)))
#define __rv__v_kadd8(a, b) \
  (__builtin_riscv_v_kadd8 ((a), (b)))
#define __rv__v_ukadd8(a, b) \
  (__builtin_riscv_v_ukadd8 ((a), (b)))
#define __rv__v_usub8(a, b) \
  (__builtin_riscv_v_usub8 ((a), (b)))
#define __rv__v_ssub8(a, b) \
  (__builtin_riscv_v_ssub8 ((a), (b)))
#define __rv__v_rsub8(a, b) \
  (__builtin_riscv_v_rsub8 ((a), (b)))
#define __rv__v_ursub8(a, b) \
  (__builtin_riscv_v_ursub8 ((a), (b)))
#define __rv__v_ksub8(a, b) \
  (__builtin_riscv_v_ksub8 ((a), (b)))
#define __rv__v_uksub8(a, b) \
  (__builtin_riscv_v_uksub8 ((a), (b)))
#define __rv__v_sra16(a, b) \
  (__builtin_riscv_v_sra16 ((a), (b)))
#define __rv__v_sra16_u(a, b) \
  (__builtin_riscv_v_sra16_u ((a), (b)))
#define __rv__v_srl16(a, b) \
  (__builtin_riscv_v_srl16 ((a), (b)))
#define __rv__v_srl16_u(a, b) \
  (__builtin_riscv_v_srl16_u ((a), (b)))
#define __rv__v_sll16(a, b) \
  (__builtin_riscv_v_sll16 ((a), (b)))
#define __rv__v_ksll16(a, b) \
  (__builtin_riscv_v_ksll16 ((a), (b)))
#define __rv__v_kslra16(a, b) \
  (__builtin_riscv_v_kslra16 ((a), (b)))
#define __rv__v_kslra16_u(a, b) \
  (__builtin_riscv_v_kslra16_u ((a), (b)))
#define __rv__v_scmpeq16(a, b) \
  (__builtin_riscv_v_scmpeq16 ((a), (b)))
#define __rv__v_ucmpeq16(a, b) \
  (__builtin_riscv_v_ucmpeq16 ((a), (b)))
#define __rv__v_scmplt16(a, b) \
  (__builtin_riscv_v_scmplt16 ((a), (b)))
#define __rv__v_scmple16(a, b) \
  (__builtin_riscv_v_scmple16 ((a), (b)))
#define __rv__v_ucmplt16(a, b) \
  (__builtin_riscv_v_ucmplt16 ((a), (b)))
#define __rv__v_ucmple16(a, b) \
  (__builtin_riscv_v_ucmple16 ((a), (b)))
#define __rv__v_scmpeq8(a, b) \
  (__builtin_riscv_v_scmpeq8 ((a), (b)))
#define __rv__v_ucmpeq8(a, b) \
  (__builtin_riscv_v_ucmpeq8 ((a), (b)))
#define __rv__v_scmplt8(a, b) \
  (__builtin_riscv_v_scmplt8 ((a), (b)))
#define __rv__v_scmple8(a, b) \
  (__builtin_riscv_v_scmple8 ((a), (b)))
#define __rv__v_ucmplt8(a, b) \
  (__builtin_riscv_v_ucmplt8 ((a), (b)))
#define __rv__v_ucmple8(a, b) \
  (__builtin_riscv_v_ucmple8 ((a), (b)))
#define __rv__v_smin16(a, b) \
  (__builtin_riscv_v_smin16 ((a), (b)))
#define __rv__v_umin16(a, b) \
  (__builtin_riscv_v_umin16 ((a), (b)))
#define __rv__v_smax16(a, b) \
  (__builtin_riscv_v_smax16 ((a), (b)))
#define __rv__v_umax16(a, b) \
  (__builtin_riscv_v_umax16 ((a), (b)))
#define __rv__v_sclip16(a, b) \
  (__builtin_riscv_v_sclip16 ((a), (b)))
#define __rv__v_uclip16(a, b) \
  (__builtin_riscv_v_uclip16 ((a), (b)))
#define __rv__v_khm16(a, b) \
  (__builtin_riscv_v_khm16 ((a), (b)))
#define __rv__v_khmx16(a, b) \
  (__builtin_riscv_v_khmx16 ((a), (b)))
#define __rv__v_khm8(a, b) \
  (__builtin_riscv_v_khm8 ((a), (b)))
#define __rv__v_khmx8(a, b) \
  (__builtin_riscv_v_khmx8 ((a), (b)))
#define __rv__v_kabs16(a) \
  (__builtin_riscv_v_kabs16 ((a)))
#define __rv__v_smin8(a, b) \
  (__builtin_riscv_v_smin8 ((a), (b)))
#define __rv__v_umin8(a, b) \
  (__builtin_riscv_v_umin8 ((a), (b)))
#define __rv__v_smax8(a, b) \
  (__builtin_riscv_v_smax8 ((a), (b)))
#define __rv__v_umax8(a, b) \
  (__builtin_riscv_v_umax8 ((a), (b)))
#define __rv__v_kabs8(a) \
  (__builtin_riscv_v_kabs8 ((a)))
#define __rv__v_sunpkd810(a) \
  (__builtin_riscv_v_sunpkd810 ((a)))
#define __rv__v_sunpkd820(a) \
  (__builtin_riscv_v_sunpkd820 ((a)))
#define __rv__v_sunpkd830(a) \
  (__builtin_riscv_v_sunpkd830 ((a)))
#define __rv__v_sunpkd831(a) \
  (__builtin_riscv_v_sunpkd831 ((a)))
#define __rv__v_sunpkd832(a) \
  (__builtin_riscv_v_sunpkd832 ((a)))
#define __rv__v_zunpkd810(a) \
  (__builtin_riscv_v_zunpkd810 ((a)))
#define __rv__v_zunpkd820(a) \
  (__builtin_riscv_v_zunpkd820 ((a)))
#define __rv__v_zunpkd830(a) \
  (__builtin_riscv_v_zunpkd830 ((a)))
#define __rv__v_zunpkd831(a) \
  (__builtin_riscv_v_zunpkd831 ((a)))
#define __rv__v_zunpkd832(a) \
  (__builtin_riscv_v_zunpkd832 ((a)))
#define __rv__v_pkbb16(a, b) \
  (__builtin_riscv_v_pkbb16 ((a), (b)))
#define __rv__v_pkbt16(a, b) \
  (__builtin_riscv_v_pkbt16 ((a), (b)))
#define __rv__v_pktb16(a, b) \
  (__builtin_riscv_v_pktb16 ((a), (b)))
#define __rv__v_pktt16(a, b) \
  (__builtin_riscv_v_pktt16 ((a), (b)))
#define __rv__v_smmwb(a, b) \
  (__builtin_riscv_v_smmwb ((a), (b)))
#define __rv__v_smmwb_u(a, b) \
  (__builtin_riscv_v_smmwb_u ((a), (b)))
#define __rv__v_smmwt(a, b) \
  (__builtin_riscv_v_smmwt ((a), (b)))
#define __rv__v_smmwt_u(a, b) \
  (__builtin_riscv_v_smmwt_u ((a), (b)))
#define __rv__v_kmmwb2(a, b) \
  (__builtin_riscv_v_kmmwb2 ((a), (b)))
#define __rv__v_kmmwb2_u(a, b) \
  (__builtin_riscv_v_kmmwb2_u ((a), (b)))
#define __rv__v_kmmwt2(a, b) \
  (__builtin_riscv_v_kmmwt2 ((a), (b)))
#define __rv__v_kmmwt2_u(a, b) \
  (__builtin_riscv_v_kmmwt2_u ((a), (b)))
#define __rv__v_kmmawb(r, a, b) \
  (__builtin_riscv_v_kmmawb ((r), (a), (b)))
#define __rv__v_kmmawb_u(r, a, b) \
  (__builtin_riscv_v_kmmawb_u ((r), (a), (b)))
#define __rv__v_kmmawt(r, a, b) \
  (__builtin_riscv_v_kmmawt ((r), (a), (b)))
#define __rv__v_kmmawt_u(r, a, b) \
  (__builtin_riscv_v_kmmawt_u ((r), (a), (b)))
#define __rv__v_kmmawb2(r, a, b) \
  (__builtin_riscv_v_kmmawb2 ((r), (a), (b)))
#define __rv__v_kmmawb2_u(r, a, b) \
  (__builtin_riscv_v_kmmawb2_u ((r), (a), (b)))
#define __rv__v_kmmawt2(r, a, b) \
  (__builtin_riscv_v_kmmawt2 ((r), (a), (b)))
#define __rv__v_kmmawt2_u(r, a, b) \
  (__builtin_riscv_v_kmmawt2_u ((r), (a), (b)))
#define __rv__v_smbb16(a, b) \
  (__builtin_riscv_v_smbb16 ((a), (b)))
#define __rv__v_smbt16(a, b) \
  (__builtin_riscv_v_smbt16 ((a), (b)))
#define __rv__v_smtt16(a, b) \
  (__builtin_riscv_v_smtt16 ((a), (b)))
#define __rv__v_kmda(a, b) \
  (__builtin_riscv_v_kmda ((a), (b)))
#define __rv__v_kmxda(a, b) \
  (__builtin_riscv_v_kmxda ((a), (b)))
#define __rv__v_smds(a, b) \
  (__builtin_riscv_v_smds ((a), (b)))
#define __rv__v_smdrs(a, b) \
  (__builtin_riscv_v_smdrs ((a), (b)))
#define __rv__v_smxds(a, b) \
  (__builtin_riscv_v_smxds ((a), (b)))
#define __rv__v_kmabb(r, a, b) \
  (__builtin_riscv_v_kmabb ((r), (a), (b)))
#define __rv__v_kmabt(r, a, b) \
  (__builtin_riscv_v_kmabt ((r), (a), (b)))
#define __rv__v_kmatt(r, a, b) \
  (__builtin_riscv_v_kmatt ((r), (a), (b)))
#define __rv__v_kmada(r, a, b) \
  (__builtin_riscv_v_kmada ((r), (a), (b)))
#define __rv__v_kmaxda(r, a, b) \
  (__builtin_riscv_v_kmaxda ((r), (a), (b)))
#define __rv__v_kmads(r, a, b) \
  (__builtin_riscv_v_kmads ((r), (a), (b)))
#define __rv__v_kmadrs(r, a, b) \
  (__builtin_riscv_v_kmadrs ((r), (a), (b)))
#define __rv__v_kmaxds(r, a, b) \
  (__builtin_riscv_v_kmaxds ((r), (a), (b)))
#define __rv__v_kmsda(r, a, b) \
  (__builtin_riscv_v_kmsda ((r), (a), (b)))
#define __rv__v_kmsxda(r, a, b) \
  (__builtin_riscv_v_kmsxda ((r), (a), (b)))
#define __rv__v_sra8(a, b) \
  (__builtin_riscv_v_sra8 ((a), (b)))
#define __rv__v_sra8_u(a, b) \
  (__builtin_riscv_v_sra8_u ((a), (b)))
#define __rv__v_srl8(a, b) \
  (__builtin_riscv_v_srl8 ((a), (b)))
#define __rv__v_srl8_u(a, b) \
  (__builtin_riscv_v_srl8_u ((a), (b)))
#define __rv__v_sll8(a, b) \
  (__builtin_riscv_v_sll8 ((a), (b)))
#define __rv__v_ksll8(a, b) \
  (__builtin_riscv_v_ksll8 ((a), (b)))
#define __rv__v_kslra8(a, b) \
  (__builtin_riscv_v_kslra8 ((a), (b)))
#define __rv__v_kslra8_u(a, b) \
  (__builtin_riscv_v_kslra8_u ((a), (b)))
#define __rv__v_swap8(a) \
  (__builtin_riscv_v_swap8 ((a)))
#define __rv__v_swap16(a) \
  (__builtin_riscv_v_pkbt16 ((a), (a)))
#define __rv__v_sclip8(a, b) \
  (__builtin_riscv_v_sclip8 ((a), (b)))
#define __rv__v_uclip8(a, b) \
  (__builtin_riscv_v_uclip8 ((a), (b)))
#define __rv__v_smaqa(r, a, b) \
  (__builtin_riscv_v_smaqa ((r), (a), (b)))
#define __rv__v_umaqa(r, a, b) \
  (__builtin_riscv_v_umaqa ((r), (a), (b)))
#define __rv__v_smaqa_su(r, a, b) \
  (__builtin_riscv_v_smaqa_su ((r), (a), (b)))
#define __rv__v_clrs8(a) \
  (__builtin_riscv_v_clrs8 ((a)))
#define __rv__v_clrs16(a) \
  (__builtin_riscv_v_clrs16 ((a)))
#define __rv__v_clo8(a) \
  (__builtin_riscv_v_clo8 ((a)))
#define __rv__v_clo16(a) \
  (__builtin_riscv_v_clo16 ((a)))
#define __rv__v_clz8(a) \
  (__builtin_riscv_v_clz8 ((a)))
#define __rv__v_clz16(a) \
  (__builtin_riscv_v_clz16 ((a)))
#define __rv__v_khmbb(a, b) \
  (__builtin_riscv_v_khmbb ((a), (b)))
#define __rv__v_khmbt(a, b) \
  (__builtin_riscv_v_khmbt ((a), (b)))
#define __rv__v_khmtt(a, b) \
  (__builtin_riscv_v_khmtt ((a), (b)))
#define __rv__v_pbsad(a, b) \
  (__builtin_riscv_v_pbsad ((a), (b)))
#define __rv__v_pbsada(acc, a, b) \
  (__builtin_riscv_v_pbsada ((acc), (a), (b)))
#define __rv__v_kdmbb(a, b) \
  (__builtin_riscv_v_kdmbb ((a), (b)))
#define __rv__v_kdmbt(a, b) \
  (__builtin_riscv_v_kdmbt ((a), (b)))
#define __rv__v_kdmtt(a, b) \
  (__builtin_riscv_v_kdmtt ((a), (b)))
#else
#define __rv__v_uadd16(a, b) \
  (__builtin_riscv_v64_uadd16 ((a), (b)))
#define __rv__v_sadd16(a, b) \
  (__builtin_riscv_v64_sadd16 ((a), (b)))
#define __rv__v_radd16(a, b) \
  (__builtin_riscv_v64_radd16 ((a), (b)))
#define __rv__v_uradd16(a, b) \
  (__builtin_riscv_v64_uradd16 ((a), (b)))
#define __rv__v_kadd16(a, b) \
  (__builtin_riscv_v64_kadd16 ((a), (b)))
#define __rv__v_ukadd16(a, b) \
  (__builtin_riscv_v64_ukadd16 ((a), (b)))
#define __rv__v_usub16(a, b) \
  (__builtin_riscv_v64_usub16 ((a), (b)))
#define __rv__v_ssub16(a, b) \
  (__builtin_riscv_v64_ssub16 ((a), (b)))
#define __rv__v_rsub16(a, b) \
  (__builtin_riscv_v64_rsub16 ((a), (b)))
#define __rv__v_ursub16(a, b) \
  (__builtin_riscv_v64_ursub16 ((a), (b)))
#define __rv__v_ksub16(a, b) \
  (__builtin_riscv_v64_ksub16 ((a), (b)))
#define __rv__v_uksub16(a, b) \
  (__builtin_riscv_v64_uksub16 ((a), (b)))
#define __rv__v_ucras16(a, b) \
  (__builtin_riscv_v64_ucras16 ((a), (b)))
#define __rv__v_scras16(a, b) \
  (__builtin_riscv_v64_scras16 ((a), (b)))
#define __rv__v_rcras16(a, b) \
  (__builtin_riscv_v64_rcras16 ((a), (b)))
#define __rv__v_urcras16(a, b) \
  (__builtin_riscv_v64_urcras16 ((a), (b)))
#define __rv__v_kcras16(a, b) \
  (__builtin_riscv_v64_kcras16 ((a), (b)))
#define __rv__v_ukcras16(a, b) \
  (__builtin_riscv_v64_ukcras16 ((a), (b)))
#define __rv__v_ucrsa16(a, b) \
  (__builtin_riscv_v64_ucrsa16 ((a), (b)))
#define __rv__v_scrsa16(a, b) \
  (__builtin_riscv_v64_scrsa16 ((a), (b)))
#define __rv__v_rcrsa16(a, b) \
  (__builtin_riscv_v64_rcrsa16 ((a), (b)))
#define __rv__v_urcrsa16(a, b) \
  (__builtin_riscv_v64_urcrsa16 ((a), (b)))
#define __rv__v_kcrsa16(a, b) \
  (__builtin_riscv_v64_kcrsa16 ((a), (b)))
#define __rv__v_ukcrsa16(a, b) \
  (__builtin_riscv_v64_ukcrsa16 ((a), (b)))
#define __rv__v_ustas16(a, b) \
  (__builtin_riscv_v64_ustas16 ((a), (b)))
#define __rv__v_sstas16(a, b) \
  (__builtin_riscv_v64_sstas16 ((a), (b)))
#define __rv__v_rstas16(a, b) \
  (__builtin_riscv_v64_rstas16 ((a), (b)))
#define __rv__v_urstas16(a, b) \
  (__builtin_riscv_v64_urstas16 ((a), (b)))
#define __rv__v_kstas16(a, b) \
  (__builtin_riscv_v64_kstas16 ((a), (b)))
#define __rv__v_ukstas16(a, b) \
  (__builtin_riscv_v64_ukstas16 ((a), (b)))
#define __rv__v_ustsa16(a, b) \
  (__builtin_riscv_v64_ustsa16 ((a), (b)))
#define __rv__v_sstsa16(a, b) \
  (__builtin_riscv_v64_sstsa16 ((a), (b)))
#define __rv__v_rstsa16(a, b) \
  (__builtin_riscv_v64_rstsa16 ((a), (b)))
#define __rv__v_urstsa16(a, b) \
  (__builtin_riscv_v64_urstsa16 ((a), (b)))
#define __rv__v_kstsa16(a, b) \
  (__builtin_riscv_v64_kstsa16 ((a), (b)))
#define __rv__v_ukstsa16(a, b) \
  (__builtin_riscv_v64_ukstsa16 ((a), (b)))
#define __rv__v_uadd8(a, b) \
  (__builtin_riscv_v64_uadd8 ((a), (b)))
#define __rv__v_sadd8(a, b) \
  (__builtin_riscv_v64_sadd8 ((a), (b)))
#define __rv__v_radd8(a, b) \
  (__builtin_riscv_v64_radd8 ((a), (b)))
#define __rv__v_uradd8(a, b) \
  (__builtin_riscv_v64_uradd8 ((a), (b)))
#define __rv__v_kadd8(a, b) \
  (__builtin_riscv_v64_kadd8 ((a), (b)))
#define __rv__v_ukadd8(a, b) \
  (__builtin_riscv_v64_ukadd8 ((a), (b)))
#define __rv__v_usub8(a, b) \
  (__builtin_riscv_v64_usub8 ((a), (b)))
#define __rv__v_ssub8(a, b) \
  (__builtin_riscv_v64_ssub8 ((a), (b)))
#define __rv__v_rsub8(a, b) \
  (__builtin_riscv_v64_rsub8 ((a), (b)))
#define __rv__v_ursub8(a, b) \
  (__builtin_riscv_v64_ursub8 ((a), (b)))
#define __rv__v_ksub8(a, b) \
  (__builtin_riscv_v64_ksub8 ((a), (b)))
#define __rv__v_uksub8(a, b) \
  (__builtin_riscv_v64_uksub8 ((a), (b)))
#define __rv__v_sra16(a, b) \
  (__builtin_riscv_v64_sra16 ((a), (b)))
#define __rv__v_sra16_u(a, b) \
  (__builtin_riscv_v64_sra16_u ((a), (b)))
#define __rv__v_srl16(a, b) \
  (__builtin_riscv_v64_srl16 ((a), (b)))
#define __rv__v_srl16_u(a, b) \
  (__builtin_riscv_v64_srl16_u ((a), (b)))
#define __rv__v_sll16(a, b) \
  (__builtin_riscv_v64_sll16 ((a), (b)))
#define __rv__v_ksll16(a, b) \
  (__builtin_riscv_v64_ksll16 ((a), (b)))
#define __rv__v_kslra16(a, b) \
  (__builtin_riscv_v64_kslra16 ((a), (b)))
#define __rv__v_kslra16_u(a, b) \
  (__builtin_riscv_v64_kslra16_u ((a), (b)))
#define __rv__v_scmpeq16(a, b) \
  (__builtin_riscv_v64_scmpeq16 ((a), (b)))
#define __rv__v_ucmpeq16(a, b) \
  (__builtin_riscv_v64_ucmpeq16 ((a), (b)))
#define __rv__v_scmplt16(a, b) \
  (__builtin_riscv_v64_scmplt16 ((a), (b)))
#define __rv__v_scmple16(a, b) \
  (__builtin_riscv_v64_scmple16 ((a), (b)))
#define __rv__v_ucmplt16(a, b) \
  (__builtin_riscv_v64_ucmplt16 ((a), (b)))
#define __rv__v_ucmple16(a, b) \
  (__builtin_riscv_v64_ucmple16 ((a), (b)))
#define __rv__v_scmpeq8(a, b) \
  (__builtin_riscv_v64_scmpeq8 ((a), (b)))
#define __rv__v_ucmpeq8(a, b) \
  (__builtin_riscv_v64_ucmpeq8 ((a), (b)))
#define __rv__v_scmplt8(a, b) \
  (__builtin_riscv_v64_scmplt8 ((a), (b)))
#define __rv__v_scmple8(a, b) \
  (__builtin_riscv_v64_scmple8 ((a), (b)))
#define __rv__v_ucmplt8(a, b) \
  (__builtin_riscv_v64_ucmplt8 ((a), (b)))
#define __rv__v_ucmple8(a, b) \
  (__builtin_riscv_v64_ucmple8 ((a), (b)))
#define __rv__v_smin16(a, b) \
  (__builtin_riscv_v64_smin16 ((a), (b)))
#define __rv__v_umin16(a, b) \
  (__builtin_riscv_v64_umin16 ((a), (b)))
#define __rv__v_smax16(a, b) \
  (__builtin_riscv_v64_smax16 ((a), (b)))
#define __rv__v_umax16(a, b) \
  (__builtin_riscv_v64_umax16 ((a), (b)))
#define __rv__v_sclip16(a, b) \
  (__builtin_riscv_v64_sclip16 ((a), (b)))
#define __rv__v_uclip16(a, b) \
  (__builtin_riscv_v64_uclip16 ((a), (b)))
#define __rv__v_khm16(a, b) \
  (__builtin_riscv_v64_khm16 ((a), (b)))
#define __rv__v_khmx16(a, b) \
  (__builtin_riscv_v64_khmx16 ((a), (b)))
#define __rv__v_khm8(a, b) \
  (__builtin_riscv_v64_khm8 ((a), (b)))
#define __rv__v_khmx8(a, b) \
  (__builtin_riscv_v64_khmx8 ((a), (b)))
#define __rv__v_kabs16(a) \
  (__builtin_riscv_v64_kabs16 ((a)))
#define __rv__v_smin8(a, b) \
  (__builtin_riscv_v64_smin8 ((a), (b)))
#define __rv__v_umin8(a, b) \
  (__builtin_riscv_v64_umin8 ((a), (b)))
#define __rv__v_smax8(a, b) \
  (__builtin_riscv_v64_smax8 ((a), (b)))
#define __rv__v_umax8(a, b) \
  (__builtin_riscv_v64_umax8 ((a), (b)))
#define __rv__v_kabs8(a) \
  (__builtin_riscv_v64_kabs8 ((a)))
#define __rv__v_sunpkd810(a) \
  (__builtin_riscv_v64_sunpkd810 ((a)))
#define __rv__v_sunpkd820(a) \
  (__builtin_riscv_v64_sunpkd820 ((a)))
#define __rv__v_sunpkd830(a) \
  (__builtin_riscv_v64_sunpkd830 ((a)))
#define __rv__v_sunpkd831(a) \
  (__builtin_riscv_v64_sunpkd831 ((a)))
#define __rv__v_sunpkd832(a) \
  (__builtin_riscv_v64_sunpkd832 ((a)))
#define __rv__v_zunpkd810(a) \
  (__builtin_riscv_v64_zunpkd810 ((a)))
#define __rv__v_zunpkd820(a) \
  (__builtin_riscv_v64_zunpkd820 ((a)))
#define __rv__v_zunpkd830(a) \
  (__builtin_riscv_v64_zunpkd830 ((a)))
#define __rv__v_zunpkd831(a) \
  (__builtin_riscv_v64_zunpkd831 ((a)))
#define __rv__v_zunpkd832(a) \
  (__builtin_riscv_v64_zunpkd832 ((a)))
#define __rv__v_pkbb16(a, b) \
  (__builtin_riscv_v64_pkbb16 ((a), (b)))
#define __rv__v_pkbt16(a, b) \
  (__builtin_riscv_v64_pkbt16 ((a), (b)))
#define __rv__v_pktb16(a, b) \
  (__builtin_riscv_v64_pktb16 ((a), (b)))
#define __rv__v_pktt16(a, b) \
  (__builtin_riscv_v64_pktt16 ((a), (b)))
#define __rv__v_smmwb(a, b) \
  (__builtin_riscv_v64_smmwb ((a), (b)))
#define __rv__v_smmwb_u(a, b) \
  (__builtin_riscv_v64_smmwb_u ((a), (b)))
#define __rv__v_smmwt(a, b) \
  (__builtin_riscv_v64_smmwt ((a), (b)))
#define __rv__v_smmwt_u(a, b) \
  (__builtin_riscv_v64_smmwt_u ((a), (b)))
#define __rv__v_kmmwb2(a, b) \
  (__builtin_riscv_v64_kmmwb2 ((a), (b)))
#define __rv__v_kmmwb2_u(a, b) \
  (__builtin_riscv_v64_kmmwb2_u ((a), (b)))
#define __rv__v_kmmwt2(a, b) \
  (__builtin_riscv_v64_kmmwt2 ((a), (b)))
#define __rv__v_kmmwt2_u(a, b) \
  (__builtin_riscv_v64_kmmwt2_u ((a), (b)))
#define __rv__v_kmmawb(r, a, b) \
  (__builtin_riscv_v64_kmmawb ((r), (a), (b)))
#define __rv__v_kmmawb_u(r, a, b) \
  (__builtin_riscv_v64_kmmawb_u ((r), (a), (b)))
#define __rv__v_kmmawt(r, a, b) \
  (__builtin_riscv_v64_kmmawt ((r), (a), (b)))
#define __rv__v_kmmawt_u(r, a, b) \
  (__builtin_riscv_v64_kmmawt_u ((r), (a), (b)))
#define __rv__v_kmmawb2(r, a, b) \
  (__builtin_riscv_v64_kmmawb2 ((r), (a), (b)))
#define __rv__v_kmmawb2_u(r, a, b) \
  (__builtin_riscv_v64_kmmawb2_u ((r), (a), (b)))
#define __rv__v_kmmawt2(r, a, b) \
  (__builtin_riscv_v64_kmmawt2 ((r), (a), (b)))
#define __rv__v_kmmawt2_u(r, a, b) \
  (__builtin_riscv_v64_kmmawt2_u ((r), (a), (b)))
#define __rv__v_smbb16(a, b) \
  (__builtin_riscv_v64_smbb16 ((a), (b)))
#define __rv__v_smbt16(a, b) \
  (__builtin_riscv_v64_smbt16 ((a), (b)))
#define __rv__v_smtt16(a, b) \
  (__builtin_riscv_v64_smtt16 ((a), (b)))
#define __rv__v_kmda(a, b) \
  (__builtin_riscv_v64_kmda ((a), (b)))
#define __rv__v_kmxda(a, b) \
  (__builtin_riscv_v64_kmxda ((a), (b)))
#define __rv__v_smds(a, b) \
  (__builtin_riscv_v64_smds ((a), (b)))
#define __rv__v_smdrs(a, b) \
  (__builtin_riscv_v64_smdrs ((a), (b)))
#define __rv__v_smxds(a, b) \
  (__builtin_riscv_v64_smxds ((a), (b)))
#define __rv__v_kmabb(r, a, b) \
  (__builtin_riscv_v64_kmabb ((r), (a), (b)))
#define __rv__v_kmabt(r, a, b) \
  (__builtin_riscv_v64_kmabt ((r), (a), (b)))
#define __rv__v_kmatt(r, a, b) \
  (__builtin_riscv_v64_kmatt ((r), (a), (b)))
#define __rv__v_kmada(r, a, b) \
  (__builtin_riscv_v64_kmada ((r), (a), (b)))
#define __rv__v_kmaxda(r, a, b) \
  (__builtin_riscv_v64_kmaxda ((r), (a), (b)))
#define __rv__v_kmads(r, a, b) \
  (__builtin_riscv_v64_kmads ((r), (a), (b)))
#define __rv__v_kmadrs(r, a, b) \
  (__builtin_riscv_v64_kmadrs ((r), (a), (b)))
#define __rv__v_kmaxds(r, a, b) \
  (__builtin_riscv_v64_kmaxds ((r), (a), (b)))
#define __rv__v_kmsda(r, a, b) \
  (__builtin_riscv_v64_kmsda ((r), (a), (b)))
#define __rv__v_kmsxda(r, a, b) \
  (__builtin_riscv_v64_kmsxda ((r), (a), (b)))
#define __rv__v_sra8(a, b) \
  (__builtin_riscv_v64_sra8 ((a), (b)))
#define __rv__v_sra8_u(a, b) \
  (__builtin_riscv_v64_sra8_u ((a), (b)))
#define __rv__v_srl8(a, b) \
  (__builtin_riscv_v64_srl8 ((a), (b)))
#define __rv__v_srl8_u(a, b) \
  (__builtin_riscv_v64_srl8_u ((a), (b)))
#define __rv__v_sll8(a, b) \
  (__builtin_riscv_v64_sll8 ((a), (b)))
#define __rv__v_ksll8(a, b) \
  (__builtin_riscv_v64_ksll8 ((a), (b)))
#define __rv__v_kslra8(a, b) \
  (__builtin_riscv_v64_kslra8 ((a), (b)))
#define __rv__v_kslra8_u(a, b) \
  (__builtin_riscv_v64_kslra8_u ((a), (b)))
#define __rv__v_sclip8(a, b) \
  (__builtin_riscv_v64_sclip8 ((a), (b)))
#define __rv__v_uclip8(a, b) \
  (__builtin_riscv_v64_uclip8 ((a), (b)))
#define __rv__v_kdmabb(r, a, b) \
  (__builtin_riscv_v64_kdmabb ((r), (a), (b)))
#define __rv__v_kdmabt(r, a, b) \
  (__builtin_riscv_v64_kdmabt ((r), (a), (b)))
#define __rv__v_smaqa(r, a, b) \
  (__builtin_riscv_v64_smaqa ((r), (a), (b)))
#define __rv__v_umaqa(r, a, b) \
  (__builtin_riscv_v64_umaqa ((r), (a), (b)))
#define __rv__v_smaqa_su(r, a, b) \
  (__builtin_riscv_v64_smaqa_su ((r), (a), (b)))
#define __rv__v_clrs8(a) \
  (__builtin_riscv_v64_clrs8 ((a)))
#define __rv__v_clrs16(a) \
  (__builtin_riscv_v64_clrs16 ((a)))
#define __rv__v_clrs32(a) \
  (__builtin_riscv_v64_clrs32 ((a)))
#define __rv__v_clo8(a) \
  (__builtin_riscv_v64_clo8 ((a)))
#define __rv__v_clo16(a) \
  (__builtin_riscv_v64_clo16 ((a)))
#define __rv__v_clo32(a) \
  (__builtin_riscv_v64_clo32 ((a)))
#define __rv__v_clz8(a) \
  (__builtin_riscv_v64_clz8 ((a)))
#define __rv__v_clz16(a) \
  (__builtin_riscv_v64_clz16 ((a)))
#define __rv__v_clz32(a) \
  (__builtin_riscv_v64_clz32 ((a)))
#define __rv__v_swap8(a) \
  (__builtin_riscv_v64_swap8 ((a)))
#define __rv__v_swap16(a) \
  (__builtin_riscv_v64_pkbt16 ((a), (a)))
#define __rv__v_kdmbb(a, b) \
  (__builtin_riscv_v64_kdmbb ((a), (b)))
#define __rv__v_kdmbt(a, b) \
  (__builtin_riscv_v64_kdmbt ((a), (b)))
#define __rv__v_kdmtt(a, b) \
  (__builtin_riscv_v64_kdmtt ((a), (b)))
#define __rv__v_khmbb(a, b) \
  (__builtin_riscv_v64_khmbb ((a), (b)))
#define __rv__v_khmbt(a, b) \
  (__builtin_riscv_v64_khmbt ((a), (b)))
#define __rv__v_khmtt(a, b) \
  (__builtin_riscv_v64_khmtt ((a), (b)))
#define __rv__v_smmul(a, b) \
  (__builtin_riscv_v64_smmul ((a), (b)))
#define __rv__v_smmul_u(a, b) \
  (__builtin_riscv_v64_smmul_u ((a), (b)))
#define __rv__v_kwmmul(a, b) \
  (__builtin_riscv_v64_kwmmul ((a), (b)))
#define __rv__v_kwmmul_u(a, b) \
  (__builtin_riscv_v64_kwmmul_u ((a), (b)))
#define __rv__v_kmmac(r, a, b) \
  (__builtin_riscv_v64_kmmac ((r), (a), (b)))
#define __rv__v_kmmac_u(r, a, b) \
  (__builtin_riscv_v64_kmmac_u ((r), (a), (b)))
#define __rv__v_kmmsb(r, a, b) \
  (__builtin_riscv_v64_kmmsb ((r), (a), (b)))
#define __rv__v_kmmsb_u(r, a, b) \
  (__builtin_riscv_v64_kmmsb_u ((r), (a), (b)))
#define __rv__v_uclip32(a, imm) \
  (__builtin_riscv_v64_uclip32 ((a), (imm)))
#define __rv__v_sclip32(a, imm) \
  (__builtin_riscv_v64_sclip32 ((a), (imm)))
#define __rv__v_pbsad(a, b) \
  (__builtin_riscv_v64_pbsad ((a), (b)))
#define __rv__v_pbsada(acc, a, b) \
  (__builtin_riscv_v64_pbsada ((acc), (a), (b)))
#endif

// ZPRV subext intrinsics
#if defined(__riscv_zprv)
#define __rv__add32(a, b) \
  (__builtin_riscv_add32 ((a), (b)))
#define __rv__radd32(a, b) \
  (__builtin_riscv_radd32 ((a), (b)))
#define __rv__uradd32(a, b) \
  (__builtin_riscv_uradd32 ((a), (b)))
#define __rv__kadd32(a, b) \
  (__builtin_riscv_kadd32 ((a), (b)))
#define __rv__ukadd32(a, b) \
  (__builtin_riscv_ukadd32 ((a), (b)))
#define __rv__sub32(a, b) \
  (__builtin_riscv_sub32 ((a), (b)))
#define __rv__rsub32(a, b) \
  (__builtin_riscv_rsub32 ((a), (b)))
#define __rv__ursub32(a, b) \
  (__builtin_riscv_ursub32 ((a), (b)))
#define __rv__ksub32(a, b) \
  (__builtin_riscv_ksub32 ((a), (b)))
#define __rv__uksub32(a, b) \
  (__builtin_riscv_uksub32 ((a), (b)))
#define __rv__cras32(a, b) \
  (__builtin_riscv_cras32 ((a), (b)))
#define __rv__crsa32(a, b) \
  (__builtin_riscv_crsa32 ((a), (b)))
#define __rv__rcras32(a, b) \
  (__builtin_riscv_rcras32 ((a), (b)))
#define __rv__rcrsa32(a, b) \
  (__builtin_riscv_rcrsa32 ((a), (b)))
#define __rv__urcras32(a, b) \
  (__builtin_riscv_urcras32 ((a), (b)))
#define __rv__urcrsa32(a, b) \
  (__builtin_riscv_urcrsa32 ((a), (b)))
#define __rv__kcras32(a, b) \
  (__builtin_riscv_kcras32 ((a), (b)))
#define __rv__kcrsa32(a, b) \
  (__builtin_riscv_kcrsa32 ((a), (b)))
#define __rv__ukcras32(a, b) \
  (__builtin_riscv_ukcras32 ((a), (b)))
#define __rv__ukcrsa32(a, b) \
  (__builtin_riscv_ukcrsa32 ((a), (b)))
#define __rv__stas32(a, b) \
  (__builtin_riscv_stas32 ((a), (b)))
#define __rv__stsa32(a, b) \
  (__builtin_riscv_stsa32 ((a), (b)))
#define __rv__rstas32(a, b) \
  (__builtin_riscv_rstas32 ((a), (b)))
#define __rv__rstsa32(a, b) \
  (__builtin_riscv_rstsa32 ((a), (b)))
#define __rv__urstas32(a, b) \
  (__builtin_riscv_urstas32 ((a), (b)))
#define __rv__urstsa32(a, b) \
  (__builtin_riscv_urstsa32 ((a), (b)))
#define __rv__kstas32(a, b) \
  (__builtin_riscv_kstas32 ((a), (b)))
#define __rv__kstsa32(a, b) \
  (__builtin_riscv_kstsa32 ((a), (b)))
#define __rv__ukstas32(a, b) \
  (__builtin_riscv_ukstas32 ((a), (b)))
#define __rv__ukstsa32(a, b) \
  (__builtin_riscv_ukstsa32 ((a), (b)))
#define __rv__sra32(a, b) \
  (__builtin_riscv_sra32 ((a), (b)))
#define __rv__sra32_u(a, b) \
  (__builtin_riscv_sra32_u ((a), (b)))
#define __rv__srl32(a, b) \
  (__builtin_riscv_srl32 ((a), (b)))
#define __rv__srl32_u(a, b) \
  (__builtin_riscv_srl32_u ((a), (b)))
#define __rv__sll32(a, b) \
  (__builtin_riscv_sll32 ((a), (b)))
#define __rv__ksll32(a, b) \
  (__builtin_riscv_ksll32 ((a), (b)))
#define __rv__kslra32(a, b) \
  (__builtin_riscv_kslra32 ((a), (b)))
#define __rv__kslra32_u(a, b) \
  (__builtin_riscv_kslra32_u ((a), (b)))
#define __rv__smin32(a, b) \
  (__builtin_riscv_smin32 ((a), (b)))
#define __rv__umin32(a, b) \
  (__builtin_riscv_umin32 ((a), (b)))
#define __rv__smax32(a, b) \
  (__builtin_riscv_smax32 ((a), (b)))
#define __rv__umax32(a, b) \
  (__builtin_riscv_umax32 ((a), (b)))
#define __rv__kabs32(a) \
  (__builtin_riscv_kabs32 ((a)))
#define __rv__khmbb16(a, b) \
  (__builtin_riscv_khmbb16 ((a), (b)))
#define __rv__khmbt16(a, b) \
  (__builtin_riscv_khmbt16 ((a), (b)))
#define __rv__khmtt16(a, b) \
  (__builtin_riscv_khmtt16 ((a), (b)))
#define __rv__kdmbb16(a, b) \
  (__builtin_riscv_kdmbb16 ((a), (b)))
#define __rv__kdmbt16(a, b) \
  (__builtin_riscv_kdmbt16 ((a), (b)))
#define __rv__kdmtt16(a, b) \
  (__builtin_riscv_kdmtt16 ((a), (b)))
#define __rv__smbb32(a, b) \
  (__builtin_riscv_smbb32 ((a), (b)))
#define __rv__smbt32(a, b) \
  (__builtin_riscv_smbt32 ((a), (b)))
#define __rv__smtt32(a, b) \
  (__builtin_riscv_smtt32 ((a), (b)))
#define __rv__kmabb32(r, a, b) \
  (__builtin_riscv_kmabb32 ((r), (a), (b)))
#define __rv__kmabt32(r, a, b) \
  (__builtin_riscv_kmabt32 ((r), (a), (b)))
#define __rv__kmatt32(r, a, b) \
  (__builtin_riscv_kmatt32 ((r), (a), (b)))
#define __rv__kmda32(a, b) \
  (__builtin_riscv_kmda32 ((a), (b)))
#define __rv__kmxda32(a, b) \
  (__builtin_riscv_kmxda32 ((a), (b)))
#define __rv__kmada32(r, a, b) \
  (__builtin_riscv_kmada32 ((r), (a), (b)))
#define __rv__kmaxda32(r, a, b) \
  (__builtin_riscv_kmaxda32 ((r), (a), (b)))
#define __rv__kmads32(r, a, b) \
  (__builtin_riscv_kmads32 ((r), (a), (b)))
#define __rv__kmadrs32(r, a, b) \
  (__builtin_riscv_kmadrs32 ((r), (a), (b)))
#define __rv__kmaxds32(r, a, b) \
  (__builtin_riscv_kmaxds32 ((r), (a), (b)))
#define __rv__kmsda32(r, a, b) \
  (__builtin_riscv_kmsda32 ((r), (a), (b)))
#define __rv__kmsxda32(r, a, b) \
  (__builtin_riscv_kmsxda32 ((r), (a), (b)))
#define __rv__smds32(a, b) \
  (__builtin_riscv_smds32 ((a), (b)))
#define __rv__smdrs32(a, b) \
  (__builtin_riscv_smdrs32 ((a), (b)))
#define __rv__smxds32(a, b) \
  (__builtin_riscv_smxds32 ((a), (b)))
#define __rv__kdmabb16(r, a, b) \
  (__builtin_riscv_kdmabb16 ((r), (a), (b)))
#define __rv__kdmabt16(r, a, b) \
  (__builtin_riscv_kdmabt16 ((r), (a), (b)))
#define __rv__kdmatt16(r, a, b) \
  (__builtin_riscv_kdmatt16 ((r), (a), (b)))
#define __rv__pkbb32(a, b) \
  (__builtin_riscv_pkbb32 ((a), (b)))
#define __rv__pkbt32(a, b) \
  (__builtin_riscv_pkbt32 ((a), (b)))
#define __rv__pktb32(a, b) \
  (__builtin_riscv_pktb32 ((a), (b)))
#define __rv__pktt32(a, b) \
  (__builtin_riscv_pktt32 ((a), (b)))
#define __rv__v_uadd32(a, b) \
  (__builtin_riscv_v64_uadd32 ((a), (b)))
#define __rv__v_sadd32(a, b) \
  (__builtin_riscv_v64_sadd32 ((a), (b)))
#define __rv__v_radd32(a, b) \
  (__builtin_riscv_v64_radd32 ((a), (b)))
#define __rv__v_uradd32(a, b) \
  (__builtin_riscv_v64_uradd32 ((a), (b)))
#define __rv__v_kadd32(a, b) \
  (__builtin_riscv_v64_kadd32 ((a), (b)))
#define __rv__v_ukadd32(a, b) \
  (__builtin_riscv_v64_ukadd32 ((a), (b)))
#define __rv__v_usub32(a, b) \
  (__builtin_riscv_v64_usub32 ((a), (b)))
#define __rv__v_ssub32(a, b) \
  (__builtin_riscv_v64_ssub32 ((a), (b)))
#define __rv__v_rsub32(a, b) \
  (__builtin_riscv_v64_rsub32 ((a), (b)))
#define __rv__v_ursub32(a, b) \
  (__builtin_riscv_v64_ursub32 ((a), (b)))
#define __rv__v_ksub32(a, b) \
  (__builtin_riscv_v64_ksub32 ((a), (b)))
#define __rv__v_uksub32(a, b) \
  (__builtin_riscv_v64_uksub32 ((a), (b)))
#define __rv__v_ucras32(a, b) \
  (__builtin_riscv_v64_ucras32 ((a), (b)))
#define __rv__v_scras32(a, b) \
  (__builtin_riscv_v64_scras32 ((a), (b)))
#define __rv__v_ucrsa32(a, b) \
  (__builtin_riscv_v64_ucrsa32 ((a), (b)))
#define __rv__v_scrsa32(a, b) \
  (__builtin_riscv_v64_scrsa32 ((a), (b)))
#define __rv__v_rcras32(a, b) \
  (__builtin_riscv_v64_rcras32 ((a), (b)))
#define __rv__v_rcrsa32(a, b) \
  (__builtin_riscv_v64_rcrsa32 ((a), (b)))
#define __rv__v_urcras32(a, b) \
  (__builtin_riscv_v64_urcras32 ((a), (b)))
#define __rv__v_urcrsa32(a, b) \
  (__builtin_riscv_v64_urcrsa32 ((a), (b)))
#define __rv__v_kcras32(a, b) \
  (__builtin_riscv_v64_kcras32 ((a), (b)))
#define __rv__v_kcrsa32(a, b) \
  (__builtin_riscv_v64_kcrsa32 ((a), (b)))
#define __rv__v_ukcras32(a, b) \
  (__builtin_riscv_v64_ukcras32 ((a), (b)))
#define __rv__v_ukcrsa32(a, b) \
  (__builtin_riscv_v64_ukcrsa32 ((a), (b)))
#define __rv__v_ustas32(a, b) \
  (__builtin_riscv_v64_ustas32 ((a), (b)))
#define __rv__v_sstas32(a, b) \
  (__builtin_riscv_v64_sstas32 ((a), (b)))
#define __rv__v_ustsa32(a, b) \
  (__builtin_riscv_v64_ustsa32 ((a), (b)))
#define __rv__v_sstsa32(a, b) \
  (__builtin_riscv_v64_sstsa32 ((a), (b)))
#define __rv__v_rstas32(a, b) \
  (__builtin_riscv_v64_rstas32 ((a), (b)))
#define __rv__v_rstsa32(a, b) \
  (__builtin_riscv_v64_rstsa32 ((a), (b)))
#define __rv__v_urstas32(a, b) \
  (__builtin_riscv_v64_urstas32 ((a), (b)))
#define __rv__v_urstsa32(a, b) \
  (__builtin_riscv_v64_urstsa32 ((a), (b)))
#define __rv__v_kstas32(a, b) \
  (__builtin_riscv_v64_kstas32 ((a), (b)))
#define __rv__v_kstsa32(a, b) \
  (__builtin_riscv_v64_kstsa32 ((a), (b)))
#define __rv__v_ukstas32(a, b) \
  (__builtin_riscv_v64_ukstas32 ((a), (b)))
#define __rv__v_ukstsa32(a, b) \
  (__builtin_riscv_v64_ukstsa32 ((a), (b)))
#define __rv__v_sra32(a, b) \
  (__builtin_riscv_v64_sra32 ((a), (b)))
#define __rv__v_sra32_u(a, b) \
  (__builtin_riscv_v64_sra32_u ((a), (b)))
#define __rv__v_srl32(a, b) \
  (__builtin_riscv_v64_srl32 ((a), (b)))
#define __rv__v_srl32_u(a, b) \
  (__builtin_riscv_v64_srl32_u ((a), (b)))
#define __rv__v_sll32(a, b) \
  (__builtin_riscv_v64_sll32 ((a), (b)))
#define __rv__v_ksll32(a, b) \
  (__builtin_riscv_v64_ksll32 ((a), (b)))
#define __rv__v_kslra32(a, b) \
  (__builtin_riscv_v64_kslra32 ((a), (b)))
#define __rv__v_kslra32_u(a, b) \
  (__builtin_riscv_v64_kslra32_u ((a), (b)))
#define __rv__v_smin32(a, b) \
  (__builtin_riscv_v64_smin32 ((a), (b)))
#define __rv__v_umin32(a, b) \
  (__builtin_riscv_v64_umin32 ((a), (b)))
#define __rv__v_smax32(a, b) \
  (__builtin_riscv_v64_smax32 ((a), (b)))
#define __rv__v_umax32(a, b) \
  (__builtin_riscv_v64_umax32 ((a), (b)))
#define __rv__v_kabs32(a) \
  (__builtin_riscv_v64_kabs32 ((a)))
#define __rv__v_khmbb16(a, b) \
  (__builtin_riscv_v64_khmbb16 ((a), (b)))
#define __rv__v_khmbt16(a, b) \
  (__builtin_riscv_v64_khmbt16 ((a), (b)))
#define __rv__v_khmtt16(a, b) \
  (__builtin_riscv_v64_khmtt16 ((a), (b)))
#define __rv__v_kdmbb16(a, b) \
  (__builtin_riscv_v64_kdmbb16 ((a), (b)))
#define __rv__v_kdmbt16(a, b) \
  (__builtin_riscv_v64_kdmbt16 ((a), (b)))
#define __rv__v_kdmtt16(a, b) \
  (__builtin_riscv_v64_kdmtt16 ((a), (b)))
#define __rv__v_smbb32(a, b) \
  (__builtin_riscv_v64_smbb32 ((a), (b)))
#define __rv__v_smbt32(a, b) \
  (__builtin_riscv_v64_smbt32 ((a), (b)))
#define __rv__v_smtt32(a, b) \
  (__builtin_riscv_v64_smtt32 ((a), (b)))
#define __rv__v_kmabb32(r, a, b) \
  (__builtin_riscv_v64_kmabb32 ((r), (a), (b)))
#define __rv__v_kmabt32(r, a, b) \
  (__builtin_riscv_v64_kmabt32 ((r), (a), (b)))
#define __rv__v_kmatt32(r, a, b) \
  (__builtin_riscv_v64_kmatt32 ((r), (a), (b)))
#define __rv__v_kmda32(a, b) \
  (__builtin_riscv_v64_kmda32 ((a), (b)))
#define __rv__v_kmxda32(a, b) \
  (__builtin_riscv_v64_kmxda32 ((a), (b)))
#define __rv__v_kmada32(r, a, b) \
  (__builtin_riscv_v64_kmada32 ((r), (a), (b)))
#define __rv__v_kmaxda32(r, a, b) \
  (__builtin_riscv_v64_kmaxda32 ((r), (a), (b)))
#define __rv__v_kmads32(r, a, b) \
  (__builtin_riscv_v64_kmads32 ((r), (a), (b)))
#define __rv__v_kmadrs32(r, a, b) \
  (__builtin_riscv_v64_kmadrs32 ((r), (a), (b)))
#define __rv__v_kmaxds32(r, a, b) \
  (__builtin_riscv_v64_kmaxds32 ((r), (a), (b)))
#define __rv__v_kmsda32(r, a, b) \
  (__builtin_riscv_v64_kmsda32 ((r), (a), (b)))
#define __rv__v_kmsxda32(r, a, b) \
  (__builtin_riscv_v64_kmsxda32 ((r), (a), (b)))
#define __rv__v_smds32(a, b) \
  (__builtin_riscv_v64_smds32 ((a), (b)))
#define __rv__v_smdrs32(a, b) \
  (__builtin_riscv_v64_smdrs32 ((a), (b)))
#define __rv__v_smxds32(a, b) \
  (__builtin_riscv_v64_smxds32 ((a), (b)))
#define __rv__v_pkbb32(a, b) \
  (__builtin_riscv_v64_pkbb32 ((a), (b)))
#define __rv__v_pkbt32(a, b) \
  (__builtin_riscv_v64_pkbt32 ((a), (b)))
#define __rv__v_pktb32(a, b) \
  (__builtin_riscv_v64_pktb32 ((a), (b)))
#define __rv__v_pktt32(a, b) \
  (__builtin_riscv_v64_pktt32 ((a), (b)))
#define __rv__sraw_u(a, b) \
  (__builtin_riscv_sraw_u ((a), (b)))
#endif 

#if defined(__riscv_zpsf)
#define __rv__smal(a, b) \
  (__builtin_riscv_smal ((a), (b)))
#define __rv__radd64(a, b) \
  (__builtin_riscv_radd64 ((a), (b)))
#define __rv__uradd64(a, b) \
  (__builtin_riscv_uradd64 ((a), (b)))
#define __rv__kadd64(a, b) \
  (__builtin_riscv_kadd64 ((a), (b)))
#define __rv__ukadd64(a, b) \
  (__builtin_riscv_ukadd64 ((a), (b)))
#define __rv__ssub64(a, b) \
  (__builtin_riscv_ssub64 ((a), (b)))
#define __rv__usub64(a, b) \
  (__builtin_riscv_usub64 ((a), (b)))
#define __rv__rsub64(a, b) \
  (__builtin_riscv_rsub64 ((a), (b)))
#define __rv__ursub64(a, b) \
  (__builtin_riscv_ursub64 ((a), (b)))
#define __rv__ksub64(a, b) \
  (__builtin_riscv_ksub64 ((a), (b)))
#define __rv__uksub64(a, b) \
  (__builtin_riscv_uksub64 ((a), (b)))
#define __rv__smul16(a, b) \
  (__builtin_riscv_smul16 ((a), (b)))
#define __rv__umul16(a, b) \
  (__builtin_riscv_umul16 ((a), (b)))
#define __rv__smul8(a, b) \
  (__builtin_riscv_smul8 ((a), (b)))
#define __rv__umul8(a, b) \
  (__builtin_riscv_umul8 ((a), (b)))
#define __rv__smulx16(a, b) \
  (__builtin_riscv_smulx16 ((a), (b)))
#define __rv__smulx8(a, b) \
  (__builtin_riscv_smulx8 ((a), (b)))
#define __rv__umulx16(a, b) \
  (__builtin_riscv_umulx16 ((a), (b)))
#define __rv__umulx8(a, b) \
  (__builtin_riscv_umulx8 ((a), (b)))
#define __rv__smar64(r, a, b) \
  (__builtin_riscv_smar64 ((r), (a), (b)))
#define __rv__smsr64(r, a, b) \
  (__builtin_riscv_smsr64 ((r), (a), (b)))
#define __rv__umar64(r, a, b) \
  (__builtin_riscv_umar64 ((r), (a), (b)))
#define __rv__umsr64(r, a, b) \
  (__builtin_riscv_umsr64 ((r), (a), (b)))
#define __rv__kmar64(r, a, b) \
  (__builtin_riscv_kmar64 ((r), (a), (b)))
#define __rv__kmsr64(r, a, b) \
  (__builtin_riscv_kmsr64 ((r), (a), (b)))
#define __rv__ukmar64(r, a, b) \
  (__builtin_riscv_ukmar64 ((r), (a), (b)))
#define __rv__ukmsr64(r, a, b) \
  (__builtin_riscv_ukmsr64 ((r), (a), (b)))
#define __rv__maddr32(a, b) \
  (__builtin_riscv_maddr32 ((a), (b)))
#define __rv__msubr32(a, b) \
  (__builtin_riscv_msubr32 ((a), (b)))
#define __rv__smalbb(r, a, b) \
  (__builtin_riscv_smalbb ((r), (a), (b)))
#define __rv__smalbt(r, a, b) \
  (__builtin_riscv_smalbt ((r), (a), (b)))
#define __rv__smaltt(r, a, b) \
  (__builtin_riscv_smaltt ((r), (a), (b)))
#define __rv__smalda(r, a, b) \
  (__builtin_riscv_smalda ((r), (a), (b)))
#define __rv__smalxda(r, a, b) \
  (__builtin_riscv_smalxda ((r), (a), (b)))
#define __rv__smalds(r, a, b) \
  (__builtin_riscv_smalds ((r), (a), (b)))
#define __rv__smaldrs(r, a, b) \
  (__builtin_riscv_smaldrs ((r), (a), (b)))
#define __rv__smalxds(r, a, b) \
  (__builtin_riscv_smalxds ((r), (a), (b)))
#define __rv__smslda(r, a, b) \
  (__builtin_riscv_smslda ((r), (a), (b)))
#define __rv__smslxda(r, a, b) \
  (__builtin_riscv_smslxda ((r), (a), (b)))
#define __rv__wext(a, b) \
  (__builtin_riscv_wext ((a), (b)))
#define __rv__v_smul16(a, b) \
  (__builtin_riscv_v_smul16 ((a), (b)))
#define __rv__v_smulx16(a, b) \
  (__builtin_riscv_v_smulx16 ((a), (b)))
#define __rv__v_umul16(a, b) \
  (__builtin_riscv_v_umul16 ((a), (b)))
#define __rv__v_smul8(a, b) \
  (__builtin_riscv_v_smul8 ((a), (b)))
#define __rv__v_umul8(a, b) \
  (__builtin_riscv_v_umul8 ((a), (b)))
#define __rv__v_smulx8(a, b) \
  (__builtin_riscv_v_smulx8 ((a), (b)))
#define __rv__v_umulx16(a, b) \
  (__builtin_riscv_v_umulx16 ((a), (b)))
#define __rv__v_umulx8(a, b) \
  (__builtin_riscv_v_umulx8 ((a), (b)))
#define __rv__sadd64(a, b) \
  (__builtin_riscv_sadd64 ((a), (b)))
#define __rv__uadd64(a, b) \
  (__builtin_riscv_uadd64 ((a), (b)))
#define __rv__mulr64(a, b) \
  (__builtin_riscv_mulr64 ((a), (b)))
#define __rv__mulsr64(a, b) \
  (__builtin_riscv_mulsr64 ((a), (b)))
#if __riscv_xlen == 32
#define __rv__v_smal(a, b) \
  (__builtin_riscv_v_smal ((a), (b)))
#define __rv__v_smalbb(r, a, b) \
  (__builtin_riscv_v_smalbb ((r), (a), (b)))
#define __rv__v_smalbt(r, a, b) \
  (__builtin_riscv_v_smalbt ((r), (a), (b)))
#define __rv__v_smaltt(r, a, b) \
  (__builtin_riscv_v_smaltt ((r), (a), (b)))
#define __rv__v_smalda(r, a, b) \
  (__builtin_riscv_v_smalda ((r), (a), (b)))
#define __rv__v_smalxda(r, a, b) \
  (__builtin_riscv_v_smalxda ((r), (a), (b)))
#define __rv__v_smalds(r, a, b) \
  (__builtin_riscv_v_smalds ((r), (a), (b)))
#define __rv__v_smaldrs(r, a, b) \
  (__builtin_riscv_v_smaldrs ((r), (a), (b)))
#define __rv__v_smalxds(r, a, b) \
  (__builtin_riscv_v_smalxds ((r), (a), (b)))
#define __rv__v_smslda(r, a, b) \
  (__builtin_riscv_v_smslda ((r), (a), (b)))
#define __rv__v_smslxda(r, a, b) \
  (__builtin_riscv_v_smslxda ((r), (a), (b)))
#else
#define __rv__v_smal(a, b) \
  (__builtin_riscv_v64_smal ((a), (b)))
#define __rv__v_smalbb(r, a, b) \
  (__builtin_riscv_v64_smalbb ((r), (a), (b)))
#define __rv__v_smalbt(r, a, b) \
  (__builtin_riscv_v64_smalbt ((r), (a), (b)))
#define __rv__v_smaltt(r, a, b) \
  (__builtin_riscv_v64_smaltt ((r), (a), (b)))
#define __rv__v_smalda(r, a, b) \
  (__builtin_riscv_v64_smalda ((r), (a), (b)))
#define __rv__v_smalxda(r, a, b) \
  (__builtin_riscv_v64_smalxda ((r), (a), (b)))
#define __rv__v_smalds(r, a, b) \
  (__builtin_riscv_v64_smalds ((r), (a), (b)))
#define __rv__v_smaldrs(r, a, b) \
  (__builtin_riscv_v64_smaldrs ((r), (a), (b)))
#define __rv__v_smalxds(r, a, b) \
  (__builtin_riscv_v64_smalxds ((r), (a), (b)))
#define __rv__v_smslda(r, a, b) \
  (__builtin_riscv_v64_smslda ((r), (a), (b)))
#define __rv__v_smslxda(r, a, b) \
  (__builtin_riscv_v64_smslxda ((r), (a), (b)))
#define __rv__v_smar64(r, a, b) \
  (__builtin_riscv_v64_smar64 ((r), (a), (b)))
#define __rv__v_smsr64(r, a, b) \
  (__builtin_riscv_v64_smsr64 ((r), (a), (b)))
#define __rv__v_umar64(r, a, b) \
  (__builtin_riscv_v64_umar64 ((r), (a), (b)))
#define __rv__v_umsr64(r, a, b) \
  (__builtin_riscv_v64_umsr64 ((r), (a), (b)))
#define __rv__v_kmar64(r, a, b) \
  (__builtin_riscv_v64_kmar64 ((r), (a), (b)))
#define __rv__v_kmsr64(r, a, b) \
  (__builtin_riscv_v64_kmsr64 ((r), (a), (b)))
#define __rv__v_ukmar64(r, a, b) \
  (__builtin_riscv_v64_ukmar64 ((r), (a), (b)))
#define __rv__v_ukmsr64(r, a, b) \
  (__builtin_riscv_v64_ukmsr64 ((r), (a), (b)))
#endif
#endif
#endif // END OF _RISCV_RVP_INTRINSIC_H