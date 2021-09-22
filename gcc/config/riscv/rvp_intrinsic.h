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

// zbqbo
#if defined(__riscv_zbpbo)
#if __riscv_xlen == 32
#define __rv_clz(a) \
  (__builtin_riscv_clz ((a)))
#define __rv_fsr(a,b,c) \
  (__builtin_riscv_fsr ((a), (b), (c)))
#define __rv_pack(a, b) \
  (__builtin_riscv_pkbb16 ((a), (b)))
#define __rv_packu(a, b) \
  (__builtin_riscv_pktt16 ((a), (b)))
#define __rv_rev(a) \
  (__builtin_riscv_bitrev ((a), 32))
#define __rv_v_rev8h(a) \
  (__builtin_riscv_swap8 ((a)))
#else
#define __rv_fsrw(a,b,c) \
  (__builtin_riscv_fsrw ((a), (b), (c)))
#define __rv_pack(a, b) \
  (__builtin_riscv_pkbb32 ((a), (b)))
#define __rv_packu(a, b) \
  (__builtin_riscv_pktt32 ((a), (b)))
#define __rv_rev(a) \
  (__builtin_riscv_bitrev ((a), 64))
#define __rv_v_rev8h(a) \
  (__builtin_riscv_v64_swap8 ((a)))
#endif
#define __rv_cmix(a, b, c) \
  (__builtin_riscv_bpick ((a), (c), (b)))
#define __rv_max(a, b) \
  (__builtin_riscv_maxw ((a), (b)))
#define __rv_min(a, b) \
  (__builtin_riscv_minw ((a), (b)))
#define __rv_rev8h(a) \
  (__builtin_riscv_swap8 ((a)))
#endif

// zpn
#define __rv_add16(a, b) \
  (__builtin_riscv_add16 ((a), (b)))
#define __rv_radd16(a, b) \
  (__builtin_riscv_radd16 ((a), (b)))
#define __rv_uradd16(a, b) \
  (__builtin_riscv_uradd16 ((a), (b)))
#define __rv_kadd16(a, b) \
  (__builtin_riscv_kadd16 ((a), (b)))
#define __rv_ukadd16(a, b) \
  (__builtin_riscv_ukadd16 ((a), (b)))
#define __rv_sub16(a, b) \
  (__builtin_riscv_sub16 ((a), (b)))
#define __rv_rsub16(a, b) \
  (__builtin_riscv_rsub16 ((a), (b)))
#define __rv_ursub16(a, b) \
  (__builtin_riscv_ursub16 ((a), (b)))
#define __rv_ksub16(a, b) \
  (__builtin_riscv_ksub16 ((a), (b)))
#define __rv_uksub16(a, b) \
  (__builtin_riscv_uksub16 ((a), (b)))
#define __rv_cras16(a, b) \
  (__builtin_riscv_cras16 ((a), (b)))
#define __rv_rcras16(a, b) \
  (__builtin_riscv_rcras16 ((a), (b)))
#define __rv_urcras16(a, b) \
  (__builtin_riscv_urcras16 ((a), (b)))
#define __rv_kcras16(a, b) \
  (__builtin_riscv_kcras16 ((a), (b)))
#define __rv_ukcras16(a, b) \
  (__builtin_riscv_ukcras16 ((a), (b)))
#define __rv_crsa16(a, b) \
  (__builtin_riscv_crsa16 ((a), (b)))
#define __rv_rcrsa16(a, b) \
  (__builtin_riscv_rcrsa16 ((a), (b)))
#define __rv_urcrsa16(a, b) \
  (__builtin_riscv_urcrsa16 ((a), (b)))
#define __rv_kcrsa16(a, b) \
  (__builtin_riscv_kcrsa16 ((a), (b)))
#define __rv_ukcrsa16(a, b) \
  (__builtin_riscv_ukcrsa16 ((a), (b)))
#define __rv_stas16(a, b) \
  (__builtin_riscv_stas16 ((a), (b)))
#define __rv_rstas16(a, b) \
  (__builtin_riscv_rstas16 ((a), (b)))
#define __rv_urstas16(a, b) \
  (__builtin_riscv_urstas16 ((a), (b)))
#define __rv_kstas16(a, b) \
  (__builtin_riscv_kstas16 ((a), (b)))
#define __rv_ukstas16(a, b) \
  (__builtin_riscv_ukstas16 ((a), (b)))
#define __rv_stsa16(a, b) \
  (__builtin_riscv_stsa16 ((a), (b)))
#define __rv_rstsa16(a, b) \
  (__builtin_riscv_rstsa16 ((a), (b)))
#define __rv_urstsa16(a, b) \
  (__builtin_riscv_urstsa16 ((a), (b)))
#define __rv_kstsa16(a, b) \
  (__builtin_riscv_kstsa16 ((a), (b)))
#define __rv_ukstsa16(a, b) \
  (__builtin_riscv_ukstsa16 ((a), (b)))
#define __rv_add8(a, b) \
  (__builtin_riscv_add8 ((a), (b)))
#define __rv_radd8(a, b) \
  (__builtin_riscv_radd8 ((a), (b)))
#define __rv_uradd8(a, b) \
  (__builtin_riscv_uradd8 ((a), (b)))
#define __rv_kadd8(a, b) \
  (__builtin_riscv_kadd8 ((a), (b)))
#define __rv_ukadd8(a, b) \
  (__builtin_riscv_ukadd8 ((a), (b)))
#define __rv_sub8(a, b) \
  (__builtin_riscv_sub8 ((a), (b)))
#define __rv_rsub8(a, b) \
  (__builtin_riscv_rsub8 ((a), (b)))
#define __rv_ursub8(a, b) \
  (__builtin_riscv_ursub8 ((a), (b)))
#define __rv_ksub8(a, b) \
  (__builtin_riscv_ksub8 ((a), (b)))
#define __rv_uksub8(a, b) \
  (__builtin_riscv_uksub8 ((a), (b)))
#define __rv_sra16(a, b) \
  (__builtin_riscv_sra16 ((a), (b)))
#define __rv_sra16_u(a, b) \
  (__builtin_riscv_sra16_u ((a), (b)))
#define __rv_srl16(a, b) \
  (__builtin_riscv_srl16 ((a), (b)))
#define __rv_srl16_u(a, b) \
  (__builtin_riscv_srl16_u ((a), (b)))
#define __rv_sll16(a, b) \
  (__builtin_riscv_sll16 ((a), (b)))
#define __rv_ksll16(a, b) \
  (__builtin_riscv_ksll16 ((a), (b)))
#define __rv_kslra16(a, b) \
  (__builtin_riscv_kslra16 ((a), (b)))
#define __rv_kslra16_u(a, b) \
  (__builtin_riscv_kslra16_u ((a), (b)))
#define __rv_cmpeq16(a, b) \
  (__builtin_riscv_cmpeq16 ((a), (b)))
#define __rv_scmplt16(a, b) \
  (__builtin_riscv_scmplt16 ((a), (b)))
#define __rv_scmple16(a, b) \
  (__builtin_riscv_scmple16 ((a), (b)))
#define __rv_ucmplt16(a, b) \
  (__builtin_riscv_ucmplt16 ((a), (b)))
#define __rv_ucmple16(a, b) \
  (__builtin_riscv_ucmple16 ((a), (b)))
#define __rv_cmpeq8(a, b) \
  (__builtin_riscv_cmpeq8 ((a), (b)))
#define __rv_scmplt8(a, b) \
  (__builtin_riscv_scmplt8 ((a), (b)))
#define __rv_scmple8(a, b) \
  (__builtin_riscv_scmple8 ((a), (b)))
#define __rv_ucmplt8(a, b) \
  (__builtin_riscv_ucmplt8 ((a), (b)))
#define __rv_ucmple8(a, b) \
  (__builtin_riscv_ucmple8 ((a), (b)))
#define __rv_smin16(a, b) \
  (__builtin_riscv_smin16 ((a), (b)))
#define __rv_umin16(a, b) \
  (__builtin_riscv_umin16 ((a), (b)))
#define __rv_smax16(a, b) \
  (__builtin_riscv_smax16 ((a), (b)))
#define __rv_umax16(a, b) \
  (__builtin_riscv_umax16 ((a), (b)))
#define __rv_sclip16(a, b) \
  (__builtin_riscv_sclip16 ((a), (b)))
#define __rv_uclip16(a, b) \
  (__builtin_riscv_uclip16 ((a), (b)))
#define __rv_khm16(a, b) \
  (__builtin_riscv_khm16 ((a), (b)))
#define __rv_khmx16(a, b) \
  (__builtin_riscv_khmx16 ((a), (b)))
#define __rv_khm8(a, b) \
  (__builtin_riscv_khm8 ((a), (b)))
#define __rv_khmx8(a, b) \
  (__builtin_riscv_khmx8 ((a), (b)))
#define __rv_kabs16(a) \
  (__builtin_riscv_kabs16 ((a)))
#define __rv_smin8(a, b) \
  (__builtin_riscv_smin8 ((a), (b)))
#define __rv_umin8(a, b) \
  (__builtin_riscv_umin8 ((a), (b)))
#define __rv_smax8(a, b) \
  (__builtin_riscv_smax8 ((a), (b)))
#define __rv_umax8(a, b) \
  (__builtin_riscv_umax8 ((a), (b)))
#define __rv_kabs8(a) \
  (__builtin_riscv_kabs8 ((a)))
#define __rv_sunpkd810(a) \
  (__builtin_riscv_sunpkd810 ((a)))
#define __rv_sunpkd820(a) \
  (__builtin_riscv_sunpkd820 ((a)))
#define __rv_sunpkd830(a) \
  (__builtin_riscv_sunpkd830 ((a)))
#define __rv_sunpkd831(a) \
  (__builtin_riscv_sunpkd831 ((a)))
#define __rv_sunpkd832(a) \
  (__builtin_riscv_sunpkd832 ((a)))
#define __rv_zunpkd810(a) \
  (__builtin_riscv_zunpkd810 ((a)))
#define __rv_zunpkd820(a) \
  (__builtin_riscv_zunpkd820 ((a)))
#define __rv_zunpkd830(a) \
  (__builtin_riscv_zunpkd830 ((a)))
#define __rv_zunpkd831(a) \
  (__builtin_riscv_zunpkd831 ((a)))
#define __rv_zunpkd832(a) \
  (__builtin_riscv_zunpkd832 ((a)))
#define __rv_raddw(a, b) \
  (__builtin_riscv_raddw ((a), (b)))
#define __rv_uraddw(a, b) \
  (__builtin_riscv_uraddw ((a), (b)))
#define __rv_rsubw(a, b) \
  (__builtin_riscv_rsubw ((a), (b)))
#define __rv_ursubw(a, b) \
  (__builtin_riscv_ursubw ((a), (b)))
#define __rv_sra_u(a, b) \
  (__builtin_riscv_sra_u ((a), (b)))
#define __rv_ksllw(a, b) \
  (__builtin_riscv_ksllw ((a), (b)))
