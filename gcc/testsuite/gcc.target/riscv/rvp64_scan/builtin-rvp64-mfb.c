/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>


#if __riscv_xlen == 64
typedef uint64_t uintXLEN_t;
typedef int64_t intXLEN_t;
typedef uint8x8_t vxUQI;
typedef int8x8_t vxQI;
typedef uint16x4_t vxUHI;
typedef int16x4_t vxHI;
typedef int32x2_t vxSI;
typedef uint32x2_t vxUSI;
#else
typedef uint32_t uintXLEN_t;
typedef int32_t intXLEN_t;
typedef uint8x4_t vxUQI;
typedef int8x4_t vxQI;
typedef uint16x2_t vxUHI;
typedef int16x2_t vxHI;
typedef int32_t vxSI;
typedef uint32_t vxUSI;
#endif

static __attribute__ ((noinline))
intXLEN_t foo(intXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
  return __rv_smaqa (t, a, b);
}

static __attribute__ ((noinline))
intXLEN_t foo1(intXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
  return __rv_smaqa_su (t, a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo2(intXLEN_t t, uintXLEN_t a, uintXLEN_t b) {
  return __rv_umaqa (t, a, b);
}

static __attribute__ ((noinline))
vxSI foo3(vxSI t, vxQI a, vxQI b) {
  return __rv_v_smaqa (t, a, b);
}

static __attribute__ ((noinline))
vxSI foo4(vxSI t, vxQI a, vxUQI b) {
  return __rv_v_smaqa_su (t, a, b);
}

static __attribute__ ((noinline))
vxUSI foo5(vxUSI t, vxUQI a, vxUQI b) {
  return __rv_v_umaqa (t, a, b);
}

/* { dg-final { scan-assembler-times "smaqa.su" 2 } } */
/* { dg-final { scan-assembler-times "smaqa" 4 } } */
/* { dg-final { scan-assembler-times "umaqa" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
