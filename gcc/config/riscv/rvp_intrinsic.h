/* Definitions for RISC-V GNU/Linux systems with ELF format.
   Copyright (C) 1998-2021 Free Software Foundation, Inc.

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

#define __riscv__add16(a, b) \
  (__builtin_riscv_add16 ((a), (b)))
#define __riscv__radd16(a, b) \
  (__builtin_riscv_radd16 ((a), (b)))
#define __riscv__uradd16(a, b) \
  (__builtin_riscv_uradd16 ((a), (b)))
#define __riscv__kadd16(a, b) \
  (__builtin_riscv_kadd16 ((a), (b)))
#define __riscv__ukadd16(a, b) \
  (__builtin_riscv_ukadd16 ((a), (b)))
#define __riscv__sub16(a, b) \
  (__builtin_riscv_sub16 ((a), (b)))
#define __riscv__rsub16(a, b) \
  (__builtin_riscv_rsub16 ((a), (b)))
#define __riscv__ursub16(a, b) \
  (__builtin_riscv_ursub16 ((a), (b)))
#define __riscv__ksub16(a, b) \
  (__builtin_riscv_ksub16 ((a), (b)))
#define __riscv__uksub16(a, b) \
  (__builtin_riscv_uksub16 ((a), (b)))
#define __riscv__cras16(a, b) \
  (__builtin_riscv_cras16 ((a), (b)))
#define __riscv__rcras16(a, b) \
  (__builtin_riscv_rcras16 ((a), (b)))
#define __riscv__urcras16(a, b) \
  (__builtin_riscv_urcras16 ((a), (b)))
#define __riscv__kcras16(a, b) \
  (__builtin_riscv_kcras16 ((a), (b)))
#define __riscv__ukcras16(a, b) \
  (__builtin_riscv_ukcras16 ((a), (b)))
#define __riscv__crsa16(a, b) \
  (__builtin_riscv_crsa16 ((a), (b)))
#define __riscv__rcrsa16(a, b) \
  (__builtin_riscv_rcrsa16 ((a), (b)))
#define __riscv__urcrsa16(a, b) \
  (__builtin_riscv_urcrsa16 ((a), (b)))
#define __riscv__kcrsa16(a, b) \
  (__builtin_riscv_kcrsa16 ((a), (b)))
#define __riscv__ukcrsa16(a, b) \
  (__builtin_riscv_ukcrsa16 ((a), (b)))
#define __riscv__stas16(a, b) \
  (__builtin_riscv_stas16 ((a), (b)))
#define __riscv__rstas16(a, b) \
  (__builtin_riscv_rstas16 ((a), (b)))
#define __riscv__urstas16(a, b) \
  (__builtin_riscv_urstas16 ((a), (b)))
#define __riscv__kstas16(a, b) \
  (__builtin_riscv_kstas16 ((a), (b)))
#define __riscv__ukstas16(a, b) \
  (__builtin_riscv_ukstas16 ((a), (b)))
#define __riscv__stsa16(a, b) \
  (__builtin_riscv_stsa16 ((a), (b)))
#define __riscv__rstsa16(a, b) \
  (__builtin_riscv_rstsa16 ((a), (b)))
#define __riscv__urstsa16(a, b) \
  (__builtin_riscv_urstsa16 ((a), (b)))
#define __riscv__kstsa16(a, b) \
  (__builtin_riscv_kstsa16 ((a), (b)))
#define __riscv__ukstsa16(a, b) \
  (__builtin_riscv_ukstsa16 ((a), (b)))
#define __riscv__add8(a, b) \
  (__builtin_riscv_add8 ((a), (b)))
#define __riscv__radd8(a, b) \
  (__builtin_riscv_radd8 ((a), (b)))
#define __riscv__uradd8(a, b) \
  (__builtin_riscv_uradd8 ((a), (b)))
#define __riscv__kadd8(a, b) \
  (__builtin_riscv_kadd8 ((a), (b)))
#define __riscv__ukadd8(a, b) \
  (__builtin_riscv_ukadd8 ((a), (b)))
#define __riscv__sub8(a, b) \
  (__builtin_riscv_sub8 ((a), (b)))
#define __riscv__rsub8(a, b) \
  (__builtin_riscv_rsub8 ((a), (b)))
#define __riscv__ursub8(a, b) \
  (__builtin_riscv_ursub8 ((a), (b)))
#define __riscv__ksub8(a, b) \
  (__builtin_riscv_ksub8 ((a), (b)))
#define __riscv__uksub8(a, b) \
  (__builtin_riscv_uksub8 ((a), (b)))

#define __riscv__sra16(a, b) \
  (__builtin_riscv_sra16 ((a), (b)))
#define __riscv__sra16_u(a, b) \
  (__builtin_riscv_sra16_u ((a), (b)))
#define __riscv__srl16(a, b) \
  (__builtin_riscv_srl16 ((a), (b)))
#define __riscv__srl16_u(a, b) \
  (__builtin_riscv_srl16_u ((a), (b)))
#define __riscv__sll16(a, b) \
  (__builtin_riscv_sll16 ((a), (b)))
#define __riscv__ksll16(a, b) \
  (__builtin_riscv_ksll16 ((a), (b)))
#define __riscv__kslra16(a, b) \
  (__builtin_riscv_kslra16 ((a), (b)))
#define __riscv__kslra16_u(a, b) \
  (__builtin_riscv_kslra16_u ((a), (b)))

#define __riscv__cmpeq16(a, b) \
  (__builtin_riscv_cmpeq16 ((a), (b)))
#define __riscv__scmplt16(a, b) \
  (__builtin_riscv_scmplt16 ((a), (b)))
#define __riscv__scmple16(a, b) \
  (__builtin_riscv_scmple16 ((a), (b)))
#define __riscv__ucmplt16(a, b) \
  (__builtin_riscv_ucmplt16 ((a), (b)))
#define __riscv__ucmple16(a, b) \
  (__builtin_riscv_ucmple16 ((a), (b)))
#define __riscv__cmpeq8(a, b) \
  (__builtin_riscv_cmpeq8 ((a), (b)))
#define __riscv__scmplt8(a, b) \
  (__builtin_riscv_scmplt8 ((a), (b)))
#define __riscv__scmple8(a, b) \
  (__builtin_riscv_scmple8 ((a), (b)))
#define __riscv__ucmplt8(a, b) \
  (__builtin_riscv_ucmplt8 ((a), (b)))
#define __riscv__ucmple8(a, b) \
  (__builtin_riscv_ucmple8 ((a), (b)))
#define __riscv__smin16(a, b) \
  (__builtin_riscv_smin16 ((a), (b)))
#define __riscv__umin16(a, b) \
  (__builtin_riscv_umin16 ((a), (b)))
#define __riscv__smax16(a, b) \
  (__builtin_riscv_smax16 ((a), (b)))
#define __riscv__umax16(a, b) \
  (__builtin_riscv_umax16 ((a), (b)))
#define __riscv__sclip16(a, b) \
  (__builtin_riscv_sclip16 ((a), (b)))
#define __riscv__uclip16(a, b) \
  (__builtin_riscv_uclip16 ((a), (b)))
#define __riscv__khm16(a, b) \
  (__builtin_riscv_khm16 ((a), (b)))
#define __riscv__khmx16(a, b) \
  (__builtin_riscv_khmx16 ((a), (b)))
#define __riscv__khm8(a, b) \
  (__builtin_riscv_khm8 ((a), (b)))
#define __riscv__khmx8(a, b) \
  (__builtin_riscv_khmx8 ((a), (b)))
#define __riscv__kabs16(a) \
  (__builtin_riscv_kabs16 ((a)))
#define __riscv__smin8(a, b) \
  (__builtin_riscv_smin8 ((a), (b)))
#define __riscv__umin8(a, b) \
  (__builtin_riscv_umin8 ((a), (b)))
#define __riscv__smax8(a, b) \
  (__builtin_riscv_smax8 ((a), (b)))
#define __riscv__umax8(a, b) \
  (__builtin_riscv_umax8 ((a), (b)))
#define __riscv__kabs8(a) \
  (__builtin_riscv_kabs8 ((a)))
#define __riscv__sunpkd810(a) \
  (__builtin_riscv_sunpkd810 ((a)))
#define __riscv__sunpkd820(a) \
  (__builtin_riscv_sunpkd820 ((a)))
#define __riscv__sunpkd830(a) \
  (__builtin_riscv_sunpkd830 ((a)))
#define __riscv__sunpkd831(a) \
  (__builtin_riscv_sunpkd831 ((a)))
#define __riscv__sunpkd832(a) \
  (__builtin_riscv_sunpkd832 ((a)))
#define __riscv__zunpkd810(a) \
  (__builtin_riscv_zunpkd810 ((a)))
#define __riscv__zunpkd820(a) \
  (__builtin_riscv_zunpkd820 ((a)))
#define __riscv__zunpkd830(a) \
  (__builtin_riscv_zunpkd830 ((a)))
#define __riscv__zunpkd831(a) \
  (__builtin_riscv_zunpkd831 ((a)))
#define __riscv__zunpkd832(a) \
  (__builtin_riscv_zunpkd832 ((a)))
#define __riscv__raddw(a, b) \
  (__builtin_riscv_raddw ((a), (b)))
#define __riscv__uraddw(a, b) \
  (__builtin_riscv_uraddw ((a), (b)))
#define __riscv__rsubw(a, b) \
  (__builtin_riscv_rsubw ((a), (b)))
#define __riscv__ursubw(a, b) \
  (__builtin_riscv_ursubw ((a), (b)))

#define __riscv__sra_u(a, b) \
  (__builtin_riscv_sra_u ((a), (b)))
#define __riscv__ksllw(a, b) \
  (__builtin_riscv_ksllw ((a), (b)))
#define __riscv__pkbb16(a, b) \
  (__builtin_riscv_pkbb16 ((a), (b)))
#define __riscv__pkbt16(a, b) \
  (__builtin_riscv_pkbt16 ((a), (b)))
#define __riscv__pktb16(a, b) \
  (__builtin_riscv_pktb16 ((a), (b)))
#define __riscv__pktt16(a, b) \
  (__builtin_riscv_pktt16 ((a), (b)))
#define __riscv__pkbb32(a, b) \
  (__builtin_riscv_pkbb32 ((a), (b)))
#define __riscv__pkbt32(a, b) \
  (__builtin_riscv_pkbt32 ((a), (b)))
#define __riscv__pktb32(a, b) \
  (__builtin_riscv_pktb32 ((a), (b)))
#define __riscv__pktt32(a, b) \
  (__builtin_riscv_pktt32 ((a), (b)))

#define __riscv__smmul(a, b) \
  (__builtin_riscv_smmul ((a), (b)))
#define __riscv__smmul_u(a, b) \
  (__builtin_riscv_smmul_u ((a), (b)))
#define __riscv__kmmac(r, a, b) \
  (__builtin_riscv_kmmac ((r), (a), (b)))
#define __riscv__kmmac_u(r, a, b) \
  (__builtin_riscv_kmmac_u ((r), (a), (b)))
#define __riscv__kmmsb(r, a, b) \
  (__builtin_riscv_kmmsb ((r), (a), (b)))
#define __riscv__kmmsb_u(r, a, b) \
  (__builtin_riscv_kmmsb_u ((r), (a), (b)))
#define __riscv__kwmmul(a, b) \
  (__builtin_riscv_kwmmul ((a), (b)))
#define __riscv__kwmmul_u(a, b) \
  (__builtin_riscv_kwmmul_u ((a), (b)))
#define __riscv__smmwb(a, b) \
  (__builtin_riscv_smmwb ((a), (b)))
#define __riscv__smmwb_u(a, b) \
  (__builtin_riscv_smmwb_u ((a), (b)))
#define __riscv__smmwt(a, b) \
  (__builtin_riscv_smmwt ((a), (b)))
#define __riscv__smmwt_u(a, b) \
  (__builtin_riscv_smmwt_u ((a), (b)))
#define __riscv__kmmwb2(a, b) \
  (__builtin_riscv_kmmwb2 ((a), (b)))
#define __riscv__kmmwb2_u(a, b) \
  (__builtin_riscv_kmmwb2_u ((a), (b)))
#define __riscv__kmmwt2(a, b) \
  (__builtin_riscv_kmmwt2 ((a), (b)))
#define __riscv__kmmwt2_u(a, b) \
  (__builtin_riscv_kmmwt2_u ((a), (b)))
#define __riscv__kmmawb(r, a, b) \
  (__builtin_riscv_kmmawb ((r), (a), (b)))
#define __riscv__kmmawb_u(r, a, b) \
  (__builtin_riscv_kmmawb_u ((r), (a), (b)))
#define __riscv__kmmawt(r, a, b) \
  (__builtin_riscv_kmmawt ((r), (a), (b)))
#define __riscv__kmmawt_u(r, a, b) \
  (__builtin_riscv_kmmawt_u ((r), (a), (b)))
#define __riscv__kmmawb2(r, a, b) \
  (__builtin_riscv_kmmawb2 ((r), (a), (b)))
#define __riscv__kmmawb2_u(r, a, b) \
  (__builtin_riscv_kmmawb2_u ((r), (a), (b)))
#define __riscv__kmmawt2(r, a, b) \
  (__builtin_riscv_kmmawt2 ((r), (a), (b)))
#define __riscv__kmmawt2_u(r, a, b) \
  (__builtin_riscv_kmmawt2_u ((r), (a), (b)))
#define __riscv__smbb16(a, b) \
  (__builtin_riscv_smbb16 ((a), (b)))
#define __riscv__smbt16(a, b) \
  (__builtin_riscv_smbt16 ((a), (b)))
#define __riscv__smtt16(a, b) \
  (__builtin_riscv_smtt16 ((a), (b)))
#define __riscv__kmda(a, b) \
  (__builtin_riscv_kmda ((a), (b)))
#define __riscv__kmxda(a, b) \
  (__builtin_riscv_kmxda ((a), (b)))
#define __riscv__smds(a, b) \
  (__builtin_riscv_smds ((a), (b)))
#define __riscv__smdrs(a, b) \
  (__builtin_riscv_smdrs ((a), (b)))
#define __riscv__smxds(a, b) \
  (__builtin_riscv_smxds ((a), (b)))
#define __riscv__kmabb(r, a, b) \
  (__builtin_riscv_kmabb ((r), (a), (b)))
#define __riscv__kmabt(r, a, b) \
  (__builtin_riscv_kmabt ((r), (a), (b)))
#define __riscv__kmatt(r, a, b) \
  (__builtin_riscv_kmatt ((r), (a), (b)))
#define __riscv__kmada(r, a, b) \
  (__builtin_riscv_kmada ((r), (a), (b)))
#define __riscv__kmaxda(r, a, b) \
  (__builtin_riscv_kmaxda ((r), (a), (b)))
#define __riscv__kmads(r, a, b) \
  (__builtin_riscv_kmads ((r), (a), (b)))
#define __riscv__kmadrs(r, a, b) \
  (__builtin_riscv_kmadrs ((r), (a), (b)))
#define __riscv__kmaxds(r, a, b) \
  (__builtin_riscv_kmaxds ((r), (a), (b)))
#define __riscv__kmsda(r, a, b) \
  (__builtin_riscv_kmsda ((r), (a), (b)))
#define __riscv__kmsxda(r, a, b) \
  (__builtin_riscv_kmsxda ((r), (a), (b)))
#define __riscv__smal(a, b) \
  (__builtin_riscv_smal ((a), (b)))
#define __riscv__bitrev(a, b) \
  (__builtin_riscv_bitrev ((a), (b)))
#define __riscv__wext(a, b) \
  (__builtin_riscv_wext ((a), (b)))
#define __riscv__bpick(r, a, b) \
  (__builtin_riscv_bpick ((r), (a), (b)))
#define __riscv__insb(r, a, b) \
  (__builtin_riscv_insb ((r), (a), (b)))
#define __riscv__sadd64(a, b) \
  (__builtin_riscv_sadd64 ((a), (b)))
#define __riscv__uadd64(a, b) \
  (__builtin_riscv_uadd64 ((a), (b)))
#define __riscv__radd64(a, b) \
  (__builtin_riscv_radd64 ((a), (b)))
#define __riscv__uradd64(a, b) \
  (__builtin_riscv_uradd64 ((a), (b)))
#define __riscv__kadd64(a, b) \
  (__builtin_riscv_kadd64 ((a), (b)))
#define __riscv__ukadd64(a, b) \
  (__builtin_riscv_ukadd64 ((a), (b)))
#define __riscv__ssub64(a, b) \
  (__builtin_riscv_ssub64 ((a), (b)))
#define __riscv__usub64(a, b) \
  (__builtin_riscv_usub64 ((a), (b)))
#define __riscv__rsub64(a, b) \
  (__builtin_riscv_rsub64 ((a), (b)))
#define __riscv__ursub64(a, b) \
  (__builtin_riscv_ursub64 ((a), (b)))
#define __riscv__ksub64(a, b) \
  (__builtin_riscv_ksub64 ((a), (b)))
#define __riscv__uksub64(a, b) \
  (__builtin_riscv_uksub64 ((a), (b)))
#define __riscv__smalbb(r, a, b) \
  (__builtin_riscv_smalbb ((r), (a), (b)))
#define __riscv__smalbt(r, a, b) \
  (__builtin_riscv_smalbt ((r), (a), (b)))
#define __riscv__smaltt(r, a, b) \
  (__builtin_riscv_smaltt ((r), (a), (b)))
#define __riscv__smalda(r, a, b) \
  (__builtin_riscv_smalda ((r), (a), (b)))
#define __riscv__smalxda(r, a, b) \
  (__builtin_riscv_smalxda ((r), (a), (b)))
#define __riscv__smalds(r, a, b) \
  (__builtin_riscv_smalds ((r), (a), (b)))
#define __riscv__smaldrs(r, a, b) \
  (__builtin_riscv_smaldrs ((r), (a), (b)))
#define __riscv__smalxds(r, a, b) \
  (__builtin_riscv_smalxds ((r), (a), (b)))
#define __riscv__smslda(r, a, b) \
  (__builtin_riscv_smslda ((r), (a), (b)))
#define __riscv__smslxda(r, a, b) \
  (__builtin_riscv_smslxda ((r), (a), (b)))
#define __riscv__uclip32(a, imm) \
  (__builtin_riscv_uclip32 ((a), (imm)))
#define __riscv__sclip32(a, imm) \
  (__builtin_riscv_sclip32 ((a), (imm)))
#define __riscv__kabsw(a) \
  (__builtin_riscv_kabsw ((a)))
#define __riscv__kaddw(a, b) \
  (__builtin_riscv_kaddw ((a), (b)))
#define __riscv__kaddh(a, b) \
  (__builtin_riscv_kaddh ((a), (b)))
#define __riscv__ksubw(a, b) \
  (__builtin_riscv_ksubw ((a), (b)))
#define __riscv__ksubh(a, b) \
  (__builtin_riscv_ksubh ((a), (b)))
#define __riscv__ukaddw(a, b) \
  (__builtin_riscv_ukaddw ((a), (b)))
#define __riscv__ukaddh(a, b) \
  (__builtin_riscv_ukaddh ((a), (b)))
#define __riscv__uksubw(a, b) \
  (__builtin_riscv_uksubw ((a), (b)))
#define __riscv__uksubh(a, b) \
  (__builtin_riscv_uksubh ((a), (b)))
#define __riscv__kdmbb(a, b) \
  (__builtin_riscv_kdmbb ((a), (b)))
#define __riscv__kdmbt(a, b) \
  (__builtin_riscv_kdmbt ((a), (b)))
#define __riscv__kdmtt(a, b) \
  (__builtin_riscv_kdmtt ((a), (b)))
#define __riscv__khmbb(a, b) \
  (__builtin_riscv_khmbb ((a), (b)))
#define __riscv__khmbt(a, b) \
  (__builtin_riscv_khmbt ((a), (b)))
#define __riscv__khmtt(a, b) \
  (__builtin_riscv_khmtt ((a), (b)))
#define __riscv__kslraw(a, b) \
  (__builtin_riscv_kslraw ((a), (b)))
#define __riscv__kslraw_u(a, b) \
  (__builtin_riscv_kslraw_u ((a), (b)))
#define __riscv__ave(a, b) \
  (__builtin_riscv_ave ((a), (b)))
#define __riscv__maxw(a, b) \
  (__builtin_riscv_maxw ((a), (b)))
#define __riscv__minw(a, b) \
  (__builtin_riscv_minw ((a), (b)))
#define __riscv__sra8(a, b) \
  (__builtin_riscv_sra8 ((a), (b)))
#define __riscv__sra8_u(a, b) \
  (__builtin_riscv_sra8_u ((a), (b)))
#define __riscv__srl8(a, b) \
  (__builtin_riscv_srl8 ((a), (b)))
#define __riscv__srl8_u(a, b) \
  (__builtin_riscv_srl8_u ((a), (b)))
#define __riscv__sll8(a, b) \
  (__builtin_riscv_sll8 ((a), (b)))
#define __riscv__ksll8(a, b) \
  (__builtin_riscv_ksll8 ((a), (b)))
#define __riscv__kslra8(a, b) \
  (__builtin_riscv_kslra8 ((a), (b)))
#define __riscv__kslra8_u(a, b) \
  (__builtin_riscv_kslra8_u ((a), (b)))
#define __riscv__pbsad(a, b) \
  (__builtin_riscv_pbsad ((a), (b)))
#define __riscv__pbsada(acc, a, b) \
  (__builtin_riscv_pbsada ((acc), (a), (b)))
#define __riscv__swap8(a) \
  (__builtin_riscv_swap8 ((a)))
#define __riscv__swap16(a) \
  (__builtin_riscv_pkbt16 ((a), (a)))
#define __riscv__sclip8(a, b) \
  (__builtin_riscv_sclip8 ((a), (b)))
#define __riscv__uclip8(a, b) \
  (__builtin_riscv_uclip8 ((a), (b)))
#define __riscv__sraw_u(a, b) \
  (__builtin_riscv_sraw_u ((a), (b)))
#define __riscv__add32(a, b) \
  (__builtin_riscv_add32 ((a), (b)))
#define __riscv__radd32(a, b) \
  (__builtin_riscv_radd32 ((a), (b)))
#define __riscv__uradd32(a, b) \
  (__builtin_riscv_uradd32 ((a), (b)))
#define __riscv__kadd32(a, b) \
  (__builtin_riscv_kadd32 ((a), (b)))
#define __riscv__ukadd32(a, b) \
  (__builtin_riscv_ukadd32 ((a), (b)))
#define __riscv__sub32(a, b) \
  (__builtin_riscv_sub32 ((a), (b)))
#define __riscv__rsub32(a, b) \
  (__builtin_riscv_rsub32 ((a), (b)))
#define __riscv__ursub32(a, b) \
  (__builtin_riscv_ursub32 ((a), (b)))
#define __riscv__ksub32(a, b) \
  (__builtin_riscv_ksub32 ((a), (b)))
#define __riscv__uksub32(a, b) \
  (__builtin_riscv_uksub32 ((a), (b)))
#define __riscv__cras32(a, b) \
  (__builtin_riscv_cras32 ((a), (b)))
#define __riscv__crsa32(a, b) \
  (__builtin_riscv_crsa32 ((a), (b)))
#define __riscv__rcras32(a, b) \
  (__builtin_riscv_rcras32 ((a), (b)))
#define __riscv__rcrsa32(a, b) \
  (__builtin_riscv_rcrsa32 ((a), (b)))
#define __riscv__urcras32(a, b) \
  (__builtin_riscv_urcras32 ((a), (b)))
#define __riscv__urcrsa32(a, b) \
  (__builtin_riscv_urcrsa32 ((a), (b)))
#define __riscv__kcras32(a, b) \
  (__builtin_riscv_kcras32 ((a), (b)))
#define __riscv__kcrsa32(a, b) \
  (__builtin_riscv_kcrsa32 ((a), (b)))
#define __riscv__ukcras32(a, b) \
  (__builtin_riscv_ukcras32 ((a), (b)))
#define __riscv__ukcrsa32(a, b) \
  (__builtin_riscv_ukcrsa32 ((a), (b)))
#define __riscv__stas32(a, b) \
  (__builtin_riscv_stas32 ((a), (b)))
#define __riscv__stsa32(a, b) \
  (__builtin_riscv_stsa32 ((a), (b)))
#define __riscv__rstas32(a, b) \
  (__builtin_riscv_rstas32 ((a), (b)))
#define __riscv__rstsa32(a, b) \
  (__builtin_riscv_rstsa32 ((a), (b)))
#define __riscv__urstas32(a, b) \
  (__builtin_riscv_urstas32 ((a), (b)))
#define __riscv__urstsa32(a, b) \
  (__builtin_riscv_urstsa32 ((a), (b)))
#define __riscv__kstas32(a, b) \
  (__builtin_riscv_kstas32 ((a), (b)))
#define __riscv__kstsa32(a, b) \
  (__builtin_riscv_kstsa32 ((a), (b)))
#define __riscv__ukstas32(a, b) \
  (__builtin_riscv_ukstas32 ((a), (b)))
#define __riscv__ukstsa32(a, b) \
  (__builtin_riscv_ukstsa32 ((a), (b)))
#define __riscv__sra32(a, b) \
  (__builtin_riscv_sra32 ((a), (b)))
#define __riscv__sra32_u(a, b) \
  (__builtin_riscv_sra32_u ((a), (b)))
#define __riscv__srl32(a, b) \
  (__builtin_riscv_srl32 ((a), (b)))
#define __riscv__srl32_u(a, b) \
  (__builtin_riscv_srl32_u ((a), (b)))
#define __riscv__sll32(a, b) \
  (__builtin_riscv_sll32 ((a), (b)))
#define __riscv__ksll32(a, b) \
  (__builtin_riscv_ksll32 ((a), (b)))
#define __riscv__kslra32(a, b) \
  (__builtin_riscv_kslra32 ((a), (b)))
#define __riscv__kslra32_u(a, b) \
  (__builtin_riscv_kslra32_u ((a), (b)))
#define __riscv__smin32(a, b) \
  (__builtin_riscv_smin32 ((a), (b)))
#define __riscv__umin32(a, b) \
  (__builtin_riscv_umin32 ((a), (b)))
#define __riscv__smax32(a, b) \
  (__builtin_riscv_smax32 ((a), (b)))
#define __riscv__umax32(a, b) \
  (__builtin_riscv_umax32 ((a), (b)))
#define __riscv__kabs32(a) \
  (__builtin_riscv_kabs32 ((a)))
#define __riscv__khmbb16(a, b) \
  (__builtin_riscv_khmbb16 ((a), (b)))
#define __riscv__khmbt16(a, b) \
  (__builtin_riscv_khmbt16 ((a), (b)))
#define __riscv__khmtt16(a, b) \
  (__builtin_riscv_khmtt16 ((a), (b)))
#define __riscv__kdmbb16(a, b) \
  (__builtin_riscv_kdmbb16 ((a), (b)))
#define __riscv__kdmbt16(a, b) \
  (__builtin_riscv_kdmbt16 ((a), (b)))
#define __riscv__kdmtt16(a, b) \
  (__builtin_riscv_kdmtt16 ((a), (b)))
#define __riscv__smbb32(a, b) \
  (__builtin_riscv_smbb32 ((a), (b)))
#define __riscv__smbt32(a, b) \
  (__builtin_riscv_smbt32 ((a), (b)))
#define __riscv__smtt32(a, b) \
  (__builtin_riscv_smtt32 ((a), (b)))
#define __riscv__kmabb32(r, a, b) \
  (__builtin_riscv_kmabb32 ((r), (a), (b)))
#define __riscv__kmabt32(r, a, b) \
  (__builtin_riscv_kmabt32 ((r), (a), (b)))
#define __riscv__kmatt32(r, a, b) \
  (__builtin_riscv_kmatt32 ((r), (a), (b)))
#define __riscv__kmda32(a, b) \
  (__builtin_riscv_kmda32 ((a), (b)))
#define __riscv__kmxda32(a, b) \
  (__builtin_riscv_kmxda32 ((a), (b)))
#define __riscv__kmada32(r, a, b) \
  (__builtin_riscv_kmada32 ((r), (a), (b)))
#define __riscv__kmaxda32(r, a, b) \
  (__builtin_riscv_kmaxda32 ((r), (a), (b)))
#define __riscv__kmads32(r, a, b) \
  (__builtin_riscv_kmads32 ((r), (a), (b)))
#define __riscv__kmadrs32(r, a, b) \
  (__builtin_riscv_kmadrs32 ((r), (a), (b)))
#define __riscv__kmaxds32(r, a, b) \
  (__builtin_riscv_kmaxds32 ((r), (a), (b)))
#define __riscv__kmsda32(r, a, b) \
  (__builtin_riscv_kmsda32 ((r), (a), (b)))
#define __riscv__kmsxda32(r, a, b) \
  (__builtin_riscv_kmsxda32 ((r), (a), (b)))
#define __riscv__smds32(a, b) \
  (__builtin_riscv_smds32 ((a), (b)))
#define __riscv__smdrs32(a, b) \
  (__builtin_riscv_smdrs32 ((a), (b)))
#define __riscv__smxds32(a, b) \
  (__builtin_riscv_smxds32 ((a), (b)))
#define __riscv__rdov() \
  (__builtin_riscv_csrr (0x801))
#define __riscv__clrov() \
  (__builtin_riscv_csrc (1, 0x801))
#define __riscv__kdmabb16(r, a, b) \
  (__builtin_riscv_kdmabb16 ((r), (a), (b)))
#define __riscv__kdmabt16(r, a, b) \
  (__builtin_riscv_kdmabt16 ((r), (a), (b)))
#define __riscv__kdmatt16(r, a, b) \
  (__builtin_riscv_kdmatt16 ((r), (a), (b)))
#define __riscv__kdmabb(r, a, b) \
  (__builtin_riscv_kdmabb ((r), (a), (b)))
#define __riscv__kdmabt(r, a, b) \
  (__builtin_riscv_kdmabt ((r), (a), (b)))
#define __riscv__kdmatt(r, a, b) \
  (__builtin_riscv_kdmatt ((r), (a), (b)))
#define __riscv__smaqa(r, a, b) \
  (__builtin_riscv_smaqa ((r), (a), (b)))
#define __riscv__umaqa(r, a, b) \
  (__builtin_riscv_umaqa ((r), (a), (b)))
#define __riscv__smaqa_su(r, a, b) \
  (__builtin_riscv_smaqa_su ((r), (a), (b)))
#define __riscv__clrs8(a) \
  (__builtin_riscv_clrs8 ((a)))
#define __riscv__clrs16(a) \
  (__builtin_riscv_clrs16 ((a)))
#define __riscv__clrs32(a) \
  (__builtin_riscv_clrs32 ((a)))
#define __riscv__clo8(a) \
  (__builtin_riscv_clo8 ((a)))
#define __riscv__clo16(a) \
  (__builtin_riscv_clo16 ((a)))
#define __riscv__clo32(a) \
  (__builtin_riscv_clo32 ((a)))
#define __riscv__clz8(a) \
  (__builtin_riscv_clz8 ((a)))
#define __riscv__clz16(a) \
  (__builtin_riscv_clz16 ((a)))
#define __riscv__clz32(a) \
  (__builtin_riscv_clz32 ((a)))
#define __riscv__smul16(a, b) \
  (__builtin_riscv_smul16 ((a), (b)))
#define __riscv__umul16(a, b) \
  (__builtin_riscv_umul16 ((a), (b)))
#define __riscv__smul8(a, b) \
  (__builtin_riscv_smul8 ((a), (b)))
#define __riscv__umul8(a, b) \
  (__builtin_riscv_umul8 ((a), (b)))
#define __riscv__smulx16(a, b) \
  (__builtin_riscv_smulx16 ((a), (b)))
#define __riscv__smulx8(a, b) \
  (__builtin_riscv_smulx8 ((a), (b)))
#define __riscv__umulx16(a, b) \
  (__builtin_riscv_umulx16 ((a), (b)))
#define __riscv__umulx8(a, b) \
  (__builtin_riscv_umulx8 ((a), (b)))
#define __riscv__smar64(r, a, b) \
  (__builtin_riscv_smar64 ((r), (a), (b)))
#define __riscv__smsr64(r, a, b) \
  (__builtin_riscv_smsr64 ((r), (a), (b)))
#define __riscv__umar64(r, a, b) \
  (__builtin_riscv_umar64 ((r), (a), (b)))
#define __riscv__umsr64(r, a, b) \
  (__builtin_riscv_umsr64 ((r), (a), (b)))
#define __riscv__kmar64(r, a, b) \
  (__builtin_riscv_kmar64 ((r), (a), (b)))
#define __riscv__kmsr64(r, a, b) \
  (__builtin_riscv_kmsr64 ((r), (a), (b)))
#define __riscv__ukmar64(r, a, b) \
  (__builtin_riscv_ukmar64 ((r), (a), (b)))
#define __riscv__ukmsr64(r, a, b) \
  (__builtin_riscv_ukmsr64 ((r), (a), (b)))

#if __riscv_xlen == 32
#define __riscv__v_uadd16(a, b) \
  (__builtin_riscv_v_uadd16 ((a), (b)))
#define __riscv__v_sadd16(a, b) \
  (__builtin_riscv_v_sadd16 ((a), (b)))
#define __riscv__v_radd16(a, b) \
  (__builtin_riscv_v_radd16 ((a), (b)))
#define __riscv__v_uradd16(a, b) \
  (__builtin_riscv_v_uradd16 ((a), (b)))
#define __riscv__v_kadd16(a, b) \
  (__builtin_riscv_v_kadd16 ((a), (b)))
#define __riscv__v_ukadd16(a, b) \
  (__builtin_riscv_v_ukadd16 ((a), (b)))
#define __riscv__v_usub16(a, b) \
  (__builtin_riscv_v_usub16 ((a), (b)))
#define __riscv__v_ssub16(a, b) \
  (__builtin_riscv_v_ssub16 ((a), (b)))
#define __riscv__v_rsub16(a, b) \
  (__builtin_riscv_v_rsub16 ((a), (b)))
#define __riscv__v_ursub16(a, b) \
  (__builtin_riscv_v_ursub16 ((a), (b)))
#define __riscv__v_ksub16(a, b) \
  (__builtin_riscv_v_ksub16 ((a), (b)))
#define __riscv__v_uksub16(a, b) \
  (__builtin_riscv_v_uksub16 ((a), (b)))
#define __riscv__v_ucras16(a, b) \
  (__builtin_riscv_v_ucras16 ((a), (b)))
#define __riscv__v_scras16(a, b) \
  (__builtin_riscv_v_scras16 ((a), (b)))
#define __riscv__v_rcras16(a, b) \
  (__builtin_riscv_v_rcras16 ((a), (b)))
#define __riscv__v_urcras16(a, b) \
  (__builtin_riscv_v_urcras16 ((a), (b)))
#define __riscv__v_kcras16(a, b) \
  (__builtin_riscv_v_kcras16 ((a), (b)))
#define __riscv__v_ukcras16(a, b) \
  (__builtin_riscv_v_ukcras16 ((a), (b)))
#define __riscv__v_ucrsa16(a, b) \
  (__builtin_riscv_v_ucrsa16 ((a), (b)))
#define __riscv__v_scrsa16(a, b) \
  (__builtin_riscv_v_scrsa16 ((a), (b)))
#define __riscv__v_rcrsa16(a, b) \
  (__builtin_riscv_v_rcrsa16 ((a), (b)))
#define __riscv__v_urcrsa16(a, b) \
  (__builtin_riscv_v_urcrsa16 ((a), (b)))
#define __riscv__v_kcrsa16(a, b) \
  (__builtin_riscv_v_kcrsa16 ((a), (b)))
#define __riscv__v_ukcrsa16(a, b) \
  (__builtin_riscv_v_ukcrsa16 ((a), (b)))
#define __riscv__v_ustas16(a, b) \
  (__builtin_riscv_v_ustas16 ((a), (b)))
#define __riscv__v_sstas16(a, b) \
  (__builtin_riscv_v_sstas16 ((a), (b)))
#define __riscv__v_rstas16(a, b) \
  (__builtin_riscv_v_rstas16 ((a), (b)))
#define __riscv__v_urstas16(a, b) \
  (__builtin_riscv_v_urstas16 ((a), (b)))
#define __riscv__v_kstas16(a, b) \
  (__builtin_riscv_v_kstas16 ((a), (b)))
#define __riscv__v_ukstas16(a, b) \
  (__builtin_riscv_v_ukstas16 ((a), (b)))
#define __riscv__v_ustsa16(a, b) \
  (__builtin_riscv_v_ustsa16 ((a), (b)))
#define __riscv__v_sstsa16(a, b) \
  (__builtin_riscv_v_sstsa16 ((a), (b)))
#define __riscv__v_rstsa16(a, b) \
  (__builtin_riscv_v_rstsa16 ((a), (b)))
#define __riscv__v_urstsa16(a, b) \
  (__builtin_riscv_v_urstsa16 ((a), (b)))
#define __riscv__v_kstsa16(a, b) \
  (__builtin_riscv_v_kstsa16 ((a), (b)))
#define __riscv__v_ukstsa16(a, b) \
  (__builtin_riscv_v_ukstsa16 ((a), (b)))
#define __riscv__v_uadd8(a, b) \
  (__builtin_riscv_v_uadd8 ((a), (b)))
#define __riscv__v_sadd8(a, b) \
  (__builtin_riscv_v_sadd8 ((a), (b)))
#define __riscv__v_radd8(a, b) \
  (__builtin_riscv_v_radd8 ((a), (b)))
#define __riscv__v_uradd8(a, b) \
  (__builtin_riscv_v_uradd8 ((a), (b)))
#define __riscv__v_kadd8(a, b) \
  (__builtin_riscv_v_kadd8 ((a), (b)))
#define __riscv__v_ukadd8(a, b) \
  (__builtin_riscv_v_ukadd8 ((a), (b)))
#define __riscv__v_usub8(a, b) \
  (__builtin_riscv_v_usub8 ((a), (b)))
#define __riscv__v_ssub8(a, b) \
  (__builtin_riscv_v_ssub8 ((a), (b)))
#define __riscv__v_rsub8(a, b) \
  (__builtin_riscv_v_rsub8 ((a), (b)))
#define __riscv__v_ursub8(a, b) \
  (__builtin_riscv_v_ursub8 ((a), (b)))
#define __riscv__v_ksub8(a, b) \
  (__builtin_riscv_v_ksub8 ((a), (b)))
#define __riscv__v_uksub8(a, b) \
  (__builtin_riscv_v_uksub8 ((a), (b)))
#define __riscv__v_sra16(a, b) \
  (__builtin_riscv_v_sra16 ((a), (b)))
#define __riscv__v_sra16_u(a, b) \
  (__builtin_riscv_v_sra16_u ((a), (b)))
#define __riscv__v_srl16(a, b) \
  (__builtin_riscv_v_srl16 ((a), (b)))
#define __riscv__v_srl16_u(a, b) \
  (__builtin_riscv_v_srl16_u ((a), (b)))
#define __riscv__v_sll16(a, b) \
  (__builtin_riscv_v_sll16 ((a), (b)))
#define __riscv__v_ksll16(a, b) \
  (__builtin_riscv_v_ksll16 ((a), (b)))
#define __riscv__v_kslra16(a, b) \
  (__builtin_riscv_v_kslra16 ((a), (b)))
#define __riscv__v_kslra16_u(a, b) \
  (__builtin_riscv_v_kslra16_u ((a), (b)))
#define __riscv__v_scmpeq16(a, b) \
  (__builtin_riscv_v_scmpeq16 ((a), (b)))
#define __riscv__v_ucmpeq16(a, b) \
  (__builtin_riscv_v_ucmpeq16 ((a), (b)))
#define __riscv__v_scmplt16(a, b) \
  (__builtin_riscv_v_scmplt16 ((a), (b)))
#define __riscv__v_scmple16(a, b) \
  (__builtin_riscv_v_scmple16 ((a), (b)))
#define __riscv__v_ucmplt16(a, b) \
  (__builtin_riscv_v_ucmplt16 ((a), (b)))
#define __riscv__v_ucmple16(a, b) \
  (__builtin_riscv_v_ucmple16 ((a), (b)))
#define __riscv__v_scmpeq8(a, b) \
  (__builtin_riscv_v_scmpeq8 ((a), (b)))
#define __riscv__v_ucmpeq8(a, b) \
  (__builtin_riscv_v_ucmpeq8 ((a), (b)))
#define __riscv__v_scmplt8(a, b) \
  (__builtin_riscv_v_scmplt8 ((a), (b)))
#define __riscv__v_scmple8(a, b) \
  (__builtin_riscv_v_scmple8 ((a), (b)))
#define __riscv__v_ucmplt8(a, b) \
  (__builtin_riscv_v_ucmplt8 ((a), (b)))
#define __riscv__v_ucmple8(a, b) \
  (__builtin_riscv_v_ucmple8 ((a), (b)))
#define __riscv__v_smin16(a, b) \
  (__builtin_riscv_v_smin16 ((a), (b)))
#define __riscv__v_umin16(a, b) \
  (__builtin_riscv_v_umin16 ((a), (b)))
#define __riscv__v_smax16(a, b) \
  (__builtin_riscv_v_smax16 ((a), (b)))
#define __riscv__v_umax16(a, b) \
  (__builtin_riscv_v_umax16 ((a), (b)))
#define __riscv__v_sclip16(a, b) \
  (__builtin_riscv_v_sclip16 ((a), (b)))
#define __riscv__v_uclip16(a, b) \
  (__builtin_riscv_v_uclip16 ((a), (b)))
#define __riscv__v_khm16(a, b) \
  (__builtin_riscv_v_khm16 ((a), (b)))
#define __riscv__v_khmx16(a, b) \
  (__builtin_riscv_v_khmx16 ((a), (b)))
#define __riscv__v_khm8(a, b) \
  (__builtin_riscv_v_khm8 ((a), (b)))
#define __riscv__v_khmx8(a, b) \
  (__builtin_riscv_v_khmx8 ((a), (b)))
#define __riscv__v_kabs16(a) \
  (__builtin_riscv_v_kabs16 ((a)))
#define __riscv__v_smul16(a, b) \
  (__builtin_riscv_v_smul16 ((a), (b)))
#define __riscv__v_smulx16(a, b) \
  (__builtin_riscv_v_smulx16 ((a), (b)))
#define __riscv__v_umul16(a, b) \
  (__builtin_riscv_v_umul16 ((a), (b)))
#define __riscv__v_umulx16(a, b) \
  (__builtin_riscv_v_umulx16 ((a), (b)))
#define __riscv__v_smul8(a, b) \
  (__builtin_riscv_v_smul8 ((a), (b)))
#define __riscv__v_smulx8(a, b) \
  (__builtin_riscv_v_smulx8 ((a), (b)))
#define __riscv__v_umul8(a, b) \
  (__builtin_riscv_v_umul8 ((a), (b)))
#define __riscv__v_umulx8(a, b) \
  (__builtin_riscv_v_umulx8 ((a), (b)))
#define __riscv__v_smin8(a, b) \
  (__builtin_riscv_v_smin8 ((a), (b)))
#define __riscv__v_umin8(a, b) \
  (__builtin_riscv_v_umin8 ((a), (b)))
#define __riscv__v_smax8(a, b) \
  (__builtin_riscv_v_smax8 ((a), (b)))
#define __riscv__v_umax8(a, b) \
  (__builtin_riscv_v_umax8 ((a), (b)))
#define __riscv__v_kabs8(a) \
  (__builtin_riscv_v_kabs8 ((a)))
#define __riscv__v_sunpkd810(a) \
  (__builtin_riscv_v_sunpkd810 ((a)))
#define __riscv__v_sunpkd820(a) \
  (__builtin_riscv_v_sunpkd820 ((a)))
#define __riscv__v_sunpkd830(a) \
  (__builtin_riscv_v_sunpkd830 ((a)))
#define __riscv__v_sunpkd831(a) \
  (__builtin_riscv_v_sunpkd831 ((a)))
#define __riscv__v_sunpkd832(a) \
  (__builtin_riscv_v_sunpkd832 ((a)))
#define __riscv__v_zunpkd810(a) \
  (__builtin_riscv_v_zunpkd810 ((a)))
#define __riscv__v_zunpkd820(a) \
  (__builtin_riscv_v_zunpkd820 ((a)))
#define __riscv__v_zunpkd830(a) \
  (__builtin_riscv_v_zunpkd830 ((a)))
#define __riscv__v_zunpkd831(a) \
  (__builtin_riscv_v_zunpkd831 ((a)))
#define __riscv__v_zunpkd832(a) \
  (__builtin_riscv_v_zunpkd832 ((a)))
#define __riscv__v_pkbb16(a, b) \
  (__builtin_riscv_v_pkbb16 ((a), (b)))
#define __riscv__v_pkbt16(a, b) \
  (__builtin_riscv_v_pkbt16 ((a), (b)))
#define __riscv__v_pktb16(a, b) \
  (__builtin_riscv_v_pktb16 ((a), (b)))
#define __riscv__v_pktt16(a, b) \
  (__builtin_riscv_v_pktt16 ((a), (b)))
#define __riscv__v_smmwb(a, b) \
  (__builtin_riscv_v_smmwb ((a), (b)))
#define __riscv__v_smmwb_u(a, b) \
  (__builtin_riscv_v_smmwb_u ((a), (b)))
#define __riscv__v_smmwt(a, b) \
  (__builtin_riscv_v_smmwt ((a), (b)))
#define __riscv__v_smmwt_u(a, b) \
  (__builtin_riscv_v_smmwt_u ((a), (b)))
#define __riscv__v_kmmwb2(a, b) \
  (__builtin_riscv_v_kmmwb2 ((a), (b)))
#define __riscv__v_kmmwb2_u(a, b) \
  (__builtin_riscv_v_kmmwb2_u ((a), (b)))
#define __riscv__v_kmmwt2(a, b) \
  (__builtin_riscv_v_kmmwt2 ((a), (b)))
#define __riscv__v_kmmwt2_u(a, b) \
  (__builtin_riscv_v_kmmwt2_u ((a), (b)))
#define __riscv__v_kmmawb(r, a, b) \
  (__builtin_riscv_v_kmmawb ((r), (a), (b)))
#define __riscv__v_kmmawb_u(r, a, b) \
  (__builtin_riscv_v_kmmawb_u ((r), (a), (b)))
#define __riscv__v_kmmawt(r, a, b) \
  (__builtin_riscv_v_kmmawt ((r), (a), (b)))
#define __riscv__v_kmmawt_u(r, a, b) \
  (__builtin_riscv_v_kmmawt_u ((r), (a), (b)))
#define __riscv__v_kmmawb2(r, a, b) \
  (__builtin_riscv_v_kmmawb2 ((r), (a), (b)))
#define __riscv__v_kmmawb2_u(r, a, b) \
  (__builtin_riscv_v_kmmawb2_u ((r), (a), (b)))
#define __riscv__v_kmmawt2(r, a, b) \
  (__builtin_riscv_v_kmmawt2 ((r), (a), (b)))
#define __riscv__v_kmmawt2_u(r, a, b) \
  (__builtin_riscv_v_kmmawt2_u ((r), (a), (b)))
#define __riscv__v_smbb16(a, b) \
  (__builtin_riscv_v_smbb16 ((a), (b)))
#define __riscv__v_smbt16(a, b) \
  (__builtin_riscv_v_smbt16 ((a), (b)))
#define __riscv__v_smtt16(a, b) \
  (__builtin_riscv_v_smtt16 ((a), (b)))
#define __riscv__v_kmda(a, b) \
  (__builtin_riscv_v_kmda ((a), (b)))
#define __riscv__v_kmxda(a, b) \
  (__builtin_riscv_v_kmxda ((a), (b)))
#define __riscv__v_smds(a, b) \
  (__builtin_riscv_v_smds ((a), (b)))
#define __riscv__v_smdrs(a, b) \
  (__builtin_riscv_v_smdrs ((a), (b)))
#define __riscv__v_smxds(a, b) \
  (__builtin_riscv_v_smxds ((a), (b)))
#define __riscv__v_kmabb(r, a, b) \
  (__builtin_riscv_v_kmabb ((r), (a), (b)))
#define __riscv__v_kmabt(r, a, b) \
  (__builtin_riscv_v_kmabt ((r), (a), (b)))
#define __riscv__v_kmatt(r, a, b) \
  (__builtin_riscv_v_kmatt ((r), (a), (b)))
#define __riscv__v_kmada(r, a, b) \
  (__builtin_riscv_v_kmada ((r), (a), (b)))
#define __riscv__v_kmaxda(r, a, b) \
  (__builtin_riscv_v_kmaxda ((r), (a), (b)))
#define __riscv__v_kmads(r, a, b) \
  (__builtin_riscv_v_kmads ((r), (a), (b)))
#define __riscv__v_kmadrs(r, a, b) \
  (__builtin_riscv_v_kmadrs ((r), (a), (b)))
#define __riscv__v_kmaxds(r, a, b) \
  (__builtin_riscv_v_kmaxds ((r), (a), (b)))
#define __riscv__v_kmsda(r, a, b) \
  (__builtin_riscv_v_kmsda ((r), (a), (b)))
#define __riscv__v_kmsxda(r, a, b) \
  (__builtin_riscv_v_kmsxda ((r), (a), (b)))
#define __riscv__v_smal(a, b) \
  (__builtin_riscv_v_smal ((a), (b)))
#define __riscv__v_smalbb(r, a, b) \
  (__builtin_riscv_v_smalbb ((r), (a), (b)))
#define __riscv__v_smalbt(r, a, b) \
  (__builtin_riscv_v_smalbt ((r), (a), (b)))
#define __riscv__v_smaltt(r, a, b) \
  (__builtin_riscv_v_smaltt ((r), (a), (b)))
#define __riscv__v_smalda(r, a, b) \
  (__builtin_riscv_v_smalda ((r), (a), (b)))
#define __riscv__v_smalxda(r, a, b) \
  (__builtin_riscv_v_smalxda ((r), (a), (b)))
#define __riscv__v_smalds(r, a, b) \
  (__builtin_riscv_v_smalds ((r), (a), (b)))
#define __riscv__v_smaldrs(r, a, b) \
  (__builtin_riscv_v_smaldrs ((r), (a), (b)))
#define __riscv__v_smalxds(r, a, b) \
  (__builtin_riscv_v_smalxds ((r), (a), (b)))
#define __riscv__v_smslda(r, a, b) \
  (__builtin_riscv_v_smslda ((r), (a), (b)))
#define __riscv__v_smslxda(r, a, b) \
  (__builtin_riscv_v_smslxda ((r), (a), (b)))
#define __riscv__v_sra8(a, b) \
  (__builtin_riscv_v_sra8 ((a), (b)))
#define __riscv__v_sra8_u(a, b) \
  (__builtin_riscv_v_sra8_u ((a), (b)))
#define __riscv__v_srl8(a, b) \
  (__builtin_riscv_v_srl8 ((a), (b)))
#define __riscv__v_srl8_u(a, b) \
  (__builtin_riscv_v_srl8_u ((a), (b)))
#define __riscv__v_sll8(a, b) \
  (__builtin_riscv_v_sll8 ((a), (b)))
#define __riscv__v_ksll8(a, b) \
  (__builtin_riscv_v_ksll8 ((a), (b)))
#define __riscv__v_kslra8(a, b) \
  (__builtin_riscv_v_kslra8 ((a), (b)))
#define __riscv__v_kslra8_u(a, b) \
  (__builtin_riscv_v_kslra8_u ((a), (b)))
#define __riscv__v_swap8(a) \
  (__builtin_riscv_v_swap8 ((a)))
#define __riscv__v_swap16(a) \
  (__builtin_riscv_v_pkbt16 ((a), (a)))
#define __riscv__v_sclip8(a, b) \
  (__builtin_riscv_v_sclip8 ((a), (b)))
#define __riscv__v_uclip8(a, b) \
  (__builtin_riscv_v_uclip8 ((a), (b)))
#define __riscv__v_kdmabb(r, a, b) \
  (__builtin_riscv_v_kdmabb ((r), (a), (b)))
#define __riscv__v_kdmabt(r, a, b) \
  (__builtin_riscv_v_kdmabt ((r), (a), (b)))
#define __riscv__v_kdmatt(r, a, b) \
  (__builtin_riscv_v_kdmatt ((r), (a), (b)))
#define __riscv__v_smaqa(r, a, b) \
  (__builtin_riscv_v_smaqa ((r), (a), (b)))
#define __riscv__v_umaqa(r, a, b) \
  (__builtin_riscv_v_umaqa ((r), (a), (b)))
#define __riscv__v_smaqa_su(r, a, b) \
  (__builtin_riscv_v_smaqa_su ((r), (a), (b)))
#define __riscv__v_clrs8(a) \
  (__builtin_riscv_v_clrs8 ((a)))
#define __riscv__v_clrs16(a) \
  (__builtin_riscv_v_clrs16 ((a)))
#define __riscv__v_clo8(a) \
  (__builtin_riscv_v_clo8 ((a)))
#define __riscv__v_clo16(a) \
  (__builtin_riscv_v_clo16 ((a)))
#define __riscv__v_clz8(a) \
  (__builtin_riscv_v_clz8 ((a)))
#define __riscv__v_clz16(a) \
  (__builtin_riscv_v_clz16 ((a)))
#define __riscv__v_kdmbb(a, b) \
  (__builtin_riscv_v_kdmbb ((a), (b)))
#define __riscv__v_kdmbt(a, b) \
  (__builtin_riscv_v_kdmbt ((a), (b)))
#define __riscv__v_kdmtt(a, b) \
  (__builtin_riscv_v_kdmtt ((a), (b)))
#define __riscv__v_khmbb(a, b) \
  (__builtin_riscv_v_khmbb ((a), (b)))
#define __riscv__v_khmbt(a, b) \
  (__builtin_riscv_v_khmbt ((a), (b)))
#define __riscv__v_khmtt(a, b) \
  (__builtin_riscv_v_khmtt ((a), (b)))
#define __riscv__v_pbsad(a, b) \
  (__builtin_riscv_v_pbsad ((a), (b)))
#define __riscv__v_pbsada(acc, a, b) \
  (__builtin_riscv_v_pbsada ((acc), (a), (b)))
#else
#define __riscv__v_smul16(a, b) \
  (__builtin_riscv_v_smul16 ((a), (b)))
#define __riscv__v_umul16(a, b) \
  (__builtin_riscv_v_umul16 ((a), (b)))
#define __riscv__v_smul8(a, b) \
  (__builtin_riscv_v_smul8 ((a), (b)))
#define __riscv__v_umul8(a, b) \
  (__builtin_riscv_v_umul8 ((a), (b)))
#define __riscv__v_smulx16(a, b) \
  (__builtin_riscv_v_smulx16 ((a), (b)))
#define __riscv__v_smulx8(a, b) \
  (__builtin_riscv_v_smulx8 ((a), (b)))
#define __riscv__v_umulx16(a, b) \
  (__builtin_riscv_v_umulx16 ((a), (b)))
#define __riscv__v_umulx8(a, b) \
  (__builtin_riscv_v_umulx8 ((a), (b)))
#define __riscv__v_uadd16(a, b) \
  (__builtin_riscv_v64_uadd16 ((a), (b)))
#define __riscv__v_sadd16(a, b) \
  (__builtin_riscv_v64_sadd16 ((a), (b)))
#define __riscv__v_radd16(a, b) \
  (__builtin_riscv_v64_radd16 ((a), (b)))
#define __riscv__v_uradd16(a, b) \
  (__builtin_riscv_v64_uradd16 ((a), (b)))
#define __riscv__v_kadd16(a, b) \
  (__builtin_riscv_v64_kadd16 ((a), (b)))
#define __riscv__v_ukadd16(a, b) \
  (__builtin_riscv_v64_ukadd16 ((a), (b)))
#define __riscv__v_usub16(a, b) \
  (__builtin_riscv_v64_usub16 ((a), (b)))
#define __riscv__v_ssub16(a, b) \
  (__builtin_riscv_v64_ssub16 ((a), (b)))
#define __riscv__v_rsub16(a, b) \
  (__builtin_riscv_v64_rsub16 ((a), (b)))
#define __riscv__v_ursub16(a, b) \
  (__builtin_riscv_v64_ursub16 ((a), (b)))
#define __riscv__v_ksub16(a, b) \
  (__builtin_riscv_v64_ksub16 ((a), (b)))
#define __riscv__v_uksub16(a, b) \
  (__builtin_riscv_v64_uksub16 ((a), (b)))
#define __riscv__v_ucras16(a, b) \
  (__builtin_riscv_v64_ucras16 ((a), (b)))
#define __riscv__v_scras16(a, b) \
  (__builtin_riscv_v64_scras16 ((a), (b)))
#define __riscv__v_rcras16(a, b) \
  (__builtin_riscv_v64_rcras16 ((a), (b)))
#define __riscv__v_urcras16(a, b) \
  (__builtin_riscv_v64_urcras16 ((a), (b)))
#define __riscv__v_kcras16(a, b) \
  (__builtin_riscv_v64_kcras16 ((a), (b)))
#define __riscv__v_ukcras16(a, b) \
  (__builtin_riscv_v64_ukcras16 ((a), (b)))
#define __riscv__v_ucrsa16(a, b) \
  (__builtin_riscv_v64_ucrsa16 ((a), (b)))
#define __riscv__v_scrsa16(a, b) \
  (__builtin_riscv_v64_scrsa16 ((a), (b)))
#define __riscv__v_rcrsa16(a, b) \
  (__builtin_riscv_v64_rcrsa16 ((a), (b)))
#define __riscv__v_urcrsa16(a, b) \
  (__builtin_riscv_v64_urcrsa16 ((a), (b)))
#define __riscv__v_kcrsa16(a, b) \
  (__builtin_riscv_v64_kcrsa16 ((a), (b)))
#define __riscv__v_ukcrsa16(a, b) \
  (__builtin_riscv_v64_ukcrsa16 ((a), (b)))
#define __riscv__v_ustas16(a, b) \
  (__builtin_riscv_v64_ustas16 ((a), (b)))
#define __riscv__v_sstas16(a, b) \
  (__builtin_riscv_v64_sstas16 ((a), (b)))
#define __riscv__v_rstas16(a, b) \
  (__builtin_riscv_v64_rstas16 ((a), (b)))
#define __riscv__v_urstas16(a, b) \
  (__builtin_riscv_v64_urstas16 ((a), (b)))
#define __riscv__v_kstas16(a, b) \
  (__builtin_riscv_v64_kstas16 ((a), (b)))
#define __riscv__v_ukstas16(a, b) \
  (__builtin_riscv_v64_ukstas16 ((a), (b)))
#define __riscv__v_ustsa16(a, b) \
  (__builtin_riscv_v64_ustsa16 ((a), (b)))
#define __riscv__v_sstsa16(a, b) \
  (__builtin_riscv_v64_sstsa16 ((a), (b)))
#define __riscv__v_rstsa16(a, b) \
  (__builtin_riscv_v64_rstsa16 ((a), (b)))
#define __riscv__v_urstsa16(a, b) \
  (__builtin_riscv_v64_urstsa16 ((a), (b)))
#define __riscv__v_kstsa16(a, b) \
  (__builtin_riscv_v64_kstsa16 ((a), (b)))
#define __riscv__v_ukstsa16(a, b) \
  (__builtin_riscv_v64_ukstsa16 ((a), (b)))
#define __riscv__v_uadd8(a, b) \
  (__builtin_riscv_v64_uadd8 ((a), (b)))
#define __riscv__v_sadd8(a, b) \
  (__builtin_riscv_v64_sadd8 ((a), (b)))
#define __riscv__v_radd8(a, b) \
  (__builtin_riscv_v64_radd8 ((a), (b)))
#define __riscv__v_uradd8(a, b) \
  (__builtin_riscv_v64_uradd8 ((a), (b)))
#define __riscv__v_kadd8(a, b) \
  (__builtin_riscv_v64_kadd8 ((a), (b)))
#define __riscv__v_ukadd8(a, b) \
  (__builtin_riscv_v64_ukadd8 ((a), (b)))
#define __riscv__v_usub8(a, b) \
  (__builtin_riscv_v64_usub8 ((a), (b)))
#define __riscv__v_ssub8(a, b) \
  (__builtin_riscv_v64_ssub8 ((a), (b)))
#define __riscv__v_rsub8(a, b) \
  (__builtin_riscv_v64_rsub8 ((a), (b)))
#define __riscv__v_ursub8(a, b) \
  (__builtin_riscv_v64_ursub8 ((a), (b)))
#define __riscv__v_ksub8(a, b) \
  (__builtin_riscv_v64_ksub8 ((a), (b)))
#define __riscv__v_uksub8(a, b) \
  (__builtin_riscv_v64_uksub8 ((a), (b)))
#define __riscv__v_sra16(a, b) \
  (__builtin_riscv_v64_sra16 ((a), (b)))
#define __riscv__v_sra16_u(a, b) \
  (__builtin_riscv_v64_sra16_u ((a), (b)))
#define __riscv__v_srl16(a, b) \
  (__builtin_riscv_v64_srl16 ((a), (b)))
#define __riscv__v_srl16_u(a, b) \
  (__builtin_riscv_v64_srl16_u ((a), (b)))
#define __riscv__v_sll16(a, b) \
  (__builtin_riscv_v64_sll16 ((a), (b)))
#define __riscv__v_ksll16(a, b) \
  (__builtin_riscv_v64_ksll16 ((a), (b)))
#define __riscv__v_kslra16(a, b) \
  (__builtin_riscv_v64_kslra16 ((a), (b)))
#define __riscv__v_kslra16_u(a, b) \
  (__builtin_riscv_v64_kslra16_u ((a), (b)))
#define __riscv__v_scmpeq16(a, b) \
  (__builtin_riscv_v64_scmpeq16 ((a), (b)))
#define __riscv__v_ucmpeq16(a, b) \
  (__builtin_riscv_v64_ucmpeq16 ((a), (b)))
#define __riscv__v_scmplt16(a, b) \
  (__builtin_riscv_v64_scmplt16 ((a), (b)))
#define __riscv__v_scmple16(a, b) \
  (__builtin_riscv_v64_scmple16 ((a), (b)))
#define __riscv__v_ucmplt16(a, b) \
  (__builtin_riscv_v64_ucmplt16 ((a), (b)))
#define __riscv__v_ucmple16(a, b) \
  (__builtin_riscv_v64_ucmple16 ((a), (b)))
#define __riscv__v_scmpeq8(a, b) \
  (__builtin_riscv_v64_scmpeq8 ((a), (b)))
#define __riscv__v_ucmpeq8(a, b) \
  (__builtin_riscv_v64_ucmpeq8 ((a), (b)))
#define __riscv__v_scmplt8(a, b) \
  (__builtin_riscv_v64_scmplt8 ((a), (b)))
#define __riscv__v_scmple8(a, b) \
  (__builtin_riscv_v64_scmple8 ((a), (b)))
#define __riscv__v_ucmplt8(a, b) \
  (__builtin_riscv_v64_ucmplt8 ((a), (b)))
#define __riscv__v_ucmple8(a, b) \
  (__builtin_riscv_v64_ucmple8 ((a), (b)))
#define __riscv__v_smin16(a, b) \
  (__builtin_riscv_v64_smin16 ((a), (b)))
#define __riscv__v_umin16(a, b) \
  (__builtin_riscv_v64_umin16 ((a), (b)))
#define __riscv__v_smax16(a, b) \
  (__builtin_riscv_v64_smax16 ((a), (b)))
#define __riscv__v_umax16(a, b) \
  (__builtin_riscv_v64_umax16 ((a), (b)))
#define __riscv__v_sclip16(a, b) \
  (__builtin_riscv_v64_sclip16 ((a), (b)))
#define __riscv__v_uclip16(a, b) \
  (__builtin_riscv_v64_uclip16 ((a), (b)))
#define __riscv__v_khm16(a, b) \
  (__builtin_riscv_v64_khm16 ((a), (b)))
#define __riscv__v_khmx16(a, b) \
  (__builtin_riscv_v64_khmx16 ((a), (b)))
#define __riscv__v_khm8(a, b) \
  (__builtin_riscv_v64_khm8 ((a), (b)))
#define __riscv__v_khmx8(a, b) \
  (__builtin_riscv_v64_khmx8 ((a), (b)))
#define __riscv__v_kabs16(a) \
  (__builtin_riscv_v64_kabs16 ((a)))
#define __riscv__v_smul16(a, b) \
  (__builtin_riscv_v_smul16 ((a), (b)))
#define __riscv__v_smulx16(a, b) \
  (__builtin_riscv_v_smulx16 ((a), (b)))
#define __riscv__v_umul16(a, b) \
  (__builtin_riscv_v_umul16 ((a), (b)))
#define __riscv__v_umulx16(a, b) \
  (__builtin_riscv_v_umulx16 ((a), (b)))
#define __riscv__v_smul8(a, b) \
  (__builtin_riscv_v_smul8 ((a), (b)))
#define __riscv__v_smulx8(a, b) \
  (__builtin_riscv_v_smulx8 ((a), (b)))
#define __riscv__v_umul8(a, b) \
  (__builtin_riscv_v_umul8 ((a), (b)))
#define __riscv__v_umulx8(a, b) \
  (__builtin_riscv_v_umulx8 ((a), (b)))
#define __riscv__v_smin8(a, b) \
  (__builtin_riscv_v64_smin8 ((a), (b)))
#define __riscv__v_umin8(a, b) \
  (__builtin_riscv_v64_umin8 ((a), (b)))
#define __riscv__v_smax8(a, b) \
  (__builtin_riscv_v64_smax8 ((a), (b)))
#define __riscv__v_umax8(a, b) \
  (__builtin_riscv_v64_umax8 ((a), (b)))
#define __riscv__v_kabs8(a) \
  (__builtin_riscv_v64_kabs8 ((a)))
#define __riscv__v_sunpkd810(a) \
  (__builtin_riscv_v64_sunpkd810 ((a)))
#define __riscv__v_sunpkd820(a) \
  (__builtin_riscv_v64_sunpkd820 ((a)))
#define __riscv__v_sunpkd830(a) \
  (__builtin_riscv_v64_sunpkd830 ((a)))
#define __riscv__v_sunpkd831(a) \
  (__builtin_riscv_v64_sunpkd831 ((a)))
#define __riscv__v_sunpkd832(a) \
  (__builtin_riscv_v64_sunpkd832 ((a)))
#define __riscv__v_zunpkd810(a) \
  (__builtin_riscv_v64_zunpkd810 ((a)))
#define __riscv__v_zunpkd820(a) \
  (__builtin_riscv_v64_zunpkd820 ((a)))
#define __riscv__v_zunpkd830(a) \
  (__builtin_riscv_v64_zunpkd830 ((a)))
#define __riscv__v_zunpkd831(a) \
  (__builtin_riscv_v64_zunpkd831 ((a)))
#define __riscv__v_zunpkd832(a) \
  (__builtin_riscv_v64_zunpkd832 ((a)))
#define __riscv__v_pkbb16(a, b) \
  (__builtin_riscv_v64_pkbb16 ((a), (b)))
#define __riscv__v_pkbt16(a, b) \
  (__builtin_riscv_v64_pkbt16 ((a), (b)))
#define __riscv__v_pktb16(a, b) \
  (__builtin_riscv_v64_pktb16 ((a), (b)))
#define __riscv__v_pktt16(a, b) \
  (__builtin_riscv_v64_pktt16 ((a), (b)))
#define __riscv__v_smmwb(a, b) \
  (__builtin_riscv_v64_smmwb ((a), (b)))
#define __riscv__v_smmwb_u(a, b) \
  (__builtin_riscv_v64_smmwb_u ((a), (b)))
#define __riscv__v_smmwt(a, b) \
  (__builtin_riscv_v64_smmwt ((a), (b)))
#define __riscv__v_smmwt_u(a, b) \
  (__builtin_riscv_v64_smmwt_u ((a), (b)))
#define __riscv__v_kmmwb2(a, b) \
  (__builtin_riscv_v64_kmmwb2 ((a), (b)))
#define __riscv__v_kmmwb2_u(a, b) \
  (__builtin_riscv_v64_kmmwb2_u ((a), (b)))
#define __riscv__v_kmmwt2(a, b) \
  (__builtin_riscv_v64_kmmwt2 ((a), (b)))
#define __riscv__v_kmmwt2_u(a, b) \
  (__builtin_riscv_v64_kmmwt2_u ((a), (b)))
#define __riscv__v_kmmawb(r, a, b) \
  (__builtin_riscv_v64_kmmawb ((r), (a), (b)))
#define __riscv__v_kmmawb_u(r, a, b) \
  (__builtin_riscv_v64_kmmawb_u ((r), (a), (b)))
#define __riscv__v_kmmawt(r, a, b) \
  (__builtin_riscv_v64_kmmawt ((r), (a), (b)))
#define __riscv__v_kmmawt_u(r, a, b) \
  (__builtin_riscv_v64_kmmawt_u ((r), (a), (b)))
#define __riscv__v_kmmawb2(r, a, b) \
  (__builtin_riscv_v64_kmmawb2 ((r), (a), (b)))
#define __riscv__v_kmmawb2_u(r, a, b) \
  (__builtin_riscv_v64_kmmawb2_u ((r), (a), (b)))
#define __riscv__v_kmmawt2(r, a, b) \
  (__builtin_riscv_v64_kmmawt2 ((r), (a), (b)))
#define __riscv__v_kmmawt2_u(r, a, b) \
  (__builtin_riscv_v64_kmmawt2_u ((r), (a), (b)))
#define __riscv__v_smbb16(a, b) \
  (__builtin_riscv_v64_smbb16 ((a), (b)))
#define __riscv__v_smbt16(a, b) \
  (__builtin_riscv_v64_smbt16 ((a), (b)))
#define __riscv__v_smtt16(a, b) \
  (__builtin_riscv_v64_smtt16 ((a), (b)))
#define __riscv__v_kmda(a, b) \
  (__builtin_riscv_v64_kmda ((a), (b)))
#define __riscv__v_kmxda(a, b) \
  (__builtin_riscv_v64_kmxda ((a), (b)))
#define __riscv__v_smds(a, b) \
  (__builtin_riscv_v64_smds ((a), (b)))
#define __riscv__v_smdrs(a, b) \
  (__builtin_riscv_v64_smdrs ((a), (b)))
#define __riscv__v_smxds(a, b) \
  (__builtin_riscv_v64_smxds ((a), (b)))
#define __riscv__v_kmabb(r, a, b) \
  (__builtin_riscv_v64_kmabb ((r), (a), (b)))
#define __riscv__v_kmabt(r, a, b) \
  (__builtin_riscv_v64_kmabt ((r), (a), (b)))
#define __riscv__v_kmatt(r, a, b) \
  (__builtin_riscv_v64_kmatt ((r), (a), (b)))
#define __riscv__v_kmada(r, a, b) \
  (__builtin_riscv_v64_kmada ((r), (a), (b)))
#define __riscv__v_kmaxda(r, a, b) \
  (__builtin_riscv_v64_kmaxda ((r), (a), (b)))
#define __riscv__v_kmads(r, a, b) \
  (__builtin_riscv_v64_kmads ((r), (a), (b)))
#define __riscv__v_kmadrs(r, a, b) \
  (__builtin_riscv_v64_kmadrs ((r), (a), (b)))
#define __riscv__v_kmaxds(r, a, b) \
  (__builtin_riscv_v64_kmaxds ((r), (a), (b)))
#define __riscv__v_kmsda(r, a, b) \
  (__builtin_riscv_v64_kmsda ((r), (a), (b)))
#define __riscv__v_kmsxda(r, a, b) \
  (__builtin_riscv_v64_kmsxda ((r), (a), (b)))
#define __riscv__v_smal(a, b) \
  (__builtin_riscv_v64_smal ((a), (b)))
#define __riscv__v_smalbb(r, a, b) \
  (__builtin_riscv_v64_smalbb ((r), (a), (b)))
#define __riscv__v_smalbt(r, a, b) \
  (__builtin_riscv_v64_smalbt ((r), (a), (b)))
#define __riscv__v_smaltt(r, a, b) \
  (__builtin_riscv_v64_smaltt ((r), (a), (b)))
#define __riscv__v_smalda(r, a, b) \
  (__builtin_riscv_v64_smalda ((r), (a), (b)))
#define __riscv__v_smalxda(r, a, b) \
  (__builtin_riscv_v64_smalxda ((r), (a), (b)))
#define __riscv__v_smalds(r, a, b) \
  (__builtin_riscv_v64_smalds ((r), (a), (b)))
#define __riscv__v_smaldrs(r, a, b) \
  (__builtin_riscv_v64_smaldrs ((r), (a), (b)))
#define __riscv__v_smalxds(r, a, b) \
  (__builtin_riscv_v64_smalxds ((r), (a), (b)))
#define __riscv__v_smslda(r, a, b) \
  (__builtin_riscv_v64_smslda ((r), (a), (b)))
#define __riscv__v_smslxda(r, a, b) \
  (__builtin_riscv_v64_smslxda ((r), (a), (b)))
#define __riscv__v_sra8(a, b) \
  (__builtin_riscv_v64_sra8 ((a), (b)))
#define __riscv__v_sra8_u(a, b) \
  (__builtin_riscv_v64_sra8_u ((a), (b)))
#define __riscv__v_srl8(a, b) \
  (__builtin_riscv_v64_srl8 ((a), (b)))
#define __riscv__v_srl8_u(a, b) \
  (__builtin_riscv_v64_srl8_u ((a), (b)))
#define __riscv__v_sll8(a, b) \
  (__builtin_riscv_v64_sll8 ((a), (b)))
#define __riscv__v_ksll8(a, b) \
  (__builtin_riscv_v64_ksll8 ((a), (b)))
#define __riscv__v_kslra8(a, b) \
  (__builtin_riscv_v64_kslra8 ((a), (b)))
#define __riscv__v_kslra8_u(a, b) \
  (__builtin_riscv_v64_kslra8_u ((a), (b)))
#define __riscv__v_sclip8(a, b) \
  (__builtin_riscv_v64_sclip8 ((a), (b)))
#define __riscv__v_uclip8(a, b) \
  (__builtin_riscv_v64_uclip8 ((a), (b)))
#define __riscv__v_uadd32(a, b) \
  (__builtin_riscv_v64_uadd32 ((a), (b)))
#define __riscv__v_sadd32(a, b) \
  (__builtin_riscv_v64_sadd32 ((a), (b)))
#define __riscv__v_radd32(a, b) \
  (__builtin_riscv_v64_radd32 ((a), (b)))
#define __riscv__v_uradd32(a, b) \
  (__builtin_riscv_v64_uradd32 ((a), (b)))
#define __riscv__v_kadd32(a, b) \
  (__builtin_riscv_v64_kadd32 ((a), (b)))
#define __riscv__v_ukadd32(a, b) \
  (__builtin_riscv_v64_ukadd32 ((a), (b)))
#define __riscv__v_usub32(a, b) \
  (__builtin_riscv_v64_usub32 ((a), (b)))
#define __riscv__v_ssub32(a, b) \
  (__builtin_riscv_v64_ssub32 ((a), (b)))
#define __riscv__v_rsub32(a, b) \
  (__builtin_riscv_v64_rsub32 ((a), (b)))
#define __riscv__v_ursub32(a, b) \
  (__builtin_riscv_v64_ursub32 ((a), (b)))
#define __riscv__v_ksub32(a, b) \
  (__builtin_riscv_v64_ksub32 ((a), (b)))
#define __riscv__v_uksub32(a, b) \
  (__builtin_riscv_v64_uksub32 ((a), (b)))
#define __riscv__v_ucras32(a, b) \
  (__builtin_riscv_v64_ucras32 ((a), (b)))
#define __riscv__v_scras32(a, b) \
  (__builtin_riscv_v64_scras32 ((a), (b)))
#define __riscv__v_ucrsa32(a, b) \
  (__builtin_riscv_v64_ucrsa32 ((a), (b)))
#define __riscv__v_scrsa32(a, b) \
  (__builtin_riscv_v64_scrsa32 ((a), (b)))
#define __riscv__v_rcras32(a, b) \
  (__builtin_riscv_v64_rcras32 ((a), (b)))
#define __riscv__v_rcrsa32(a, b) \
  (__builtin_riscv_v64_rcrsa32 ((a), (b)))
#define __riscv__v_urcras32(a, b) \
  (__builtin_riscv_v64_urcras32 ((a), (b)))
#define __riscv__v_urcrsa32(a, b) \
  (__builtin_riscv_v64_urcrsa32 ((a), (b)))
#define __riscv__v_kcras32(a, b) \
  (__builtin_riscv_v64_kcras32 ((a), (b)))
#define __riscv__v_kcrsa32(a, b) \
  (__builtin_riscv_v64_kcrsa32 ((a), (b)))
#define __riscv__v_ukcras32(a, b) \
  (__builtin_riscv_v64_ukcras32 ((a), (b)))
#define __riscv__v_ukcrsa32(a, b) \
  (__builtin_riscv_v64_ukcrsa32 ((a), (b)))
#define __riscv__v_ustas32(a, b) \
  (__builtin_riscv_v64_ustas32 ((a), (b)))
#define __riscv__v_sstas32(a, b) \
  (__builtin_riscv_v64_sstas32 ((a), (b)))
#define __riscv__v_ustsa32(a, b) \
  (__builtin_riscv_v64_ustsa32 ((a), (b)))
#define __riscv__v_sstsa32(a, b) \
  (__builtin_riscv_v64_sstsa32 ((a), (b)))
#define __riscv__v_rstas32(a, b) \
  (__builtin_riscv_v64_rstas32 ((a), (b)))
#define __riscv__v_rstsa32(a, b) \
  (__builtin_riscv_v64_rstsa32 ((a), (b)))
#define __riscv__v_urstas32(a, b) \
  (__builtin_riscv_v64_urstas32 ((a), (b)))
#define __riscv__v_urstsa32(a, b) \
  (__builtin_riscv_v64_urstsa32 ((a), (b)))
#define __riscv__v_kstas32(a, b) \
  (__builtin_riscv_v64_kstas32 ((a), (b)))
#define __riscv__v_kstsa32(a, b) \
  (__builtin_riscv_v64_kstsa32 ((a), (b)))
#define __riscv__v_ukstas32(a, b) \
  (__builtin_riscv_v64_ukstas32 ((a), (b)))
#define __riscv__v_ukstsa32(a, b) \
  (__builtin_riscv_v64_ukstsa32 ((a), (b)))
#define __riscv__v_sra32(a, b) \
  (__builtin_riscv_v64_sra32 ((a), (b)))
#define __riscv__v_sra32_u(a, b) \
  (__builtin_riscv_v64_sra32_u ((a), (b)))
#define __riscv__v_srl32(a, b) \
  (__builtin_riscv_v64_srl32 ((a), (b)))
#define __riscv__v_srl32_u(a, b) \
  (__builtin_riscv_v64_srl32_u ((a), (b)))
#define __riscv__v_sll32(a, b) \
  (__builtin_riscv_v64_sll32 ((a), (b)))
#define __riscv__v_ksll32(a, b) \
  (__builtin_riscv_v64_ksll32 ((a), (b)))
#define __riscv__v_kslra32(a, b) \
  (__builtin_riscv_v64_kslra32 ((a), (b)))
#define __riscv__v_kslra32_u(a, b) \
  (__builtin_riscv_v64_kslra32_u ((a), (b)))
#define __riscv__v_smin32(a, b) \
  (__builtin_riscv_v64_smin32 ((a), (b)))
#define __riscv__v_umin32(a, b) \
  (__builtin_riscv_v64_umin32 ((a), (b)))
#define __riscv__v_smax32(a, b) \
  (__builtin_riscv_v64_smax32 ((a), (b)))
#define __riscv__v_umax32(a, b) \
  (__builtin_riscv_v64_umax32 ((a), (b)))
#define __riscv__v_kabs32(a) \
  (__builtin_riscv_v64_kabs32 ((a)))
#define __riscv__v_khmbb16(a, b) \
  (__builtin_riscv_v64_khmbb16 ((a), (b)))
#define __riscv__v_khmbt16(a, b) \
  (__builtin_riscv_v64_khmbt16 ((a), (b)))
#define __riscv__v_khmtt16(a, b) \
  (__builtin_riscv_v64_khmtt16 ((a), (b)))
#define __riscv__v_kdmbb16(a, b) \
  (__builtin_riscv_v64_kdmbb16 ((a), (b)))
#define __riscv__v_kdmbt16(a, b) \
  (__builtin_riscv_v64_kdmbt16 ((a), (b)))
#define __riscv__v_kdmtt16(a, b) \
  (__builtin_riscv_v64_kdmtt16 ((a), (b)))
#define __riscv__v_smbb32(a, b) \
  (__builtin_riscv_v64_smbb32 ((a), (b)))
#define __riscv__v_smbt32(a, b) \
  (__builtin_riscv_v64_smbt32 ((a), (b)))
#define __riscv__v_smtt32(a, b) \
  (__builtin_riscv_v64_smtt32 ((a), (b)))
#define __riscv__v_kmabb32(r, a, b) \
  (__builtin_riscv_v64_kmabb32 ((r), (a), (b)))
#define __riscv__v_kmabt32(r, a, b) \
  (__builtin_riscv_v64_kmabt32 ((r), (a), (b)))
#define __riscv__v_kmatt32(r, a, b) \
  (__builtin_riscv_v64_kmatt32 ((r), (a), (b)))
#define __riscv__v_kmda32(a, b) \
  (__builtin_riscv_v64_kmda32 ((a), (b)))
#define __riscv__v_kmxda32(a, b) \
  (__builtin_riscv_v64_kmxda32 ((a), (b)))
#define __riscv__v_kmada32(r, a, b) \
  (__builtin_riscv_v64_kmada32 ((r), (a), (b)))
#define __riscv__v_kmaxda32(r, a, b) \
  (__builtin_riscv_v64_kmaxda32 ((r), (a), (b)))
#define __riscv__v_kmads32(r, a, b) \
  (__builtin_riscv_v64_kmads32 ((r), (a), (b)))
#define __riscv__v_kmadrs32(r, a, b) \
  (__builtin_riscv_v64_kmadrs32 ((r), (a), (b)))
#define __riscv__v_kmaxds32(r, a, b) \
  (__builtin_riscv_v64_kmaxds32 ((r), (a), (b)))
#define __riscv__v_kmsda32(r, a, b) \
  (__builtin_riscv_v64_kmsda32 ((r), (a), (b)))
#define __riscv__v_kmsxda32(r, a, b) \
  (__builtin_riscv_v64_kmsxda32 ((r), (a), (b)))
#define __riscv__v_smds32(a, b) \
  (__builtin_riscv_v64_smds32 ((a), (b)))
#define __riscv__v_smdrs32(a, b) \
  (__builtin_riscv_v64_smdrs32 ((a), (b)))
#define __riscv__v_smxds32(a, b) \
  (__builtin_riscv_v64_smxds32 ((a), (b)))
#define __riscv__v_kdmabb(r, a, b) \
  (__builtin_riscv_v64_kdmabb ((r), (a), (b)))
#define __riscv__v_kdmabt(r, a, b) \
  (__builtin_riscv_v64_kdmabt ((r), (a), (b)))
#define __riscv__v_kdmatt(r, a, b) \
  (__builtin_riscv_v64_kdmatt ((r), (a), (b)))
#define __riscv__v_kdmabb16(r, a, b) \
  (__builtin_riscv_v64_kdmabb16 ((r), (a), (b)))
#define __riscv__v_kdmabt16(r, a, b) \
  (__builtin_riscv_v64_kdmabt16 ((r), (a), (b)))
#define __riscv__v_kdmatt16(r, a, b) \
  (__builtin_riscv_v64_kdmatt16 ((r), (a), (b)))
#define __riscv__v_smaqa(r, a, b) \
  (__builtin_riscv_v64_smaqa ((r), (a), (b)))
#define __riscv__v_umaqa(r, a, b) \
  (__builtin_riscv_v64_umaqa ((r), (a), (b)))
#define __riscv__v_smaqa_su(r, a, b) \
  (__builtin_riscv_v64_smaqa_su ((r), (a), (b)))
#define __riscv__v_clrs8(a) \
  (__builtin_riscv_v64_clrs8 ((a)))
#define __riscv__v_clrs16(a) \
  (__builtin_riscv_v64_clrs16 ((a)))
#define __riscv__v_clrs32(a) \
  (__builtin_riscv_v64_clrs32 ((a)))
#define __riscv__v_clo8(a) \
  (__builtin_riscv_v64_clo8 ((a)))
#define __riscv__v_clo16(a) \
  (__builtin_riscv_v64_clo16 ((a)))
#define __riscv__v_clo32(a) \
  (__builtin_riscv_v64_clo32 ((a)))
#define __riscv__v_clz8(a) \
  (__builtin_riscv_v64_clz8 ((a)))
#define __riscv__v_clz16(a) \
  (__builtin_riscv_v64_clz16 ((a)))
#define __riscv__v_clz32(a) \
  (__builtin_riscv_v64_clz32 ((a)))
#define __riscv__v_swap8(a) \
  (__builtin_riscv_v64_swap8 ((a)))
#define __riscv__v_swap16(a) \
  (__builtin_riscv_v64_pkbt16 ((a), (a)))
#define __riscv__v_pkbb32(a, b) \
  (__builtin_riscv_v64_pkbb32 ((a), (b)))
#define __riscv__v_pkbt32(a, b) \
  (__builtin_riscv_v64_pkbt32 ((a), (b)))
#define __riscv__v_pktb32(a, b) \
  (__builtin_riscv_v64_pktb32 ((a), (b)))
#define __riscv__v_pktt32(a, b) \
  (__builtin_riscv_v64_pktt32 ((a), (b)))
#define __riscv__v_kdmbb(a, b) \
  (__builtin_riscv_v64_kdmbb ((a), (b)))
#define __riscv__v_kdmbt(a, b) \
  (__builtin_riscv_v64_kdmbt ((a), (b)))
#define __riscv__v_kdmtt(a, b) \
  (__builtin_riscv_v64_kdmtt ((a), (b)))
#define __riscv__v_khmbb(a, b) \
  (__builtin_riscv_v64_khmbb ((a), (b)))
#define __riscv__v_khmbt(a, b) \
  (__builtin_riscv_v64_khmbt ((a), (b)))
#define __riscv__v_khmtt(a, b) \
  (__builtin_riscv_v64_khmtt ((a), (b)))
#define __riscv__v_smmul(a, b) \
  (__builtin_riscv_v64_smmul ((a), (b)))
#define __riscv__v_smmul_u(a, b) \
  (__builtin_riscv_v64_smmul_u ((a), (b)))
#define __riscv__v_kwmmul(a, b) \
  (__builtin_riscv_v64_kwmmul ((a), (b)))
#define __riscv__v_kwmmul_u(a, b) \
  (__builtin_riscv_v64_kwmmul_u ((a), (b)))
#define __riscv__v_kmmac(r, a, b) \
  (__builtin_riscv_v64_kmmac ((r), (a), (b)))
#define __riscv__v_kmmac_u(r, a, b) \
  (__builtin_riscv_v64_kmmac_u ((r), (a), (b)))
#define __riscv__v_kmmsb(r, a, b) \
  (__builtin_riscv_v64_kmmsb ((r), (a), (b)))
#define __riscv__v_kmmsb_u(r, a, b) \
  (__builtin_riscv_v64_kmmsb_u ((r), (a), (b)))
#define __riscv__v_uclip32(a, imm) \
  (__builtin_riscv_v64_uclip32 ((a), (imm)))
#define __riscv__v_sclip32(a, imm) \
  (__builtin_riscv_v64_sclip32 ((a), (imm)))
#define __riscv__v_pbsad(a, b) \
  (__builtin_riscv_v64_pbsad ((a), (b)))
#define __riscv__v_pbsada(acc, a, b) \
  (__builtin_riscv_v64_pbsada ((acc), (a), (b)))
#define __riscv__v_smar64(r, a, b) \
  (__builtin_riscv_v64_smar64 ((r), (a), (b)))
#define __riscv__v_smsr64(r, a, b) \
  (__builtin_riscv_v64_smsr64 ((r), (a), (b)))
#define __riscv__v_umar64(r, a, b) \
  (__builtin_riscv_v64_umar64 ((r), (a), (b)))
#define __riscv__v_umsr64(r, a, b) \
  (__builtin_riscv_v64_umsr64 ((r), (a), (b)))
#define __riscv__v_kmar64(r, a, b) \
  (__builtin_riscv_v64_kmar64 ((r), (a), (b)))
#define __riscv__v_kmsr64(r, a, b) \
  (__builtin_riscv_v64_kmsr64 ((r), (a), (b)))
#define __riscv__v_ukmar64(r, a, b) \
  (__builtin_riscv_v64_ukmar64 ((r), (a), (b)))
#define __riscv__v_ukmsr64(r, a, b) \
  (__builtin_riscv_v64_ukmsr64 ((r), (a), (b)))
#define vec64_all_eq(type, size, vec1, vec2) \
    (__builtin_riscv_vec_ ##type##cmpeq ##size (vec1, vec2) == 0xffffffffffffffffull)
#endif

#define __rv__add16 __riscv__add16
#define __rv__radd16 __riscv__radd16
#define __rv__uradd16 __riscv__uradd16
#define __rv__kadd16 __riscv__kadd16
#define __rv__ukadd16 __riscv__ukadd16
#define __rv__sub16 __riscv__sub16
#define __rv__rsub16 __riscv__rsub16
#define __rv__ursub16 __riscv__ursub16
#define __rv__ksub16 __riscv__ksub16
#define __rv__uksub16 __riscv__uksub16
#define __rv__cras16 __riscv__cras16
#define __rv__rcras16 __riscv__rcras16
#define __rv__urcras16 __riscv__urcras16
#define __rv__kcras16 __riscv__kcras16
#define __rv__ukcras16 __riscv__ukcras16
#define __rv__crsa16 __riscv__crsa16
#define __rv__rcrsa16 __riscv__rcrsa16
#define __rv__urcrsa16 __riscv__urcrsa16
#define __rv__kcrsa16 __riscv__kcrsa16
#define __rv__ukcrsa16 __riscv__ukcrsa16
#define __rv__add8 __riscv__add8
#define __rv__radd8 __riscv__radd8
#define __rv__uradd8 __riscv__uradd8
#define __rv__kadd8 __riscv__kadd8
#define __rv__ukadd8 __riscv__ukadd8
#define __rv__sub8 __riscv__sub8
#define __rv__rsub8 __riscv__rsub8
#define __rv__ursub8 __riscv__ursub8
#define __rv__ksub8 __riscv__ksub8
#define __rv__uksub8 __riscv__uksub8
#define __rv__sra16 __riscv__sra16
#define __rv__sra16_u __riscv__sra16_u
#define __rv__srl16 __riscv__srl16
#define __rv__srl16_u __riscv__srl16_u
#define __rv__sll16 __riscv__sll16
#define __rv__ksll16 __riscv__ksll16
#define __rv__kslra16 __riscv__kslra16
#define __rv__kslra16_u __riscv__kslra16_u
#define __rv__cmpeq16 __riscv__cmpeq16
#define __rv__scmplt16 __riscv__scmplt16
#define __rv__scmple16 __riscv__scmple16
#define __rv__ucmplt16 __riscv__ucmplt16
#define __rv__ucmple16 __riscv__ucmple16
#define __rv__cmpeq8 __riscv__cmpeq8
#define __rv__scmplt8 __riscv__scmplt8
#define __rv__scmple8 __riscv__scmple8
#define __rv__ucmplt8 __riscv__ucmplt8
#define __rv__ucmple8 __riscv__ucmple8
#define __rv__smin16 __riscv__smin16
#define __rv__umin16 __riscv__umin16
#define __rv__smax16 __riscv__smax16
#define __rv__umax16 __riscv__umax16
#define __rv__sclip16 __riscv__sclip16
#define __rv__uclip16 __riscv__uclip16
#define __rv__khm16 __riscv__khm16
#define __rv__khmx16 __riscv__khmx16
#define __rv__khm8 __riscv__khm8
#define __rv__khmx8 __riscv__khmx8
#define __rv__kabs16 __riscv__kabs16
#define __rv__smul16 __riscv__smul16
#define __rv__smulx16 __riscv__smulx16
#define __rv__umul16 __riscv__umul16
#define __rv__umulx16 __riscv__umulx16
#define __rv__smul8 __riscv__smul8
#define __rv__smulx8 __riscv__smulx8
#define __rv__umul8 __riscv__umul8
#define __rv__umulx8 __riscv__umulx8
#define __rv__smin8 __riscv__smin8
#define __rv__umin8 __riscv__umin8
#define __rv__smax8 __riscv__smax8
#define __rv__umax8 __riscv__umax8
#define __rv__kabs8 __riscv__kabs8
#define __rv__sunpkd810 __riscv__sunpkd810
#define __rv__sunpkd820 __riscv__sunpkd820
#define __rv__sunpkd830 __riscv__sunpkd830
#define __rv__sunpkd831 __riscv__sunpkd831
#define __rv__sunpkd832 __riscv__sunpkd832
#define __rv__zunpkd810 __riscv__zunpkd810
#define __rv__zunpkd820 __riscv__zunpkd820
#define __rv__zunpkd830 __riscv__zunpkd830
#define __rv__zunpkd831 __riscv__zunpkd831
#define __rv__zunpkd832 __riscv__zunpkd832
#define __rv__raddw __riscv__raddw
#define __rv__uraddw __riscv__uraddw
#define __rv__rsubw __riscv__rsubw
#define __rv__ursubw __riscv__ursubw
#define __rv__sra_u __riscv__sra_u
#define __rv__ksll __riscv__ksllw
#define __rv__pkbb16 __riscv__pkbb16
#define __rv__pkbt16 __riscv__pkbt16
#define __rv__pktb16 __riscv__pktb16
#define __rv__pktt16 __riscv__pktt16
#define __rv__smmul __riscv__smmul
#define __rv__smmul_u __riscv__smmul_u
#define __rv__kmmac __riscv__kmmac
#define __rv__kmmac_u __riscv__kmmac_u
#define __rv__kmmsb __riscv__kmmsb
#define __rv__kmmsb_u __riscv__kmmsb_u
#define __rv__kwmmul __riscv__kwmmul
#define __rv__kwmmul_u __riscv__kwmmul_u
#define __rv__smmwb __riscv__smmwb
#define __rv__smmwb_u __riscv__smmwb_u
#define __rv__smmwt __riscv__smmwt
#define __rv__smmwt_u __riscv__smmwt_u
#define __rv__kmmawb __riscv__kmmawb
#define __rv__kmmawb_u __riscv__kmmawb_u
#define __rv__kmmawt __riscv__kmmawt
#define __rv__kmmawt_u __riscv__kmmawt_u
#define __rv__smbb __riscv__smbb16
#define __rv__smbt __riscv__smbt16
#define __rv__smtt __riscv__smtt
#define __rv__kmda __riscv__kmda
#define __rv__kmxda __riscv__kmxda
#define __rv__smds __riscv__smds
#define __rv__smdrs __riscv__smdrs
#define __rv__smxds __riscv__smxds
#define __rv__kmabb __riscv__kmabb
#define __rv__kmabt __riscv__kmabt
#define __rv__kmatt __riscv__kmatt
#define __rv__kmada __riscv__kmada
#define __rv__kmaxda __riscv__kmaxda
#define __rv__kmads __riscv__kmads
#define __rv__kmadrs __riscv__kmadrs
#define __rv__kmaxds __riscv__kmaxds
#define __rv__kmsda __riscv__kmsda
#define __rv__kmsxda __riscv__kmsxda
#define __rv__smal __riscv__smal
#define __rv__bitrev __riscv__bitrev
#define __rv__wext __riscv__wext
#define __rv__bpick __riscv__bpick
#define __rv__insb __riscv__insb
#define __rv__sadd64 __riscv__sadd64
#define __rv__uadd64 __riscv__uadd64
#define __rv__radd64 __riscv__radd64
#define __rv__uradd64 __riscv__uradd64
#define __rv__kadd64 __riscv__kadd64
#define __rv__ukadd64 __riscv__ukadd64
#define __rv__ssub64 __riscv__ssub64
#define __rv__usub64 __riscv__usub64
#define __rv__rsub64 __riscv__rsub64
#define __rv__ursub64 __riscv__ursub64
#define __rv__ksub64 __riscv__ksub64
#define __rv__uksub64 __riscv__uksub64
#define __rv__smar64 __riscv__smar64
#define __rv__smsr64 __riscv__smsr64
#define __rv__umar64 __riscv__umar64
#define __rv__umsr64 __riscv__umsr64
#define __rv__kmar64 __riscv__kmar64
#define __rv__kmsr64 __riscv__kmsr64
#define __rv__ukmar64 __riscv__ukmar64
#define __rv__ukmsr64 __riscv__ukmsr64
#define __rv__smalbb __riscv__smalbb
#define __rv__smalbt __riscv__smalbt
#define __rv__smaltt __riscv__smaltt
#define __rv__smalda __riscv__smalda
#define __rv__smalxda __riscv__smalxda
#define __rv__smalds __riscv__smalds
#define __rv__smaldrs __riscv__smaldrs
#define __rv__smalxds __riscv__smalxds
#define __rv__smslda __riscv__smslda
#define __rv__smslxda __riscv__smslxda
#define __rv__clip __riscv__uclip32
#define __rv__clips __riscv__sclip32
#define __rv__kabs __riscv__kabsw
#define __rv__kaddw __riscv__kaddw
#define __rv__kaddh __riscv__kaddh
#define __rv__ksubw __riscv__ksubw
#define __rv__ksubh __riscv__ksubh
#define __rv__ukaddw __riscv__ukaddw
#define __rv__ukaddh __riscv__ukaddh
#define __rv__uksubw __riscv__uksubw
#define __rv__uksubh __riscv__uksubh
#define __rv__kdmbb __riscv__kdmbb
#define __rv__kdmbt __riscv__kdmbt
#define __rv__kdmtt __riscv__kdmtt
#define __rv__khmbb __riscv__khmbb
#define __rv__khmbt __riscv__khmbt
#define __rv__khmtt __riscv__khmtt
#define __rv__kslraw __riscv__kslraw
#define __rv__kslraw_u __riscv__kslraw_u
#define __rv__ave __riscv__ave
#define __rv__max __riscv__maxw
#define __rv__min __riscv__minw
#define __rv__sra8 __riscv__sra8
#define __rv__sra8_u __riscv__sra8_u
#define __rv__srl8 __riscv__srl8
#define __rv__srl8_u __riscv__srl8_u
#define __rv__sll8 __riscv__sll8
#define __rv__ksll8 __riscv__ksll8
#define __rv__kslra8 __riscv__kslra8
#define __rv__kslra8_u __riscv__kslra8_u
#define __rv__clz __riscv__clz32
#define __rv__clo __riscv__clo32
#define __rv__pbsad __riscv__pbsad
#define __rv__pbsada __riscv__pbsada
#define __rv__swap8 __riscv__swap8
#define __rv__swap16 __riscv__swap16
#define __rv__sclip8 __riscv__sclip8
#define __rv__uclip8 __riscv__uclip8
#define __rv__rdov __riscv__rdov
#define __rv__clrov __riscv__clrov
#define __rv__v_umulx8 __riscv__v_umulx8
#define __rv__v_smul16 __riscv__v_smul16
#define __rv__v_umul8 __riscv__v_umul8
#define __rv__v_umul16 __riscv__v_umul16
#define __rv__v_smulx16 __riscv__v_smulx16
#define __rv__v_smulx8 __riscv__v_smulx8
#define __rv__v_smul8 __riscv__v_smul8
#define __rv__v_umulx16 __riscv__v_umulx16
#define __rv__v_clrs16 __riscv__v_clrs16
#define __rv__v_sstsa16 __riscv__v_sstsa16
#define __rv__v_kmmawb_u __riscv__v_kmmawb_u
#define __rv__v_umaqa __riscv__v_umaqa
#define __rv__v_kstsa16 __riscv__v_kstsa16
#define __rv__v_ukadd16 __riscv__v_ukadd16
#define __rv__v_smal __riscv__v_smal
#define __rv__v_smmwb __riscv__v_smmwb
#define __rv__v_ssub8 __riscv__v_ssub8
#define __rv__v_rcrsa16 __riscv__v_rcrsa16
#define __rv__v_kmmawt2 __riscv__v_kmmawt2
#define __rv__v_kstas16 __riscv__v_kstas16
#define __rv__v_khmtt __riscv__v_khmtt
#define __rv__v_ukcrsa16 __riscv__v_ukcrsa16
#define __rv__v_kmsxda __riscv__v_kmsxda
#define __rv__v_ucmplt8 __riscv__v_ucmplt8
#define __rv__v_ucrsa16 __riscv__v_ucrsa16
#define __rv__v_khm16 __riscv__v_khm16
#define __rv__v_pbsada __riscv__v_pbsada
#define __rv__v_kmmawt __riscv__v_kmmawt
#define __rv__v_uclip16 __riscv__v_uclip16
#define __rv__v_kdmbb __riscv__v_kdmbb
#define __rv__v_ustsa16 __riscv__v_ustsa16
#define __rv__v_ssub16 __riscv__v_ssub16
#define __rv__v_ksll16 __riscv__v_ksll16
#define __rv__v_smalbt __riscv__v_smalbt
#define __rv__v_kadd8 __riscv__v_kadd8
#define __rv__v_kmmawb __riscv__v_kmmawb
#define __rv__v_swap8 __riscv__v_swap8
#define __rv__v_kcras16 __riscv__v_kcras16
#define __rv__v_scmplt16 __riscv__v_scmplt16
#define __rv__v_pkbb16 __riscv__v_pkbb16
#define __rv__v_smalbb __riscv__v_smalbb
#define __rv__v_smmwt __riscv__v_smmwt
#define __rv__v_uksub16 __riscv__v_uksub16
#define __rv__v_radd16 __riscv__v_radd16
#define __rv__v_rcras16 __riscv__v_rcras16
#define __rv__v_zunpkd830 __riscv__v_zunpkd830
#define __rv__v_srl8_u __riscv__v_srl8_u
#define __rv__v_kmda __riscv__v_kmda
#define __rv__v_ukstas16 __riscv__v_ukstas16
#define __rv__v_sra16_u __riscv__v_sra16_u
#define __rv__v_umin8 __riscv__v_umin8
#define __rv__v_clo16 __riscv__v_clo16
#define __rv__v_pktt16 __riscv__v_pktt16
#define __rv__v_kdmatt __riscv__v_kdmatt
#define __rv__v_smalxds __riscv__v_smalxds
#define __rv__v_kmsda __riscv__v_kmsda
#define __rv__v_sclip16 __riscv__v_sclip16
#define __rv__v_kabs16 __riscv__v_kabs16
#define __rv__v_kslra8_u __riscv__v_kslra8_u
#define __rv__v_kmaxds __riscv__v_kmaxds
#define __rv__v_sll16 __riscv__v_sll16
#define __rv__v_umin16 __riscv__v_umin16
#define __rv__v_uclip8 __riscv__v_uclip8
#define __rv__v_zunpkd820 __riscv__v_zunpkd820
#define __rv__v_smxds __riscv__v_smxds
#define __rv__v_umax16 __riscv__v_umax16
#define __rv__v_smmwb_u __riscv__v_smmwb_u
#define __rv__v_sunpkd810 __riscv__v_sunpkd810
#define __rv__v_rstsa16 __riscv__v_rstsa16
#define __rv__v_khmbt __riscv__v_khmbt
#define __rv__v_urstsa16 __riscv__v_urstsa16
#define __rv__v_sll8 __riscv__v_sll8
#define __rv__v_kmadrs __riscv__v_kmadrs
#define __rv__v_kdmabb __riscv__v_kdmabb
#define __rv__v_clz16 __riscv__v_clz16
#define __rv__v_usub8 __riscv__v_usub8
#define __rv__v_scmple8 __riscv__v_scmple8
#define __rv__v_ucras16 __riscv__v_ucras16
#define __rv__v_kmaxda __riscv__v_kmaxda
#define __rv__v_ucmple8 __riscv__v_ucmple8
#define __rv__v_scmpeq16 __riscv__v_scmpeq16
#define __rv__v_smalds __riscv__v_smalds
#define __rv__v_kmatt __riscv__v_kmatt
#define __rv__v_rsub8 __riscv__v_rsub8
#define __rv__v_kslra8 __riscv__v_kslra8
#define __rv__v_sadd8 __riscv__v_sadd8
#define __rv__v_clrs8 __riscv__v_clrs8
#define __rv__v_ucmpeq16 __riscv__v_ucmpeq16
#define __rv__v_smslda __riscv__v_smslda
#define __rv__v_srl16 __riscv__v_srl16
#define __rv__v_srl16_u __riscv__v_srl16_u
#define __rv__v_kmmawb2 __riscv__v_kmmawb2
#define __rv__v_umax8 __riscv__v_umax8
#define __rv__v_sadd16 __riscv__v_sadd16
#define __rv__v_ksub8 __riscv__v_ksub8
#define __rv__v_ukadd8 __riscv__v_ukadd8
#define __rv__v_ucmpeq8 __riscv__v_ucmpeq8
#define __rv__v_kmmwb2_u __riscv__v_kmmwb2_u
#define __rv__v_kdmbt __riscv__v_kdmbt
#define __rv__v_kdmabt __riscv__v_kdmabt
#define __rv__v_smbb16 __riscv__v_smbb16
#define __rv__v_ucmple16 __riscv__v_ucmple16
#define __rv__v_kdmtt __riscv__v_kdmtt
#define __rv__v_sunpkd832 __riscv__v_sunpkd832
#define __rv__v_pktb16 __riscv__v_pktb16
#define __rv__v_kmmawb2_u __riscv__v_kmmawb2_u
#define __rv__v_scmplt8 __riscv__v_scmplt8
#define __rv__v_smalxda __riscv__v_smalxda
#define __rv__v_scras16 __riscv__v_scras16
#define __rv__v_smaltt __riscv__v_smaltt
#define __rv__v_smtt16 __riscv__v_smtt16
#define __rv__v_smin16 __riscv__v_smin16
#define __rv__v_scmple16 __riscv__v_scmple16
#define __rv__v_sra8 __riscv__v_sra8
#define __rv__v_swap16 __riscv__v_swap16
#define __rv__v_urcrsa16 __riscv__v_urcrsa16
#define __rv__v_smin8 __riscv__v_smin8
#define __rv__v_zunpkd831 __riscv__v_zunpkd831
#define __rv__v_zunpkd832 __riscv__v_zunpkd832
#define __rv__v_smaqa_su __riscv__v_smaqa_su
#define __rv__v_kmabb __riscv__v_kmabb
#define __rv__v_sra8_u __riscv__v_sra8_u
#define __rv__v_kadd16 __riscv__v_kadd16
#define __rv__v_sunpkd830 __riscv__v_sunpkd830
#define __rv__v_ucmplt16 __riscv__v_ucmplt16
#define __rv__v_smslxda __riscv__v_smslxda
#define __rv__v_sclip8 __riscv__v_sclip8
#define __rv__v_kmmwb2 __riscv__v_kmmwb2
#define __rv__v_uradd16 __riscv__v_uradd16
#define __rv__v_smmwt_u __riscv__v_smmwt_u
#define __rv__v_smax8 __riscv__v_smax8
#define __rv__v_kmabt __riscv__v_kmabt
#define __rv__v_sstas16 __riscv__v_sstas16
#define __rv__v_urstas16 __riscv__v_urstas16
#define __rv__v_smds __riscv__v_smds
#define __rv__v_kmmwt2 __riscv__v_kmmwt2
#define __rv__v_kslra16 __riscv__v_kslra16
#define __rv__v_ukstsa16 __riscv__v_ukstsa16
#define __rv__v_ursub8 __riscv__v_ursub8
#define __rv__v_ustas16 __riscv__v_ustas16
#define __rv__v_sra16 __riscv__v_sra16
#define __rv__v_uksub8 __riscv__v_uksub8
#define __rv__v_scmpeq8 __riscv__v_scmpeq8
#define __rv__v_clo8 __riscv__v_clo8
#define __rv__v_ksub16 __riscv__v_ksub16
#define __rv__v_ksll8 __riscv__v_ksll8
#define __rv__v_sunpkd820 __riscv__v_sunpkd820
#define __rv__v_sunpkd831 __riscv__v_sunpkd831
#define __rv__v_kmmawt_u __riscv__v_kmmawt_u
#define __rv__v_ukcras16 __riscv__v_ukcras16
#define __rv__v_kabs8 __riscv__v_kabs8
#define __rv__v_smdrs __riscv__v_smdrs
#define __rv__v_clz8 __riscv__v_clz8
#define __rv__v_khmbb __riscv__v_khmbb
#define __rv__v_smaqa __riscv__v_smaqa
#define __rv__v_smaldrs __riscv__v_smaldrs
#define __rv__v_smax16 __riscv__v_smax16
#define __rv__v_khm8 __riscv__v_khm8
#define __rv__v_pkbt16 __riscv__v_pkbt16
#define __rv__v_kmmwt2_u __riscv__v_kmmwt2_u
#define __rv__v_rstas16 __riscv__v_rstas16
#define __rv__v_radd8 __riscv__v_radd8
#define __rv__v_rsub16 __riscv__v_rsub16
#define __rv__v_khmx16 __riscv__v_khmx16
#define __rv__v_uradd8 __riscv__v_uradd8
#define __rv__v_smbt16 __riscv__v_smbt16
#define __rv__v_kcrsa16 __riscv__v_kcrsa16
#define __rv__v_scrsa16 __riscv__v_scrsa16
#define __rv__v_kslra16_u __riscv__v_kslra16_u
#define __rv__v_uadd8 __riscv__v_uadd8
#define __rv__v_kmada __riscv__v_kmada
#define __rv__v_smalda __riscv__v_smalda
#define __rv__v_urcras16 __riscv__v_urcras16
#define __rv__v_pbsad __riscv__v_pbsad
#define __rv__v_uadd16 __riscv__v_uadd16
#define __rv__v_usub16 __riscv__v_usub16
#define __rv__v_ursub16 __riscv__v_ursub16
#define __rv__v_khmx8 __riscv__v_khmx8
#define __rv__v_zunpkd810 __riscv__v_zunpkd810
#define __rv__v_kmmawt2_u __riscv__v_kmmawt2_u
#define __rv__v_srl8 __riscv__v_srl8
#define __rv__v_kmads __riscv__v_kmads
#define __rv__v_kmxda __riscv__v_kmxda

// RV64 Only
#if __riscv_xlen == 64
#define __rv__v_sra32_u __riscv__v_sra32_u
#define __rv__v_kmaxds32 __riscv__v_kmaxds32
#define __rv__v_sstsa32 __riscv__v_sstsa32
#define __rv__v_kdmtt16 __riscv__v_kdmtt16
#define __rv__v_kabs32 __riscv__v_kabs32
#define __rv__v_kmmsb_u __riscv__v_kmmsb_u
#define __rv__v_scrsa32 __riscv__v_scrsa32
#define __rv__v_smmul_u __riscv__v_smmul_u
#define __rv__v_scras32 __riscv__v_scras32
#define __rv__v_umsr64 __riscv__v_umsr64
#define __rv__v_khmtt16 __riscv__v_khmtt16
#define __rv__v_smds32 __riscv__v_smds32
#define __rv__v_kmmsb __riscv__v_kmmsb
#define __rv__v_kmda32 __riscv__v_kmda32
#define __rv__v_ukadd32 __riscv__v_ukadd32
#define __rv__v_sstas32 __riscv__v_sstas32
#define __rv__v_uclip32 __riscv__v_uclip32
#define __rv__v_urcrsa32 __riscv__v_urcrsa32
#define __rv__v_ursub32 __riscv__v_ursub32
#define __rv__v_rstsa32 __riscv__v_rstsa32
#define __rv__v_srl32 __riscv__v_srl32
#define __rv__v_kdmabb16 __riscv__v_kdmabb16
#define __rv__v_smtt32 __riscv__v_smtt32
#define __rv__v_kslra32 __riscv__v_kslra32
#define __rv__v_ukcrsa32 __riscv__v_ukcrsa32
#define __rv__v_ksll32 __riscv__v_ksll32
#define __rv__v_clrs32 __riscv__v_clrs32
#define __rv__v_kwmmul __riscv__v_kwmmul
#define __rv__v_srl32_u __riscv__v_srl32_u
#define __rv__v_kdmbb16 __riscv__v_kdmbb16
#define __rv__v_ucras32 __riscv__v_ucras32
#define __rv__v_ukcras32 __riscv__v_ukcras32
#define __rv__v_smax32 __riscv__v_smax32
#define __rv__v_urstas32 __riscv__v_urstas32
#define __rv__v_urstsa32 __riscv__v_urstsa32
#define __rv__v_kdmbt16 __riscv__v_kdmbt16
#define __rv__v_pkbt32 __riscv__v_pkbt32
#define __rv__v_khmbb16 __riscv__v_khmbb16
#define __rv__v_kmsxda32 __riscv__v_kmsxda32
#define __rv__v_rcras32 __riscv__v_rcras32
#define __rv__v_radd32 __riscv__v_radd32
#define __rv__v_kstas32 __riscv__v_kstas32
#define __rv__v_smbb32 __riscv__v_smbb32
#define __rv__v_kdmabt16 __riscv__v_kdmabt16
#define __rv__v_kmabt32 __riscv__v_kmabt32
#define __rv__v_pktt32 __riscv__v_pktt32
#define __rv__v_smar64 __riscv__v_smar64
#define __rv__v_ukmar64 __riscv__v_ukmar64
#define __rv__v_kwmmul_u __riscv__v_kwmmul_u
#define __rv__v_kmada32 __riscv__v_kmada32
#define __rv__v_khmbt16 __riscv__v_khmbt16
#define __rv__v_clz32 __riscv__v_clz32
#define __rv__v_ustsa32 __riscv__v_ustsa32
#define __rv__v_ukstsa32 __riscv__v_ukstsa32
#define __rv__v_kstsa32 __riscv__v_kstsa32
#define __rv__v_umax32 __riscv__v_umax32
#define __rv__v_umar64 __riscv__v_umar64
#define __rv__v_uksub32 __riscv__v_uksub32
#define __rv__v_smmul __riscv__v_smmul
#define __rv__v_ksub32 __riscv__v_ksub32
#define __rv__v_kcras32 __riscv__v_kcras32
#define __rv__v_kadd32 __riscv__v_kadd32
#define __rv__v_kmar64 __riscv__v_kmar64
#define __rv__v_kmads32 __riscv__v_kmads32
#define __rv__v_ukmsr64 __riscv__v_ukmsr64
#define __rv__v_kmsr64 __riscv__v_kmsr64
#define __rv__v_sclip32 __riscv__v_sclip32
#define __rv__v_kmsda32 __riscv__v_kmsda32
#define __rv__v_urcras32 __riscv__v_urcras32
#define __rv__v_smin32 __riscv__v_smin32
#define __rv__v_uadd32 __riscv__v_uadd32
#define __rv__v_smxds32 __riscv__v_smxds32
#define __rv__v_sll32 __riscv__v_sll32
#define __rv__v_smsr64 __riscv__v_smsr64
#define __rv__v_umin32 __riscv__v_umin32
#define __rv__v_smdrs32 __riscv__v_smdrs32
#define __rv__v_kmaxda32 __riscv__v_kmaxda32
#define __rv__v_ssub32 __riscv__v_ssub32
#define __rv__v_rcrsa32 __riscv__v_rcrsa32
#define __rv__v_ucrsa32 __riscv__v_ucrsa32
#define __rv__v_usub32 __riscv__v_usub32
#define __rv__v_kmmac __riscv__v_kmmac
#define __rv__v_kslra32_u __riscv__v_kslra32_u
#define __rv__v_kmmac_u __riscv__v_kmmac_u
#define __rv__v_kdmatt16 __riscv__v_kdmatt16
#define __rv__v_kmabb32 __riscv__v_kmabb32
#define __rv__v_uradd32 __riscv__v_uradd32
#define __rv__v_rsub32 __riscv__v_rsub32
#define __rv__v_kmxda32 __riscv__v_kmxda32
#define __rv__v_sra32 __riscv__v_sra32
#define __rv__v_pkbb32 __riscv__v_pkbb32
#define __rv__v_kmadrs32 __riscv__v_kmadrs32
#define __rv__v_clo32 __riscv__v_clo32
#define __rv__v_rstas32 __riscv__v_rstas32
#define __rv__v_ukstas32 __riscv__v_ukstas32
#define __rv__v_kcrsa32 __riscv__v_kcrsa32
#define __rv__v_smbt32 __riscv__v_smbt32
#define __rv__v_ustas32 __riscv__v_ustas32
#define __rv__v_pktb32 __riscv__v_pktb32
#define __rv__v_kmatt32 __riscv__v_kmatt32
#define __rv__v_sadd32 __riscv__v_sadd32
#endif
#endif // END OF _RISCV_RVP_INTRINSIC_H