#define __rv_pkbb16(a, b) \
  (__builtin_riscv_pkbb16 ((a), (b)))
#define __rv_pkbt16(a, b) \
  (__builtin_riscv_pkbt16 ((a), (b)))
#define __rv_pktb16(a, b) \
  (__builtin_riscv_pktb16 ((a), (b)))
#define __rv_pktt16(a, b) \
  (__builtin_riscv_pktt16 ((a), (b)))
#define __rv_smmul(a, b) \
  (__builtin_riscv_smmul ((a), (b)))
#define __rv_smmul_u(a, b) \
  (__builtin_riscv_smmul_u ((a), (b)))
#define __rv_kmmac(r, a, b) \
  (__builtin_riscv_kmmac ((r), (a), (b)))
#define __rv_kmmac_u(r, a, b) \
  (__builtin_riscv_kmmac_u ((r), (a), (b)))
#define __rv_kmmsb(r, a, b) \
  (__builtin_riscv_kmmsb ((r), (a), (b)))
#define __rv_kmmsb_u(r, a, b) \
  (__builtin_riscv_kmmsb_u ((r), (a), (b)))
#define __rv_kwmmul(a, b) \
  (__builtin_riscv_kwmmul ((a), (b)))
#define __rv_kwmmul_u(a, b) \
  (__builtin_riscv_kwmmul_u ((a), (b)))
#define __rv_smmwb(a, b) \
  (__builtin_riscv_smmwb ((a), (b)))
#define __rv_smmwb_u(a, b) \
  (__builtin_riscv_smmwb_u ((a), (b)))
#define __rv_smmwt(a, b) \
  (__builtin_riscv_smmwt ((a), (b)))
#define __rv_smmwt_u(a, b) \
  (__builtin_riscv_smmwt_u ((a), (b)))
#define __rv_kmmwb2(a, b) \
  (__builtin_riscv_kmmwb2 ((a), (b)))
#define __rv_kmmwb2_u(a, b) \
  (__builtin_riscv_kmmwb2_u ((a), (b)))
#define __rv_kmmwt2(a, b) \
  (__builtin_riscv_kmmwt2 ((a), (b)))
#define __rv_kmmwt2_u(a, b) \
  (__builtin_riscv_kmmwt2_u ((a), (b)))
#define __rv_kmmawb(r, a, b) \
  (__builtin_riscv_kmmawb ((r), (a), (b)))
#define __rv_kmmawb_u(r, a, b) \
  (__builtin_riscv_kmmawb_u ((r), (a), (b)))
#define __rv_kmmawt(r, a, b) \
  (__builtin_riscv_kmmawt ((r), (a), (b)))
#define __rv_kmmawt_u(r, a, b) \
  (__builtin_riscv_kmmawt_u ((r), (a), (b)))
#define __rv_kmmawb2(r, a, b) \
  (__builtin_riscv_kmmawb2 ((r), (a), (b)))
#define __rv_kmmawb2_u(r, a, b) \
  (__builtin_riscv_kmmawb2_u ((r), (a), (b)))
#define __rv_kmmawt2(r, a, b) \
  (__builtin_riscv_kmmawt2 ((r), (a), (b)))
#define __rv_kmmawt2_u(r, a, b) \
  (__builtin_riscv_kmmawt2_u ((r), (a), (b)))
#define __rv_smbb16(a, b) \
  (__builtin_riscv_smbb16 ((a), (b)))
#define __rv_smbt16(a, b) \
  (__builtin_riscv_smbt16 ((a), (b)))
#define __rv_smtt16(a, b) \
  (__builtin_riscv_smtt16 ((a), (b)))
#define __rv_kmda(a, b) \
  (__builtin_riscv_kmda ((a), (b)))
#define __rv_kmxda(a, b) \
  (__builtin_riscv_kmxda ((a), (b)))
#define __rv_smds(a, b) \
  (__builtin_riscv_smds ((a), (b)))
#define __rv_smdrs(a, b) \
  (__builtin_riscv_smdrs ((a), (b)))
#define __rv_smxds(a, b) \
  (__builtin_riscv_smxds ((a), (b)))
#define __rv_kmabb(r, a, b) \
  (__builtin_riscv_kmabb ((r), (a), (b)))
#define __rv_kmabt(r, a, b) \
  (__builtin_riscv_kmabt ((r), (a), (b)))
#define __rv_kmatt(r, a, b) \
  (__builtin_riscv_kmatt ((r), (a), (b)))
#define __rv_kmada(r, a, b) \
  (__builtin_riscv_kmada ((r), (a), (b)))
#define __rv_kmaxda(r, a, b) \
  (__builtin_riscv_kmaxda ((r), (a), (b)))
#define __rv_kmads(r, a, b) \
  (__builtin_riscv_kmads ((r), (a), (b)))
#define __rv_kmadrs(r, a, b) \
  (__builtin_riscv_kmadrs ((r), (a), (b)))
#define __rv_kmaxds(r, a, b) \
  (__builtin_riscv_kmaxds ((r), (a), (b)))
#define __rv_kmsda(r, a, b) \
  (__builtin_riscv_kmsda ((r), (a), (b)))
#define __rv_kmsxda(r, a, b) \
  (__builtin_riscv_kmsxda ((r), (a), (b)))
#define __rv_bitrev(a, b) \
  (__builtin_riscv_bitrev ((a), (b)))
#define __rv_bpick(r, a, b) \
  (__builtin_riscv_bpick ((r), (a), (b)))
#define __rv_insb(r, a, b) \
  (__builtin_riscv_insb ((r), (a), (b)))
#define __rv_kabsw(a) \
  (__builtin_riscv_kabsw ((a)))
#define __rv_kaddw(a, b) \
  (__builtin_riscv_kaddw ((a), (b)))
#define __rv_kaddh(a, b) \
  (__builtin_riscv_kaddh ((a), (b)))
#define __rv_ksubw(a, b) \
  (__builtin_riscv_ksubw ((a), (b)))
#define __rv_ksubh(a, b) \
  (__builtin_riscv_ksubh ((a), (b)))
#define __rv_ukaddw(a, b) \
  (__builtin_riscv_ukaddw ((a), (b)))
#define __rv_ukaddh(a, b) \
  (__builtin_riscv_ukaddh ((a), (b)))
#define __rv_uksubw(a, b) \
  (__builtin_riscv_uksubw ((a), (b)))
#define __rv_uksubh(a, b) \
  (__builtin_riscv_uksubh ((a), (b)))
#define __rv_kdmbb(a, b) \
  (__builtin_riscv_kdmbb ((a), (b)))
#define __rv_kdmbt(a, b) \
  (__builtin_riscv_kdmbt ((a), (b)))
#define __rv_kdmtt(a, b) \
  (__builtin_riscv_kdmtt ((a), (b)))
#define __rv_khmbb(a, b) \
  (__builtin_riscv_khmbb ((a), (b)))
#define __rv_khmbt(a, b) \
  (__builtin_riscv_khmbt ((a), (b)))
#define __rv_khmtt(a, b) \
  (__builtin_riscv_khmtt ((a), (b)))
#define __rv_kslraw(a, b) \
  (__builtin_riscv_kslraw ((a), (b)))
#define __rv_kslraw_u(a, b) \
  (__builtin_riscv_kslraw_u ((a), (b)))
#define __rv_ave(a, b) \
  (__builtin_riscv_ave ((a), (b)))
#define __rv_maxw(a, b) \
  (__builtin_riscv_maxw ((a), (b)))
#define __rv_minw(a, b) \
  (__builtin_riscv_minw ((a), (b)))
#define __rv_sra8(a, b) \
  (__builtin_riscv_sra8 ((a), (b)))
#define __rv_sra8_u(a, b) \
  (__builtin_riscv_sra8_u ((a), (b)))
#define __rv_srl8(a, b) \
  (__builtin_riscv_srl8 ((a), (b)))
#define __rv_srl8_u(a, b) \
  (__builtin_riscv_srl8_u ((a), (b)))
#define __rv_sll8(a, b) \
  (__builtin_riscv_sll8 ((a), (b)))
#define __rv_ksll8(a, b) \
  (__builtin_riscv_ksll8 ((a), (b)))
#define __rv_kslra8(a, b) \
  (__builtin_riscv_kslra8 ((a), (b)))
#define __rv_kslra8_u(a, b) \
  (__builtin_riscv_kslra8_u ((a), (b)))
#define __rv_pbsad(a, b) \
  (__builtin_riscv_pbsad ((a), (b)))
#define __rv_pbsada(acc, a, b) \
  (__builtin_riscv_pbsada ((acc), (a), (b)))
#define __rv_swap8(a) \
  (__builtin_riscv_swap8 ((a)))
#define __rv_swap16(a) \
  (__builtin_riscv_pkbt16 ((a), (a)))
#define __rv_sclip8(a, b) \
  (__builtin_riscv_sclip8 ((a), (b)))
#define __rv_uclip8(a, b) \
  (__builtin_riscv_uclip8 ((a), (b)))
#define __rv_rdov() \
  (__builtin_riscv_rdov())
#define __rv_clrov() \
  (__builtin_riscv_clrov())
#define __rv_kdmabb(r, a, b) \
  (__builtin_riscv_kdmabb ((r), (a), (b)))
#define __rv_kdmabt(r, a, b) \
  (__builtin_riscv_kdmabt ((r), (a), (b)))
#define __rv_kdmatt(r, a, b) \
  (__builtin_riscv_kdmatt ((r), (a), (b)))
#define __rv_smaqa(r, a, b) \
  (__builtin_riscv_smaqa ((r), (a), (b)))
#define __rv_umaqa(r, a, b) \
  (__builtin_riscv_umaqa ((r), (a), (b)))
#define __rv_smaqa_su(r, a, b) \
  (__builtin_riscv_smaqa_su ((r), (a), (b)))
#define __rv_clrs8(a) \
  (__builtin_riscv_clrs8 ((a)))
#define __rv_clrs16(a) \
  (__builtin_riscv_clrs16 ((a)))
#define __rv_clrs32(a) \
  (__builtin_riscv_clrs32 ((a)))
#define __rv_clz8(a) \
  (__builtin_riscv_clz8 ((a)))
#define __rv_clz16(a) \
  (__builtin_riscv_clz16 ((a)))
#define __rv_clz32(a) \
  (__builtin_riscv_clz32 ((a)))
#define __rv_uclip32(a, imm) \
  (__builtin_riscv_uclip32 ((a), (imm)))
#define __rv_sclip32(a, imm) \
  (__builtin_riscv_sclip32 ((a), (imm)))
#define __rv_add32(a, b) \
  (__builtin_riscv_add32 ((a), (b)))
#define __rv_radd32(a, b) \
  (__builtin_riscv_radd32 ((a), (b)))
#define __rv_uradd32(a, b) \
  (__builtin_riscv_uradd32 ((a), (b)))
#define __rv_kadd32(a, b) \
  (__builtin_riscv_kadd32 ((a), (b)))
