/* stsa32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for stsa32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint64_t uintXLEN_t;
typedef uint32x2_t vxUSI;
typedef int32x2_t vxSI;

static __attribute__ ((noinline))
uintXLEN_t foo(uintXLEN_t a, uintXLEN_t b) {
  return __rv_stsa32 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo2(uintXLEN_t a, uintXLEN_t b) {
  return __rv_rstsa32 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo3(uintXLEN_t a, uintXLEN_t b) {
  return __rv_urstsa32 (a, b);
}

static __attribute__ ((noinline))
vxUSI foo4(vxUSI a, vxUSI b) {
  return __rv_v_ustsa32 (a, b);
}

static __attribute__ ((noinline))
vxSI foo5(vxSI a, vxSI b) {
  return __rv_v_sstsa32 (a, b);
}

static __attribute__ ((noinline))
vxSI foo6(vxSI a, vxSI b) {
  return __rv_v_rstsa32 (a, b);
}

static __attribute__ ((noinline))
vxUSI foo7(vxUSI a, vxUSI b) {
  return __rv_v_urstsa32 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo8(uintXLEN_t a, uintXLEN_t b) {
  return __rv_kstsa32 (a, b);
}

static __attribute__ ((noinline))
vxSI foo9(vxSI a, vxSI b) {
  return __rv_v_kstsa32 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo10(uintXLEN_t a, uintXLEN_t b) {
  return __rv_ukstsa32 (a, b);
}

static __attribute__ ((noinline))
vxUSI foo11(vxUSI a, vxUSI b) {
  return __rv_v_ukstsa32 (a, b);
}

/* { dg-final { scan-assembler-times "stsa32" 12 } } */
/* { dg-final { scan-assembler-times "rstsa32" 4 } } */
/* { dg-final { scan-assembler-times "urstsa32" 2 } } */
/* { dg-final { scan-assembler-times "kstsa32" 4 } } */
/* { dg-final { scan-assembler-times "ukstsa32" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
