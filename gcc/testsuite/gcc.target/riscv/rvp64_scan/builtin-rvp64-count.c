/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>


#if __riscv_xlen == 64
typedef uint64_t uintXLEN_t;
typedef uint8x8_t vxUQI;
typedef int8x8_t vxQI;
typedef uint16x4_t vxUHI;
typedef int16x4_t vxHI;
#else
typedef uint32_t uintXLEN_t;
typedef uint8x4_t vxUQI;
typedef int8x4_t vxQI;
typedef uint16x2_t vxUHI;
typedef int16x2_t vxHI;
#endif

static __attribute__ ((noinline))
uintXLEN_t foo(uintXLEN_t a) {
  return __rv_clrs8 (a);
}

static __attribute__ ((noinline))
uintXLEN_t foo1(uintXLEN_t a) {
  return __rv_clrs16 (a);
}

static __attribute__ ((noinline))
uintXLEN_t foo2(uintXLEN_t a) {
  return __rv_clrs32 (a);
}

static __attribute__ ((noinline))
uintXLEN_t foo3(uintXLEN_t a) {
  return __rv_clz8 (a);
}

static __attribute__ ((noinline))
uintXLEN_t foo4(uintXLEN_t a) {
  return __rv_clz16 (a);
}

static __attribute__ ((noinline))
uintXLEN_t foo5(uintXLEN_t a) {
  return __rv_clz32 (a);
}

static __attribute__ ((noinline))
vxUQI foo6(vxQI a) {
  return __rv_v_clrs8 (a);
}

static __attribute__ ((noinline))
vxUHI foo7(vxHI a) {
  return __rv_v_clrs16 (a);
}

static __attribute__ ((noinline))
uint32x2_t foo8(int32x2_t a) {
  return __rv_v_clrs32 (a);
}

static __attribute__ ((noinline))
vxUQI foo9(vxUQI a) {
  return __rv_v_clz8 (a);
}

static __attribute__ ((noinline))
vxUHI foo10(vxUHI a) {
  return __rv_v_clz16 (a);
}

static __attribute__ ((noinline))
uint32x2_t foo11(uint32x2_t a) {
  return __rv_v_clz32 (a);
}

/* { dg-final { scan-assembler-times "clrs8" 2 } } */
/* { dg-final { scan-assembler-times "clrs16" 2 } } */
/* { dg-final { scan-assembler-times "clrs32" 2 } } */
/* { dg-final { scan-assembler-times "clz8" 2 } } */
/* { dg-final { scan-assembler-times "clz16" 2 } } */
/* { dg-final { scan-assembler-times "clz32" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