#define __rv_ukadd32(a, b) \
  (__builtin_riscv_ukadd32 ((a), (b)))
#define __rv_sub32(a, b) \
  (__builtin_riscv_sub32 ((a), (b)))
#define __rv_rsub32(a, b) \
  (__builtin_riscv_rsub32 ((a), (b)))
#define __rv_ursub32(a, b) \
  (__builtin_riscv_ursub32 ((a), (b)))
#define __rv_ksub32(a, b) \
  (__builtin_riscv_ksub32 ((a), (b)))
#define __rv_uksub32(a, b) \
  (__builtin_riscv_uksub32 ((a), (b)))
#define __rv_cras32(a, b) \
  (__builtin_riscv_cras32 ((a), (b)))
#define __rv_crsa32(a, b) \
  (__builtin_riscv_crsa32 ((a), (b)))
#define __rv_rcras32(a, b) \
  (__builtin_riscv_rcras32 ((a), (b)))
#define __rv_rcrsa32(a, b) \
  (__builtin_riscv_rcrsa32 ((a), (b)))
#define __rv_urcras32(a, b) \
  (__builtin_riscv_urcras32 ((a), (b)))
#define __rv_urcrsa32(a, b) \
  (__builtin_riscv_urcrsa32 ((a), (b)))
#define __rv_kcras32(a, b) \
  (__builtin_riscv_kcras32 ((a), (b)))
#define __rv_kcrsa32(a, b) \
  (__builtin_riscv_kcrsa32 ((a), (b)))
#define __rv_ukcras32(a, b) \
  (__builtin_riscv_ukcras32 ((a), (b)))
#define __rv_ukcrsa32(a, b) \
  (__builtin_riscv_ukcrsa32 ((a), (b)))
#define __rv_stas32(a, b) \
  (__builtin_riscv_stas32 ((a), (b)))
#define __rv_stsa32(a, b) \
  (__builtin_riscv_stsa32 ((a), (b)))
#define __rv_rstas32(a, b) \
  (__builtin_riscv_rstas32 ((a), (b)))
#define __rv_rstsa32(a, b) \
  (__builtin_riscv_rstsa32 ((a), (b)))
#define __rv_urstas32(a, b) \
  (__builtin_riscv_urstas32 ((a), (b)))
#define __rv_urstsa32(a, b) \
  (__builtin_riscv_urstsa32 ((a), (b)))
#define __rv_kstas32(a, b) \
  (__builtin_riscv_kstas32 ((a), (b)))
#define __rv_kstsa32(a, b) \
  (__builtin_riscv_kstsa32 ((a), (b)))
#define __rv_ukstas32(a, b) \
  (__builtin_riscv_ukstas32 ((a), (b)))
#define __rv_ukstsa32(a, b) \
  (__builtin_riscv_ukstsa32 ((a), (b)))
#define __rv_sra32(a, b) \
  (__builtin_riscv_sra32 ((a), (b)))
#define __rv_sra32_u(a, b) \
  (__builtin_riscv_sra32_u ((a), (b)))
#define __rv_srl32(a, b) \
  (__builtin_riscv_srl32 ((a), (b)))
#define __rv_srl32_u(a, b) \
  (__builtin_riscv_srl32_u ((a), (b)))
#define __rv_sll32(a, b) \
  (__builtin_riscv_sll32 ((a), (b)))
#define __rv_ksll32(a, b) \
  (__builtin_riscv_ksll32 ((a), (b)))
#define __rv_kslra32(a, b) \
  (__builtin_riscv_kslra32 ((a), (b)))
#define __rv_kslra32_u(a, b) \
  (__builtin_riscv_kslra32_u ((a), (b)))
#define __rv_smin32(a, b) \
  (__builtin_riscv_smin32 ((a), (b)))
#define __rv_umin32(a, b) \
  (__builtin_riscv_umin32 ((a), (b)))
#define __rv_smax32(a, b) \
  (__builtin_riscv_smax32 ((a), (b)))
#define __rv_umax32(a, b) \
  (__builtin_riscv_umax32 ((a), (b)))
#define __rv_kabs32(a) \
  (__builtin_riscv_kabs32 ((a)))
#define __rv_khmbb16(a, b) \
  (__builtin_riscv_khmbb16 ((a), (b)))
#define __rv_khmbt16(a, b) \
  (__builtin_riscv_khmbt16 ((a), (b)))
#define __rv_khmtt16(a, b) \
  (__builtin_riscv_khmtt16 ((a), (b)))
#define __rv_kdmbb16(a, b) \
  (__builtin_riscv_kdmbb16 ((a), (b)))
#define __rv_kdmbt16(a, b) \
  (__builtin_riscv_kdmbt16 ((a), (b)))
#define __rv_kdmtt16(a, b) \
  (__builtin_riscv_kdmtt16 ((a), (b)))
#define __rv_smbb32(a, b) \
  (__builtin_riscv_smbb32 ((a), (b)))
#define __rv_smbt32(a, b) \
  (__builtin_riscv_smbt32 ((a), (b)))
#define __rv_smtt32(a, b) \
  (__builtin_riscv_smtt32 ((a), (b)))
#define __rv_kmabb32(r, a, b) \
  (__builtin_riscv_kmabb32 ((r), (a), (b)))
#define __rv_kmabt32(r, a, b) \
  (__builtin_riscv_kmabt32 ((r), (a), (b)))
#define __rv_kmatt32(r, a, b) \
  (__builtin_riscv_kmatt32 ((r), (a), (b)))
#define __rv_kmda32(a, b) \
  (__builtin_riscv_kmda32 ((a), (b)))
#define __rv_kmxda32(a, b) \
  (__builtin_riscv_kmxda32 ((a), (b)))
#define __rv_kmada32(r, a, b) \
  (__builtin_riscv_kmada32 ((r), (a), (b)))
#define __rv_kmaxda32(r, a, b) \
  (__builtin_riscv_kmaxda32 ((r), (a), (b)))
#define __rv_kmads32(r, a, b) \
  (__builtin_riscv_kmads32 ((r), (a), (b)))
#define __rv_kmadrs32(r, a, b) \
  (__builtin_riscv_kmadrs32 ((r), (a), (b)))
#define __rv_kmaxds32(r, a, b) \
  (__builtin_riscv_kmaxds32 ((r), (a), (b)))
#define __rv_kmsda32(r, a, b) \
  (__builtin_riscv_kmsda32 ((r), (a), (b)))
#define __rv_kmsxda32(r, a, b) \
  (__builtin_riscv_kmsxda32 ((r), (a), (b)))
#define __rv_smds32(a, b) \
  (__builtin_riscv_smds32 ((a), (b)))
#define __rv_smdrs32(a, b) \
  (__builtin_riscv_smdrs32 ((a), (b)))
#define __rv_smxds32(a, b) \
  (__builtin_riscv_smxds32 ((a), (b)))
#define __rv_kdmabb16(r, a, b) \
  (__builtin_riscv_kdmabb16 ((r), (a), (b)))
#define __rv_kdmabt16(r, a, b) \
  (__builtin_riscv_kdmabt16 ((r), (a), (b)))
#define __rv_kdmatt16(r, a, b) \
  (__builtin_riscv_kdmatt16 ((r), (a), (b)))
#define __rv_pkbb32(a, b) \
  (__builtin_riscv_pkbb32 ((a), (b)))
#define __rv_pkbt32(a, b) \
  (__builtin_riscv_pkbt32 ((a), (b)))
#define __rv_pktb32(a, b) \
  (__builtin_riscv_pktb32 ((a), (b)))
#define __rv_pktt32(a, b) \
  (__builtin_riscv_pktt32 ((a), (b)))
#define __rv_v_uadd32(a, b) \
  (__builtin_riscv_uadd32 ((a), (b)))
#define __rv_v_sadd32(a, b) \
  (__builtin_riscv_sadd32 ((a), (b)))
#define __rv_v_radd32(a, b) \
  (__builtin_riscv_radd32 ((a), (b)))
#define __rv_v_uradd32(a, b) \
  (__builtin_riscv_uradd32 ((a), (b)))
#define __rv_v_kadd32(a, b) \
  (__builtin_riscv_kadd32 ((a), (b)))
#define __rv_v_ukadd32(a, b) \
  (__builtin_riscv_ukadd32 ((a), (b)))
#define __rv_v_usub32(a, b) \
  (__builtin_riscv_usub32 ((a), (b)))
#define __rv_v_ssub32(a, b) \
  (__builtin_riscv_ssub32 ((a), (b)))
#define __rv_v_rsub32(a, b) \
  (__builtin_riscv_rsub32 ((a), (b)))
#define __rv_v_ursub32(a, b) \
  (__builtin_riscv_ursub32 ((a), (b)))
#define __rv_v_ksub32(a, b) \
  (__builtin_riscv_ksub32 ((a), (b)))
#define __rv_v_uksub32(a, b) \
  (__builtin_riscv_uksub32 ((a), (b)))
#define __rv_v_ucras32(a, b) \
  (__builtin_riscv_ucras32 ((a), (b)))
#define __rv_v_scras32(a, b) \
  (__builtin_riscv_scras32 ((a), (b)))
#define __rv_v_ucrsa32(a, b) \
  (__builtin_riscv_ucrsa32 ((a), (b)))
#define __rv_v_scrsa32(a, b) \
  (__builtin_riscv_scrsa32 ((a), (b)))
#define __rv_v_rcras32(a, b) \
  (__builtin_riscv_rcras32 ((a), (b)))
#define __rv_v_rcrsa32(a, b) \
  (__builtin_riscv_rcrsa32 ((a), (b)))
#define __rv_v_urcras32(a, b) \
  (__builtin_riscv_urcras32 ((a), (b)))
#define __rv_v_urcrsa32(a, b) \
  (__builtin_riscv_urcrsa32 ((a), (b)))
#define __rv_v_kcras32(a, b) \
  (__builtin_riscv_kcras32 ((a), (b)))
#define __rv_v_kcrsa32(a, b) \
  (__builtin_riscv_kcrsa32 ((a), (b)))
#define __rv_v_ukcras32(a, b) \
  (__builtin_riscv_ukcras32 ((a), (b)))
#define __rv_v_ukcrsa32(a, b) \
  (__builtin_riscv_ukcrsa32 ((a), (b)))
#define __rv_v_ustas32(a, b) \
  (__builtin_riscv_ustas32 ((a), (b)))
#define __rv_v_sstas32(a, b) \
  (__builtin_riscv_sstas32 ((a), (b)))
#define __rv_v_ustsa32(a, b) \
  (__builtin_riscv_ustsa32 ((a), (b)))
#define __rv_v_sstsa32(a, b) \
  (__builtin_riscv_sstsa32 ((a), (b)))
#define __rv_v_rstas32(a, b) \
  (__builtin_riscv_rstas32 ((a), (b)))
#define __rv_v_rstsa32(a, b) \
  (__builtin_riscv_rstsa32 ((a), (b)))
#define __rv_v_urstas32(a, b) \
  (__builtin_riscv_urstas32 ((a), (b)))
#define __rv_v_urstsa32(a, b) \
  (__builtin_riscv_urstsa32 ((a), (b)))
#define __rv_v_kstas32(a, b) \
  (__builtin_riscv_kstas32 ((a), (b)))
#define __rv_v_kstsa32(a, b) \
  (__builtin_riscv_kstsa32 ((a), (b)))
#define __rv_v_ukstas32(a, b) \
  (__builtin_riscv_ukstas32 ((a), (b)))
#define __rv_v_ukstsa32(a, b) \
  (__builtin_riscv_ukstsa32 ((a), (b)))
#define __rv_v_sra32(a, b) \
  (__builtin_riscv_sra32 ((a), (b)))
#define __rv_v_sra32_u(a, b) \
  (__builtin_riscv_sra32_u ((a), (b)))
#define __rv_v_srl32(a, b) \
  (__builtin_riscv_srl32 ((a), (b)))
#define __rv_v_srl32_u(a, b) \
  (__builtin_riscv_srl32_u ((a), (b)))
#define __rv_v_sll32(a, b) \
  (__builtin_riscv_sll32 ((a), (b)))
#define __rv_v_ksll32(a, b) \
  (__builtin_riscv_ksll32 ((a), (b)))
#define __rv_v_kslra32(a, b) \
  (__builtin_riscv_kslra32 ((a), (b)))
#define __rv_v_kslra32_u(a, b) \
  (__builtin_riscv_kslra32_u ((a), (b)))
#define __rv_v_smin32(a, b) \
  (__builtin_riscv_smin32 ((a), (b)))
#define __rv_v_umin32(a, b) \
  (__builtin_riscv_umin32 ((a), (b)))
#define __rv_v_smax32(a, b) \
  (__builtin_riscv_smax32 ((a), (b)))
#define __rv_v_umax32(a, b) \
  (__builtin_riscv_umax32 ((a), (b)))
#define __rv_v_kabs32(a) \
  (__builtin_riscv_kabs32 ((a)))
#define __rv_v_khmbb16(a, b) \
  (__builtin_riscv_khmbb16 ((a), (b)))
#define __rv_v_khmbt16(a, b) \
  (__builtin_riscv_khmbt16 ((a), (b)))
#define __rv_v_khmtt16(a, b) \
  (__builtin_riscv_khmtt16 ((a), (b)))
#define __rv_v_kdmbb16(a, b) \
  (__builtin_riscv_kdmbb16 ((a), (b)))
#define __rv_v_kdmbt16(a, b) \
  (__builtin_riscv_kdmbt16 ((a), (b)))
#define __rv_v_kdmtt16(a, b) \
  (__builtin_riscv_kdmtt16 ((a), (b)))
#define __rv_v_smbb32(a, b) \
  (__builtin_riscv_smbb32 ((a), (b)))
#define __rv_v_smbt32(a, b) \
  (__builtin_riscv_smbt32 ((a), (b)))
#define __rv_v_smtt32(a, b) \
  (__builtin_riscv_smtt32 ((a), (b)))
#define __rv_v_kmabb32(r, a, b) \
  (__builtin_riscv_kmabb32 ((r), (a), (b)))
#define __rv_v_kmabt32(r, a, b) \
  (__builtin_riscv_kmabt32 ((r), (a), (b)))
#define __rv_v_kmatt32(r, a, b) \
  (__builtin_riscv_kmatt32 ((r), (a), (b)))
#define __rv_v_kmda32(a, b) \
  (__builtin_riscv_kmda32 ((a), (b)))
#define __rv_v_kmxda32(a, b) \
  (__builtin_riscv_kmxda32 ((a), (b)))
#define __rv_v_kmada32(r, a, b) \
  (__builtin_riscv_kmada32 ((r), (a), (b)))
#define __rv_v_kmaxda32(r, a, b) \
  (__builtin_riscv_kmaxda32 ((r), (a), (b)))
#define __rv_v_kmads32(r, a, b) \
  (__builtin_riscv_kmads32 ((r), (a), (b)))
#define __rv_v_kmadrs32(r, a, b) \
  (__builtin_riscv_kmadrs32 ((r), (a), (b)))
#define __rv_v_kmaxds32(r, a, b) \
  (__builtin_riscv_kmaxds32 ((r), (a), (b)))
#define __rv_v_kmsda32(r, a, b) \
  (__builtin_riscv_kmsda32 ((r), (a), (b)))
#define __rv_v_kmsxda32(r, a, b) \
  (__builtin_riscv_kmsxda32 ((r), (a), (b)))
#define __rv_v_smds32(a, b) \
  (__builtin_riscv_smds32 ((a), (b)))
#define __rv_v_smdrs32(a, b) \
  (__builtin_riscv_smdrs32 ((a), (b)))
#define __rv_v_smxds32(a, b) \
  (__builtin_riscv_smxds32 ((a), (b)))
#define __rv_v_pkbb32(a, b) \
  (__builtin_riscv_pkbb32 ((a), (b)))
#define __rv_v_pkbt32(a, b) \
  (__builtin_riscv_pkbt32 ((a), (b)))
#define __rv_v_pktb32(a, b) \
  (__builtin_riscv_pktb32 ((a), (b)))
#define __rv_v_pktt32(a, b) \
  (__builtin_riscv_pktt32 ((a), (b)))
#define __rv_sraw_u(a, b) \
  (__builtin_riscv_sraw_u ((a), (b)))

#if __riscv_xlen == 32
#define __rv_v_uadd16(a, b) \
  (__builtin_riscv_v_uadd16 ((a), (b)))
#define __rv_v_sadd16(a, b) \
  (__builtin_riscv_v_sadd16 ((a), (b)))
#define __rv_v_radd16(a, b) \
  (__builtin_riscv_v_radd16 ((a), (b)))
#define __rv_v_uradd16(a, b) \
  (__builtin_riscv_v_uradd16 ((a), (b)))
#define __rv_v_kadd16(a, b) \
  (__builtin_riscv_v_kadd16 ((a), (b)))
#define __rv_v_ukadd16(a, b) \
  (__builtin_riscv_v_ukadd16 ((a), (b)))
#define __rv_v_usub16(a, b) \
  (__builtin_riscv_v_usub16 ((a), (b)))
#define __rv_v_ssub16(a, b) \
  (__builtin_riscv_v_ssub16 ((a), (b)))
#define __rv_v_rsub16(a, b) \
  (__builtin_riscv_v_rsub16 ((a), (b)))
#define __rv_v_ursub16(a, b) \
  (__builtin_riscv_v_ursub16 ((a), (b)))
#define __rv_v_ksub16(a, b) \
  (__builtin_riscv_v_ksub16 ((a), (b)))
#define __rv_v_uksub16(a, b) \
  (__builtin_riscv_v_uksub16 ((a), (b)))
#define __rv_v_ucras16(a, b) \
  (__builtin_riscv_v_ucras16 ((a), (b)))
#define __rv_v_scras16(a, b) \
  (__builtin_riscv_v_scras16 ((a), (b)))
#define __rv_v_rcras16(a, b) \
  (__builtin_riscv_v_rcras16 ((a), (b)))
#define __rv_v_urcras16(a, b) \
  (__builtin_riscv_v_urcras16 ((a), (b)))
#define __rv_v_kcras16(a, b) \
  (__builtin_riscv_v_kcras16 ((a), (b)))
#define __rv_v_ukcras16(a, b) \
  (__builtin_riscv_v_ukcras16 ((a), (b)))
#define __rv_v_ucrsa16(a, b) \
  (__builtin_riscv_v_ucrsa16 ((a), (b)))
#define __rv_v_scrsa16(a, b) \
  (__builtin_riscv_v_scrsa16 ((a), (b)))
#define __rv_v_rcrsa16(a, b) \
  (__builtin_riscv_v_rcrsa16 ((a), (b)))
#define __rv_v_urcrsa16(a, b) \
  (__builtin_riscv_v_urcrsa16 ((a), (b)))
#define __rv_v_kcrsa16(a, b) \
  (__builtin_riscv_v_kcrsa16 ((a), (b)))
#define __rv_v_ukcrsa16(a, b) \
  (__builtin_riscv_v_ukcrsa16 ((a), (b)))
#define __rv_v_ustas16(a, b) \
  (__builtin_riscv_v_ustas16 ((a), (b)))
#define __rv_v_sstas16(a, b) \
  (__builtin_riscv_v_sstas16 ((a), (b)))
#define __rv_v_rstas16(a, b) \
  (__builtin_riscv_v_rstas16 ((a), (b)))
#define __rv_v_urstas16(a, b) \
  (__builtin_riscv_v_urstas16 ((a), (b)))
#define __rv_v_kstas16(a, b) \
  (__builtin_riscv_v_kstas16 ((a), (b)))
#define __rv_v_ukstas16(a, b) \
  (__builtin_riscv_v_ukstas16 ((a), (b)))
#define __rv_v_ustsa16(a, b) \
  (__builtin_riscv_v_ustsa16 ((a), (b)))
#define __rv_v_sstsa16(a, b) \
  (__builtin_riscv_v_sstsa16 ((a), (b)))
#define __rv_v_rstsa16(a, b) \
  (__builtin_riscv_v_rstsa16 ((a), (b)))
#define __rv_v_urstsa16(a, b) \
  (__builtin_riscv_v_urstsa16 ((a), (b)))
#define __rv_v_kstsa16(a, b) \
  (__builtin_riscv_v_kstsa16 ((a), (b)))
#define __rv_v_ukstsa16(a, b) \
  (__builtin_riscv_v_ukstsa16 ((a), (b)))
#define __rv_v_uadd8(a, b) \
  (__builtin_riscv_v_uadd8 ((a), (b)))
#define __rv_v_sadd8(a, b) \
  (__builtin_riscv_v_sadd8 ((a), (b)))
#define __rv_v_radd8(a, b) \
  (__builtin_riscv_v_radd8 ((a), (b)))
#define __rv_v_uradd8(a, b) \
  (__builtin_riscv_v_uradd8 ((a), (b)))
#define __rv_v_kadd8(a, b) \
  (__builtin_riscv_v_kadd8 ((a), (b)))
#define __rv_v_ukadd8(a, b) \
  (__builtin_riscv_v_ukadd8 ((a), (b)))
#define __rv_v_usub8(a, b) \
  (__builtin_riscv_v_usub8 ((a), (b)))
#define __rv_v_ssub8(a, b) \
  (__builtin_riscv_v_ssub8 ((a), (b)))
#define __rv_v_rsub8(a, b) \
  (__builtin_riscv_v_rsub8 ((a), (b)))
#define __rv_v_ursub8(a, b) \
  (__builtin_riscv_v_ursub8 ((a), (b)))
#define __rv_v_ksub8(a, b) \
  (__builtin_riscv_v_ksub8 ((a), (b)))
#define __rv_v_uksub8(a, b) \
  (__builtin_riscv_v_uksub8 ((a), (b)))
#define __rv_v_sra16(a, b) \
  (__builtin_riscv_v_sra16 ((a), (b)))
#define __rv_v_sra16_u(a, b) \
  (__builtin_riscv_v_sra16_u ((a), (b)))
#define __rv_v_srl16(a, b) \
  (__builtin_riscv_v_srl16 ((a), (b)))
#define __rv_v_srl16_u(a, b) \
  (__builtin_riscv_v_srl16_u ((a), (b)))
#define __rv_v_sll16(a, b) \
  (__builtin_riscv_v_sll16 ((a), (b)))
#define __rv_v_ksll16(a, b) \
  (__builtin_riscv_v_ksll16 ((a), (b)))
#define __rv_v_kslra16(a, b) \
  (__builtin_riscv_v_kslra16 ((a), (b)))
#define __rv_v_kslra16_u(a, b) \
  (__builtin_riscv_v_kslra16_u ((a), (b)))
#define __rv_v_scmpeq16(a, b) \
  (__builtin_riscv_v_scmpeq16 ((a), (b)))
#define __rv_v_ucmpeq16(a, b) \
  (__builtin_riscv_v_ucmpeq16 ((a), (b)))
#define __rv_v_scmplt16(a, b) \
  (__builtin_riscv_v_scmplt16 ((a), (b)))
#define __rv_v_scmple16(a, b) \
  (__builtin_riscv_v_scmple16 ((a), (b)))
#define __rv_v_ucmplt16(a, b) \
  (__builtin_riscv_v_ucmplt16 ((a), (b)))
#define __rv_v_ucmple16(a, b) \
  (__builtin_riscv_v_ucmple16 ((a), (b)))
#define __rv_v_scmpeq8(a, b) \
  (__builtin_riscv_v_scmpeq8 ((a), (b)))
#define __rv_v_ucmpeq8(a, b) \
  (__builtin_riscv_v_ucmpeq8 ((a), (b)))
#define __rv_v_scmplt8(a, b) \
  (__builtin_riscv_v_scmplt8 ((a), (b)))
#define __rv_v_scmple8(a, b) \
  (__builtin_riscv_v_scmple8 ((a), (b)))
#define __rv_v_ucmplt8(a, b) \
  (__builtin_riscv_v_ucmplt8 ((a), (b)))
#define __rv_v_ucmple8(a, b) \
  (__builtin_riscv_v_ucmple8 ((a), (b)))
#define __rv_v_smin16(a, b) \
  (__builtin_riscv_v_smin16 ((a), (b)))
#define __rv_v_umin16(a, b) \
  (__builtin_riscv_v_umin16 ((a), (b)))
#define __rv_v_smax16(a, b) \
  (__builtin_riscv_v_smax16 ((a), (b)))
#define __rv_v_umax16(a, b) \
  (__builtin_riscv_v_umax16 ((a), (b)))
#define __rv_v_sclip16(a, b) \
  (__builtin_riscv_v_sclip16 ((a), (b)))
#define __rv_v_uclip16(a, b) \
  (__builtin_riscv_v_uclip16 ((a), (b)))
#define __rv_v_khm16(a, b) \
  (__builtin_riscv_v_khm16 ((a), (b)))
#define __rv_v_khmx16(a, b) \
  (__builtin_riscv_v_khmx16 ((a), (b)))
#define __rv_v_khm8(a, b) \
  (__builtin_riscv_v_khm8 ((a), (b)))
#define __rv_v_khmx8(a, b) \
  (__builtin_riscv_v_khmx8 ((a), (b)))
#define __rv_v_kabs16(a) \
  (__builtin_riscv_v_kabs16 ((a)))
#define __rv_v_smin8(a, b) \
  (__builtin_riscv_v_smin8 ((a), (b)))
#define __rv_v_umin8(a, b) \
  (__builtin_riscv_v_umin8 ((a), (b)))
#define __rv_v_smax8(a, b) \
  (__builtin_riscv_v_smax8 ((a), (b)))
#define __rv_v_umax8(a, b) \
  (__builtin_riscv_v_umax8 ((a), (b)))
#define __rv_v_kabs8(a) \
  (__builtin_riscv_v_kabs8 ((a)))
#define __rv_v_sunpkd810(a) \
  (__builtin_riscv_v_sunpkd810 ((a)))
#define __rv_v_sunpkd820(a) \
  (__builtin_riscv_v_sunpkd820 ((a)))
#define __rv_v_sunpkd830(a) \
  (__builtin_riscv_v_sunpkd830 ((a)))
#define __rv_v_sunpkd831(a) \
  (__builtin_riscv_v_sunpkd831 ((a)))
#define __rv_v_sunpkd832(a) \
  (__builtin_riscv_v_sunpkd832 ((a)))
#define __rv_v_zunpkd810(a) \
  (__builtin_riscv_v_zunpkd810 ((a)))
#define __rv_v_zunpkd820(a) \
  (__builtin_riscv_v_zunpkd820 ((a)))
#define __rv_v_zunpkd830(a) \
  (__builtin_riscv_v_zunpkd830 ((a)))
#define __rv_v_zunpkd831(a) \
  (__builtin_riscv_v_zunpkd831 ((a)))
#define __rv_v_zunpkd832(a) \
  (__builtin_riscv_v_zunpkd832 ((a)))
#define __rv_v_pkbb16(a, b) \
  (__builtin_riscv_v_pkbb16 ((a), (b)))
#define __rv_v_pkbt16(a, b) \
  (__builtin_riscv_v_pkbt16 ((a), (b)))
#define __rv_v_pktb16(a, b) \
  (__builtin_riscv_v_pktb16 ((a), (b)))
#define __rv_v_pktt16(a, b) \
  (__builtin_riscv_v_pktt16 ((a), (b)))
#define __rv_v_smmwb(a, b) \
  (__builtin_riscv_v_smmwb ((a), (b)))
#define __rv_v_smmwb_u(a, b) \
  (__builtin_riscv_v_smmwb_u ((a), (b)))
#define __rv_v_smmwt(a, b) \
  (__builtin_riscv_v_smmwt ((a), (b)))
#define __rv_v_smmwt_u(a, b) \
  (__builtin_riscv_v_smmwt_u ((a), (b)))
#define __rv_v_kmmwb2(a, b) \
  (__builtin_riscv_v_kmmwb2 ((a), (b)))
#define __rv_v_kmmwb2_u(a, b) \
  (__builtin_riscv_v_kmmwb2_u ((a), (b)))
#define __rv_v_kmmwt2(a, b) \
  (__builtin_riscv_v_kmmwt2 ((a), (b)))
#define __rv_v_kmmwt2_u(a, b) \
  (__builtin_riscv_v_kmmwt2_u ((a), (b)))
#define __rv_v_kmmawb(r, a, b) \
  (__builtin_riscv_v_kmmawb ((r), (a), (b)))
#define __rv_v_kmmawb_u(r, a, b) \
  (__builtin_riscv_v_kmmawb_u ((r), (a), (b)))
#define __rv_v_kmmawt(r, a, b) \
  (__builtin_riscv_v_kmmawt ((r), (a), (b)))
#define __rv_v_kmmawt_u(r, a, b) \
  (__builtin_riscv_v_kmmawt_u ((r), (a), (b)))
#define __rv_v_kmmawb2(r, a, b) \
  (__builtin_riscv_v_kmmawb2 ((r), (a), (b)))
#define __rv_v_kmmawb2_u(r, a, b) \
  (__builtin_riscv_v_kmmawb2_u ((r), (a), (b)))
#define __rv_v_kmmawt2(r, a, b) \
  (__builtin_riscv_v_kmmawt2 ((r), (a), (b)))
#define __rv_v_kmmawt2_u(r, a, b) \
  (__builtin_riscv_v_kmmawt2_u ((r), (a), (b)))
#define __rv_v_smbb16(a, b) \
  (__builtin_riscv_v_smbb16 ((a), (b)))
#define __rv_v_smbt16(a, b) \
  (__builtin_riscv_v_smbt16 ((a), (b)))
#define __rv_v_smtt16(a, b) \
  (__builtin_riscv_v_smtt16 ((a), (b)))
#define __rv_v_kmda(a, b) \
  (__builtin_riscv_v_kmda ((a), (b)))
#define __rv_v_kmxda(a, b) \
  (__builtin_riscv_v_kmxda ((a), (b)))
#define __rv_v_smds(a, b) \
  (__builtin_riscv_v_smds ((a), (b)))
#define __rv_v_smdrs(a, b) \
  (__builtin_riscv_v_smdrs ((a), (b)))
#define __rv_v_smxds(a, b) \
  (__builtin_riscv_v_smxds ((a), (b)))
#define __rv_v_kmabb(r, a, b) \
  (__builtin_riscv_v_kmabb ((r), (a), (b)))
#define __rv_v_kmabt(r, a, b) \
  (__builtin_riscv_v_kmabt ((r), (a), (b)))
#define __rv_v_kmatt(r, a, b) \
  (__builtin_riscv_v_kmatt ((r), (a), (b)))
#define __rv_v_kmada(r, a, b) \
  (__builtin_riscv_v_kmada ((r), (a), (b)))
#define __rv_v_kmaxda(r, a, b) \
  (__builtin_riscv_v_kmaxda ((r), (a), (b)))
#define __rv_v_kmads(r, a, b) \
  (__builtin_riscv_v_kmads ((r), (a), (b)))
#define __rv_v_kmadrs(r, a, b) \
  (__builtin_riscv_v_kmadrs ((r), (a), (b)))
#define __rv_v_kmaxds(r, a, b) \
  (__builtin_riscv_v_kmaxds ((r), (a), (b)))
#define __rv_v_kmsda(r, a, b) \
  (__builtin_riscv_v_kmsda ((r), (a), (b)))
#define __rv_v_kmsxda(r, a, b) \
  (__builtin_riscv_v_kmsxda ((r), (a), (b)))
#define __rv_v_sra8(a, b) \
  (__builtin_riscv_v_sra8 ((a), (b)))
#define __rv_v_sra8_u(a, b) \
  (__builtin_riscv_v_sra8_u ((a), (b)))
#define __rv_v_srl8(a, b) \
  (__builtin_riscv_v_srl8 ((a), (b)))
#define __rv_v_srl8_u(a, b) \
  (__builtin_riscv_v_srl8_u ((a), (b)))
#define __rv_v_sll8(a, b) \
  (__builtin_riscv_v_sll8 ((a), (b)))
#define __rv_v_ksll8(a, b) \
  (__builtin_riscv_v_ksll8 ((a), (b)))
#define __rv_v_kslra8(a, b) \
  (__builtin_riscv_v_kslra8 ((a), (b)))
#define __rv_v_kslra8_u(a, b) \
  (__builtin_riscv_v_kslra8_u ((a), (b)))
#define __rv_v_swap8(a) \
  (__builtin_riscv_v_swap8 ((a)))
#define __rv_v_swap16(a) \
  (__builtin_riscv_v_pkbt16 ((a), (a)))
#define __rv_v_sclip8(a, b) \
  (__builtin_riscv_v_sclip8 ((a), (b)))
#define __rv_v_uclip8(a, b) \
  (__builtin_riscv_v_uclip8 ((a), (b)))
#define __rv_v_kdmabb(r, a, b) \
  (__builtin_riscv_v_kdmabb ((r), (a), (b)))
#define __rv_v_kdmabt(r, a, b) \
  (__builtin_riscv_v_kdmabt ((r), (a), (b)))
#define __rv_v_kdmatt(r, a, b) \
  (__builtin_riscv_v_kdmatt ((r), (a), (b)))
#define __rv_v_smaqa(r, a, b) \
  (__builtin_riscv_v_smaqa ((r), (a), (b)))
#define __rv_v_umaqa(r, a, b) \
  (__builtin_riscv_v_umaqa ((r), (a), (b)))
#define __rv_v_smaqa_su(r, a, b) \
  (__builtin_riscv_v_smaqa_su ((r), (a), (b)))
#define __rv_v_clrs8(a) \
  (__builtin_riscv_v_clrs8 ((a)))
#define __rv_v_clrs16(a) \
  (__builtin_riscv_v_clrs16 ((a)))
#define __rv_v_clz8(a) \
  (__builtin_riscv_v_clz8 ((a)))
#define __rv_v_clz16(a) \
  (__builtin_riscv_v_clz16 ((a)))
#define __rv_v_kdmbb(a, b) \
  (__builtin_riscv_v_kdmbb ((a), (b)))
#define __rv_v_kdmbt(a, b) \
  (__builtin_riscv_v_kdmbt ((a), (b)))
#define __rv_v_kdmtt(a, b) \
  (__builtin_riscv_v_kdmtt ((a), (b)))
#define __rv_v_khmbb(a, b) \
  (__builtin_riscv_v_khmbb ((a), (b)))
#define __rv_v_khmbt(a, b) \
  (__builtin_riscv_v_khmbt ((a), (b)))
#define __rv_v_khmtt(a, b) \
  (__builtin_riscv_v_khmtt ((a), (b)))
#define __rv_v_pbsad(a, b) \
  (__builtin_riscv_v_pbsad ((a), (b)))
#define __rv_v_pbsada(acc, a, b) \
  (__builtin_riscv_v_pbsada ((acc), (a), (b)))
#else
#define __rv_v_uadd16(a, b) \
  (__builtin_riscv_v64_uadd16 ((a), (b)))
#define __rv_v_sadd16(a, b) \
  (__builtin_riscv_v64_sadd16 ((a), (b)))
#define __rv_v_radd16(a, b) \
  (__builtin_riscv_v64_radd16 ((a), (b)))
#define __rv_v_uradd16(a, b) \
  (__builtin_riscv_v64_uradd16 ((a), (b)))
#define __rv_v_kadd16(a, b) \
  (__builtin_riscv_v64_kadd16 ((a), (b)))
#define __rv_v_ukadd16(a, b) \
  (__builtin_riscv_v64_ukadd16 ((a), (b)))
#define __rv_v_usub16(a, b) \
  (__builtin_riscv_v64_usub16 ((a), (b)))
#define __rv_v_ssub16(a, b) \
  (__builtin_riscv_v64_ssub16 ((a), (b)))
#define __rv_v_rsub16(a, b) \
  (__builtin_riscv_v64_rsub16 ((a), (b)))
#define __rv_v_ursub16(a, b) \
  (__builtin_riscv_v64_ursub16 ((a), (b)))
#define __rv_v_ksub16(a, b) \
  (__builtin_riscv_v64_ksub16 ((a), (b)))
#define __rv_v_uksub16(a, b) \
  (__builtin_riscv_v64_uksub16 ((a), (b)))
#define __rv_v_ucras16(a, b) \
  (__builtin_riscv_v64_ucras16 ((a), (b)))
#define __rv_v_scras16(a, b) \
  (__builtin_riscv_v64_scras16 ((a), (b)))
#define __rv_v_rcras16(a, b) \
  (__builtin_riscv_v64_rcras16 ((a), (b)))
#define __rv_v_urcras16(a, b) \
  (__builtin_riscv_v64_urcras16 ((a), (b)))
#define __rv_v_kcras16(a, b) \
  (__builtin_riscv_v64_kcras16 ((a), (b)))
#define __rv_v_ukcras16(a, b) \
  (__builtin_riscv_v64_ukcras16 ((a), (b)))
#define __rv_v_ucrsa16(a, b) \
  (__builtin_riscv_v64_ucrsa16 ((a), (b)))
#define __rv_v_scrsa16(a, b) \
  (__builtin_riscv_v64_scrsa16 ((a), (b)))
#define __rv_v_rcrsa16(a, b) \
  (__builtin_riscv_v64_rcrsa16 ((a), (b)))
#define __rv_v_urcrsa16(a, b) \
  (__builtin_riscv_v64_urcrsa16 ((a), (b)))
#define __rv_v_kcrsa16(a, b) \
  (__builtin_riscv_v64_kcrsa16 ((a), (b)))
#define __rv_v_ukcrsa16(a, b) \
  (__builtin_riscv_v64_ukcrsa16 ((a), (b)))
#define __rv_v_ustas16(a, b) \
  (__builtin_riscv_v64_ustas16 ((a), (b)))
#define __rv_v_sstas16(a, b) \
  (__builtin_riscv_v64_sstas16 ((a), (b)))
#define __rv_v_rstas16(a, b) \
  (__builtin_riscv_v64_rstas16 ((a), (b)))
#define __rv_v_urstas16(a, b) \
  (__builtin_riscv_v64_urstas16 ((a), (b)))
#define __rv_v_kstas16(a, b) \
  (__builtin_riscv_v64_kstas16 ((a), (b)))
#define __rv_v_ukstas16(a, b) \
  (__builtin_riscv_v64_ukstas16 ((a), (b)))
#define __rv_v_ustsa16(a, b) \
  (__builtin_riscv_v64_ustsa16 ((a), (b)))
#define __rv_v_sstsa16(a, b) \
  (__builtin_riscv_v64_sstsa16 ((a), (b)))
#define __rv_v_rstsa16(a, b) \
  (__builtin_riscv_v64_rstsa16 ((a), (b)))
#define __rv_v_urstsa16(a, b) \
  (__builtin_riscv_v64_urstsa16 ((a), (b)))
#define __rv_v_kstsa16(a, b) \
  (__builtin_riscv_v64_kstsa16 ((a), (b)))
#define __rv_v_ukstsa16(a, b) \
  (__builtin_riscv_v64_ukstsa16 ((a), (b)))
#define __rv_v_uadd8(a, b) \
  (__builtin_riscv_v64_uadd8 ((a), (b)))
#define __rv_v_sadd8(a, b) \
  (__builtin_riscv_v64_sadd8 ((a), (b)))
#define __rv_v_radd8(a, b) \
  (__builtin_riscv_v64_radd8 ((a), (b)))
#define __rv_v_uradd8(a, b) \
  (__builtin_riscv_v64_uradd8 ((a), (b)))
#define __rv_v_kadd8(a, b) \
  (__builtin_riscv_v64_kadd8 ((a), (b)))
#define __rv_v_ukadd8(a, b) \
  (__builtin_riscv_v64_ukadd8 ((a), (b)))
#define __rv_v_usub8(a, b) \
  (__builtin_riscv_v64_usub8 ((a), (b)))
#define __rv_v_ssub8(a, b) \
  (__builtin_riscv_v64_ssub8 ((a), (b)))
#define __rv_v_rsub8(a, b) \
  (__builtin_riscv_v64_rsub8 ((a), (b)))
#define __rv_v_ursub8(a, b) \
  (__builtin_riscv_v64_ursub8 ((a), (b)))
#define __rv_v_ksub8(a, b) \
  (__builtin_riscv_v64_ksub8 ((a), (b)))
#define __rv_v_uksub8(a, b) \
  (__builtin_riscv_v64_uksub8 ((a), (b)))
#define __rv_v_sra16(a, b) \
  (__builtin_riscv_v64_sra16 ((a), (b)))
#define __rv_v_sra16_u(a, b) \
  (__builtin_riscv_v64_sra16_u ((a), (b)))
#define __rv_v_srl16(a, b) \
  (__builtin_riscv_v64_srl16 ((a), (b)))
#define __rv_v_srl16_u(a, b) \
  (__builtin_riscv_v64_srl16_u ((a), (b)))
#define __rv_v_sll16(a, b) \
  (__builtin_riscv_v64_sll16 ((a), (b)))
#define __rv_v_ksll16(a, b) \
  (__builtin_riscv_v64_ksll16 ((a), (b)))
#define __rv_v_kslra16(a, b) \
  (__builtin_riscv_v64_kslra16 ((a), (b)))
#define __rv_v_kslra16_u(a, b) \
  (__builtin_riscv_v64_kslra16_u ((a), (b)))
#define __rv_v_scmpeq16(a, b) \
  (__builtin_riscv_v64_scmpeq16 ((a), (b)))
#define __rv_v_ucmpeq16(a, b) \
  (__builtin_riscv_v64_ucmpeq16 ((a), (b)))
#define __rv_v_scmplt16(a, b) \
  (__builtin_riscv_v64_scmplt16 ((a), (b)))
#define __rv_v_scmple16(a, b) \
  (__builtin_riscv_v64_scmple16 ((a), (b)))
#define __rv_v_ucmplt16(a, b) \
  (__builtin_riscv_v64_ucmplt16 ((a), (b)))
#define __rv_v_ucmple16(a, b) \
  (__builtin_riscv_v64_ucmple16 ((a), (b)))
#define __rv_v_scmpeq8(a, b) \
  (__builtin_riscv_v64_scmpeq8 ((a), (b)))
#define __rv_v_ucmpeq8(a, b) \
  (__builtin_riscv_v64_ucmpeq8 ((a), (b)))
#define __rv_v_scmplt8(a, b) \
  (__builtin_riscv_v64_scmplt8 ((a), (b)))
#define __rv_v_scmple8(a, b) \
  (__builtin_riscv_v64_scmple8 ((a), (b)))
#define __rv_v_ucmplt8(a, b) \
  (__builtin_riscv_v64_ucmplt8 ((a), (b)))
#define __rv_v_ucmple8(a, b) \
  (__builtin_riscv_v64_ucmple8 ((a), (b)))
#define __rv_v_smin16(a, b) \
  (__builtin_riscv_v64_smin16 ((a), (b)))
#define __rv_v_umin16(a, b) \
  (__builtin_riscv_v64_umin16 ((a), (b)))
#define __rv_v_smax16(a, b) \
  (__builtin_riscv_v64_smax16 ((a), (b)))
#define __rv_v_umax16(a, b) \
  (__builtin_riscv_v64_umax16 ((a), (b)))
#define __rv_v_sclip16(a, b) \
  (__builtin_riscv_v64_sclip16 ((a), (b)))
#define __rv_v_uclip16(a, b) \
  (__builtin_riscv_v64_uclip16 ((a), (b)))
#define __rv_v_khm16(a, b) \
  (__builtin_riscv_v64_khm16 ((a), (b)))
#define __rv_v_khmx16(a, b) \
  (__builtin_riscv_v64_khmx16 ((a), (b)))
#define __rv_v_khm8(a, b) \
  (__builtin_riscv_v64_khm8 ((a), (b)))
#define __rv_v_khmx8(a, b) \
  (__builtin_riscv_v64_khmx8 ((a), (b)))
#define __rv_v_kabs16(a) \
  (__builtin_riscv_v64_kabs16 ((a)))
#define __rv_v_smin8(a, b) \
  (__builtin_riscv_v64_smin8 ((a), (b)))
#define __rv_v_umin8(a, b) \
  (__builtin_riscv_v64_umin8 ((a), (b)))
#define __rv_v_smax8(a, b) \
  (__builtin_riscv_v64_smax8 ((a), (b)))
#define __rv_v_umax8(a, b) \
  (__builtin_riscv_v64_umax8 ((a), (b)))
#define __rv_v_kabs8(a) \
  (__builtin_riscv_v64_kabs8 ((a)))
#define __rv_v_sunpkd810(a) \
  (__builtin_riscv_v64_sunpkd810 ((a)))
#define __rv_v_sunpkd820(a) \
  (__builtin_riscv_v64_sunpkd820 ((a)))
#define __rv_v_sunpkd830(a) \
  (__builtin_riscv_v64_sunpkd830 ((a)))
#define __rv_v_sunpkd831(a) \
  (__builtin_riscv_v64_sunpkd831 ((a)))
#define __rv_v_sunpkd832(a) \
  (__builtin_riscv_v64_sunpkd832 ((a)))
#define __rv_v_zunpkd810(a) \
  (__builtin_riscv_v64_zunpkd810 ((a)))
#define __rv_v_zunpkd820(a) \
  (__builtin_riscv_v64_zunpkd820 ((a)))
#define __rv_v_zunpkd830(a) \
  (__builtin_riscv_v64_zunpkd830 ((a)))
#define __rv_v_zunpkd831(a) \
  (__builtin_riscv_v64_zunpkd831 ((a)))
#define __rv_v_zunpkd832(a) \
  (__builtin_riscv_v64_zunpkd832 ((a)))
#define __rv_v_pkbb16(a, b) \
  (__builtin_riscv_v64_pkbb16 ((a), (b)))
#define __rv_v_pkbt16(a, b) \
  (__builtin_riscv_v64_pkbt16 ((a), (b)))
#define __rv_v_pktb16(a, b) \
  (__builtin_riscv_v64_pktb16 ((a), (b)))
#define __rv_v_pktt16(a, b) \
  (__builtin_riscv_v64_pktt16 ((a), (b)))
#define __rv_v_smmwb(a, b) \
  (__builtin_riscv_v64_smmwb ((a), (b)))
#define __rv_v_smmwb_u(a, b) \
  (__builtin_riscv_v64_smmwb_u ((a), (b)))
#define __rv_v_smmwt(a, b) \
  (__builtin_riscv_v64_smmwt ((a), (b)))
#define __rv_v_smmwt_u(a, b) \
  (__builtin_riscv_v64_smmwt_u ((a), (b)))
#define __rv_v_kmmwb2(a, b) \
  (__builtin_riscv_v64_kmmwb2 ((a), (b)))
#define __rv_v_kmmwb2_u(a, b) \
  (__builtin_riscv_v64_kmmwb2_u ((a), (b)))
#define __rv_v_kmmwt2(a, b) \
  (__builtin_riscv_v64_kmmwt2 ((a), (b)))
#define __rv_v_kmmwt2_u(a, b) \
  (__builtin_riscv_v64_kmmwt2_u ((a), (b)))
#define __rv_v_kmmawb(r, a, b) \
  (__builtin_riscv_v64_kmmawb ((r), (a), (b)))
#define __rv_v_kmmawb_u(r, a, b) \
  (__builtin_riscv_v64_kmmawb_u ((r), (a), (b)))
#define __rv_v_kmmawt(r, a, b) \
  (__builtin_riscv_v64_kmmawt ((r), (a), (b)))
#define __rv_v_kmmawt_u(r, a, b) \
  (__builtin_riscv_v64_kmmawt_u ((r), (a), (b)))
#define __rv_v_kmmawb2(r, a, b) \
  (__builtin_riscv_v64_kmmawb2 ((r), (a), (b)))
#define __rv_v_kmmawb2_u(r, a, b) \
  (__builtin_riscv_v64_kmmawb2_u ((r), (a), (b)))
#define __rv_v_kmmawt2(r, a, b) \
  (__builtin_riscv_v64_kmmawt2 ((r), (a), (b)))
#define __rv_v_kmmawt2_u(r, a, b) \
  (__builtin_riscv_v64_kmmawt2_u ((r), (a), (b)))
#define __rv_v_smbb16(a, b) \
  (__builtin_riscv_v64_smbb16 ((a), (b)))
#define __rv_v_smbt16(a, b) \
  (__builtin_riscv_v64_smbt16 ((a), (b)))
#define __rv_v_smtt16(a, b) \
  (__builtin_riscv_v64_smtt16 ((a), (b)))
#define __rv_v_kmda(a, b) \
  (__builtin_riscv_v64_kmda ((a), (b)))
#define __rv_v_kmxda(a, b) \
  (__builtin_riscv_v64_kmxda ((a), (b)))
#define __rv_v_smds(a, b) \
  (__builtin_riscv_v64_smds ((a), (b)))
#define __rv_v_smdrs(a, b) \
  (__builtin_riscv_v64_smdrs ((a), (b)))
#define __rv_v_smxds(a, b) \
  (__builtin_riscv_v64_smxds ((a), (b)))
#define __rv_v_kmabb(r, a, b) \
  (__builtin_riscv_v64_kmabb ((r), (a), (b)))
#define __rv_v_kmabt(r, a, b) \
  (__builtin_riscv_v64_kmabt ((r), (a), (b)))
#define __rv_v_kmatt(r, a, b) \
  (__builtin_riscv_v64_kmatt ((r), (a), (b)))
#define __rv_v_kmada(r, a, b) \
  (__builtin_riscv_v64_kmada ((r), (a), (b)))
#define __rv_v_kmaxda(r, a, b) \
  (__builtin_riscv_v64_kmaxda ((r), (a), (b)))
#define __rv_v_kmads(r, a, b) \
  (__builtin_riscv_v64_kmads ((r), (a), (b)))
#define __rv_v_kmadrs(r, a, b) \
  (__builtin_riscv_v64_kmadrs ((r), (a), (b)))
#define __rv_v_kmaxds(r, a, b) \
  (__builtin_riscv_v64_kmaxds ((r), (a), (b)))
#define __rv_v_kmsda(r, a, b) \
  (__builtin_riscv_v64_kmsda ((r), (a), (b)))
#define __rv_v_kmsxda(r, a, b) \
  (__builtin_riscv_v64_kmsxda ((r), (a), (b)))
#define __rv_v_sra8(a, b) \
  (__builtin_riscv_v64_sra8 ((a), (b)))
#define __rv_v_sra8_u(a, b) \
  (__builtin_riscv_v64_sra8_u ((a), (b)))
#define __rv_v_srl8(a, b) \
  (__builtin_riscv_v64_srl8 ((a), (b)))
#define __rv_v_srl8_u(a, b) \
  (__builtin_riscv_v64_srl8_u ((a), (b)))
#define __rv_v_sll8(a, b) \
  (__builtin_riscv_v64_sll8 ((a), (b)))
#define __rv_v_ksll8(a, b) \
  (__builtin_riscv_v64_ksll8 ((a), (b)))
#define __rv_v_kslra8(a, b) \
  (__builtin_riscv_v64_kslra8 ((a), (b)))
#define __rv_v_kslra8_u(a, b) \
  (__builtin_riscv_v64_kslra8_u ((a), (b)))
#define __rv_v_sclip8(a, b) \
  (__builtin_riscv_v64_sclip8 ((a), (b)))
#define __rv_v_uclip8(a, b) \
  (__builtin_riscv_v64_uclip8 ((a), (b)))
#define __rv_v_kdmabb(r, a, b) \
  (__builtin_riscv_v64_kdmabb ((r), (a), (b)))
#define __rv_v_kdmabt(r, a, b) \
  (__builtin_riscv_v64_kdmabt ((r), (a), (b)))
#define __rv_v_kdmatt(r, a, b) \
  (__builtin_riscv_v64_kdmatt ((r), (a), (b)))
#define __rv_v_kdmabb16(r, a, b) \
  (__builtin_riscv_v64_kdmabb16 ((r), (a), (b)))
#define __rv_v_kdmabt16(r, a, b) \
  (__builtin_riscv_v64_kdmabt16 ((r), (a), (b)))
#define __rv_v_kdmatt16(r, a, b) \
  (__builtin_riscv_v64_kdmatt16 ((r), (a), (b)))
#define __rv_v_smaqa(r, a, b) \
  (__builtin_riscv_v64_smaqa ((r), (a), (b)))
#define __rv_v_umaqa(r, a, b) \
  (__builtin_riscv_v64_umaqa ((r), (a), (b)))
#define __rv_v_smaqa_su(r, a, b) \
  (__builtin_riscv_v64_smaqa_su ((r), (a), (b)))
#define __rv_v_clrs8(a) \
  (__builtin_riscv_v64_clrs8 ((a)))
#define __rv_v_clrs16(a) \
  (__builtin_riscv_v64_clrs16 ((a)))
#define __rv_v_clrs32(a) \
  (__builtin_riscv_v64_clrs32 ((a)))
#define __rv_v_clz8(a) \
  (__builtin_riscv_v64_clz8 ((a)))
#define __rv_v_clz16(a) \
  (__builtin_riscv_v64_clz16 ((a)))
#define __rv_v_clz32(a) \
  (__builtin_riscv_v64_clz32 ((a)))
#define __rv_v_swap8(a) \
  (__builtin_riscv_v64_swap8 ((a)))
#define __rv_v_swap16(a) \
  (__builtin_riscv_v64_pkbt16 ((a), (a)))
#define __rv_v_kdmbb(a, b) \
  (__builtin_riscv_v64_kdmbb ((a), (b)))
#define __rv_v_kdmbt(a, b) \
  (__builtin_riscv_v64_kdmbt ((a), (b)))
#define __rv_v_kdmtt(a, b) \
  (__builtin_riscv_v64_kdmtt ((a), (b)))
#define __rv_v_khmbb(a, b) \
  (__builtin_riscv_v64_khmbb ((a), (b)))
#define __rv_v_khmbt(a, b) \
  (__builtin_riscv_v64_khmbt ((a), (b)))
#define __rv_v_khmtt(a, b) \
  (__builtin_riscv_v64_khmtt ((a), (b)))
#define __rv_v_smmul(a, b) \
  (__builtin_riscv_v64_smmul ((a), (b)))
#define __rv_v_smmul_u(a, b) \
  (__builtin_riscv_v64_smmul_u ((a), (b)))
#define __rv_v_kwmmul(a, b) \
  (__builtin_riscv_v64_kwmmul ((a), (b)))
#define __rv_v_kwmmul_u(a, b) \
  (__builtin_riscv_v64_kwmmul_u ((a), (b)))
#define __rv_v_kmmac(r, a, b) \
  (__builtin_riscv_v64_kmmac ((r), (a), (b)))
#define __rv_v_kmmac_u(r, a, b) \
  (__builtin_riscv_v64_kmmac_u ((r), (a), (b)))
#define __rv_v_kmmsb(r, a, b) \
  (__builtin_riscv_v64_kmmsb ((r), (a), (b)))
#define __rv_v_kmmsb_u(r, a, b) \
  (__builtin_riscv_v64_kmmsb_u ((r), (a), (b)))
#define __rv_v_uclip32(a, imm) \
  (__builtin_riscv_v64_uclip32 ((a), (imm)))
#define __rv_v_sclip32(a, imm) \
  (__builtin_riscv_v64_sclip32 ((a), (imm)))
#define __rv_v_pbsad(a, b) \
  (__builtin_riscv_v64_pbsad ((a), (b)))
#define __rv_v_pbsada(acc, a, b) \
  (__builtin_riscv_v64_pbsada ((acc), (a), (b)))
#endif

#if defined(__riscv_zpsf)
#define __rv_smal(a, b) \
  (__builtin_riscv_smal ((a), (b)))
#define __rv_radd64(a, b) \
  (__builtin_riscv_radd64 ((a), (b)))
#define __rv_uradd64(a, b) \
  (__builtin_riscv_uradd64 ((a), (b)))
#define __rv_kadd64(a, b) \
  (__builtin_riscv_kadd64 ((a), (b)))
#define __rv_ukadd64(a, b) \
  (__builtin_riscv_ukadd64 ((a), (b)))
#define __rv_ssub64(a, b) \
  (__builtin_riscv_ssub64 ((a), (b)))
#define __rv_usub64(a, b) \
  (__builtin_riscv_usub64 ((a), (b)))
#define __rv_rsub64(a, b) \
  (__builtin_riscv_rsub64 ((a), (b)))
#define __rv_ursub64(a, b) \
  (__builtin_riscv_ursub64 ((a), (b)))
#define __rv_ksub64(a, b) \
  (__builtin_riscv_ksub64 ((a), (b)))
#define __rv_uksub64(a, b) \
  (__builtin_riscv_uksub64 ((a), (b)))
#define __rv_smul16(a, b) \
  (__builtin_riscv_smul16 ((a), (b)))
#define __rv_umul16(a, b) \
  (__builtin_riscv_umul16 ((a), (b)))
#define __rv_smul8(a, b) \
  (__builtin_riscv_smul8 ((a), (b)))
#define __rv_umul8(a, b) \
  (__builtin_riscv_umul8 ((a), (b)))
#define __rv_smulx16(a, b) \
  (__builtin_riscv_smulx16 ((a), (b)))
#define __rv_smulx8(a, b) \
  (__builtin_riscv_smulx8 ((a), (b)))
#define __rv_umulx16(a, b) \
  (__builtin_riscv_umulx16 ((a), (b)))
#define __rv_umulx8(a, b) \
  (__builtin_riscv_umulx8 ((a), (b)))
#define __rv_smar64(r, a, b) \
  (__builtin_riscv_smar64 ((r), (a), (b)))
#define __rv_smsr64(r, a, b) \
  (__builtin_riscv_smsr64 ((r), (a), (b)))
#define __rv_umar64(r, a, b) \
  (__builtin_riscv_umar64 ((r), (a), (b)))
#define __rv_umsr64(r, a, b) \
  (__builtin_riscv_umsr64 ((r), (a), (b)))
#define __rv_kmar64(r, a, b) \
  (__builtin_riscv_kmar64 ((r), (a), (b)))
#define __rv_kmsr64(r, a, b) \
  (__builtin_riscv_kmsr64 ((r), (a), (b)))
#define __rv_ukmar64(r, a, b) \
  (__builtin_riscv_ukmar64 ((r), (a), (b)))
#define __rv_ukmsr64(r, a, b) \
  (__builtin_riscv_ukmsr64 ((r), (a), (b)))
#define __rv_maddr32(t, a, b) \
  (__builtin_riscv_maddr32 ((t), (a), (b)))
#define __rv_msubr32(t, a, b) \
  (__builtin_riscv_msubr32 ((t), (a), (b)))
#define __rv_smalbb(r, a, b) \
  (__builtin_riscv_smalbb ((r), (a), (b)))
#define __rv_smalbt(r, a, b) \
  (__builtin_riscv_smalbt ((r), (a), (b)))
#define __rv_smaltt(r, a, b) \
  (__builtin_riscv_smaltt ((r), (a), (b)))
#define __rv_smalda(r, a, b) \
  (__builtin_riscv_smalda ((r), (a), (b)))
#define __rv_smalxda(r, a, b) \
  (__builtin_riscv_smalxda ((r), (a), (b)))
#define __rv_smalds(r, a, b) \
  (__builtin_riscv_smalds ((r), (a), (b)))
#define __rv_smaldrs(r, a, b) \
  (__builtin_riscv_smaldrs ((r), (a), (b)))
#define __rv_smalxds(r, a, b) \
  (__builtin_riscv_smalxds ((r), (a), (b)))
#define __rv_smslda(r, a, b) \
  (__builtin_riscv_smslda ((r), (a), (b)))
#define __rv_smslxda(r, a, b) \
  (__builtin_riscv_smslxda ((r), (a), (b)))
#define __rv_wext(a, b) \
  (__builtin_riscv_wext ((a), (b)))
#define __rv_v_smul16(a, b) \
  (__builtin_riscv_v_smul16 ((a), (b)))
#define __rv_v_smulx16(a, b) \
  (__builtin_riscv_v_smulx16 ((a), (b)))
#define __rv_v_umul16(a, b) \
  (__builtin_riscv_v_umul16 ((a), (b)))
#define __rv_v_smul8(a, b) \
  (__builtin_riscv_v_smul8 ((a), (b)))
#define __rv_v_umul8(a, b) \
  (__builtin_riscv_v_umul8 ((a), (b)))
#define __rv_v_smulx8(a, b) \
  (__builtin_riscv_v_smulx8 ((a), (b)))
#define __rv_v_umulx16(a, b) \
  (__builtin_riscv_v_umulx16 ((a), (b)))
#define __rv_v_umulx8(a, b) \
  (__builtin_riscv_v_umulx8 ((a), (b)))
#define __rv_sadd64(a, b) \
  (__builtin_riscv_sadd64 ((a), (b)))
#define __rv_uadd64(a, b) \
  (__builtin_riscv_uadd64 ((a), (b)))
#define __rv_mulr64(a, b) \
  (__builtin_riscv_mulr64 ((a), (b)))
#define __rv_mulsr64(a, b) \
  (__builtin_riscv_mulsr64 ((a), (b)))
#if __riscv_xlen == 32
#define __rv_v_smal(a, b) \
  (__builtin_riscv_v_smal ((a), (b)))
#define __rv_v_smalbb(r, a, b) \
  (__builtin_riscv_v_smalbb ((r), (a), (b)))
#define __rv_v_smalbt(r, a, b) \
  (__builtin_riscv_v_smalbt ((r), (a), (b)))
#define __rv_v_smaltt(r, a, b) \
  (__builtin_riscv_v_smaltt ((r), (a), (b)))
#define __rv_v_smalda(r, a, b) \
  (__builtin_riscv_v_smalda ((r), (a), (b)))
#define __rv_v_smalxda(r, a, b) \
  (__builtin_riscv_v_smalxda ((r), (a), (b)))
#define __rv_v_smalds(r, a, b) \
  (__builtin_riscv_v_smalds ((r), (a), (b)))
#define __rv_v_smaldrs(r, a, b) \
  (__builtin_riscv_v_smaldrs ((r), (a), (b)))
#define __rv_v_smalxds(r, a, b) \
  (__builtin_riscv_v_smalxds ((r), (a), (b)))
#define __rv_v_smslda(r, a, b) \
  (__builtin_riscv_v_smslda ((r), (a), (b)))
#define __rv_v_smslxda(r, a, b) \
  (__builtin_riscv_v_smslxda ((r), (a), (b)))
#else
#define __rv_v_smal(a, b) \
  (__builtin_riscv_v64_smal ((a), (b)))
#define __rv_v_smalbb(r, a, b) \
  (__builtin_riscv_v64_smalbb ((r), (a), (b)))
#define __rv_v_smalbt(r, a, b) \
  (__builtin_riscv_v64_smalbt ((r), (a), (b)))
#define __rv_v_smaltt(r, a, b) \
  (__builtin_riscv_v64_smaltt ((r), (a), (b)))
#define __rv_v_smalda(r, a, b) \
  (__builtin_riscv_v64_smalda ((r), (a), (b)))
#define __rv_v_smalxda(r, a, b) \
  (__builtin_riscv_v64_smalxda ((r), (a), (b)))
#define __rv_v_smalds(r, a, b) \
  (__builtin_riscv_v64_smalds ((r), (a), (b)))
#define __rv_v_smaldrs(r, a, b) \
  (__builtin_riscv_v64_smaldrs ((r), (a), (b)))
#define __rv_v_smalxds(r, a, b) \
  (__builtin_riscv_v64_smalxds ((r), (a), (b)))
#define __rv_v_smslda(r, a, b) \
  (__builtin_riscv_v64_smslda ((r), (a), (b)))
#define __rv_v_smslxda(r, a, b) \
  (__builtin_riscv_v64_smslxda ((r), (a), (b)))
#define __rv_v_smar64(r, a, b) \
  (__builtin_riscv_v64_smar64 ((r), (a), (b)))
#define __rv_v_smsr64(r, a, b) \
  (__builtin_riscv_v64_smsr64 ((r), (a), (b)))
#define __rv_v_umar64(r, a, b) \
  (__builtin_riscv_v64_umar64 ((r), (a), (b)))
#define __rv_v_umsr64(r, a, b) \
  (__builtin_riscv_v64_umsr64 ((r), (a), (b)))
#define __rv_v_kmar64(r, a, b) \
  (__builtin_riscv_v64_kmar64 ((r), (a), (b)))
#define __rv_v_kmsr64(r, a, b) \
  (__builtin_riscv_v64_kmsr64 ((r), (a), (b)))
#define __rv_v_ukmar64(r, a, b) \
  (__builtin_riscv_v64_ukmar64 ((r), (a), (b)))
#define __rv_v_ukmsr64(r, a, b) \
  (__builtin_riscv_v64_ukmsr64 ((r), (a), (b)))
#endif
#endif
#endif // END OF _RISCV_RVP_INTRINSIC_H