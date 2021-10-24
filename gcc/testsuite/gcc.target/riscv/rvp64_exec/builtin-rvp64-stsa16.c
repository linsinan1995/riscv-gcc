/* This is a test program for srli32u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>


#if __riscv_xlen == 64
typedef uint64_t uintXLEN_t;
typedef uint16x4_t vxUHI;
typedef int16x4_t vxHI;
#else
typedef uint32_t uintXLEN_t;
typedef uint16x2_t vxUHI;
typedef int16x2_t vxHI;
#endif

static __attribute__ ((noinline))
uintXLEN_t foo(uintXLEN_t a, uintXLEN_t b) {
  return __rv_stsa16 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo2(uintXLEN_t a, uintXLEN_t b) {
  return __rv_rstsa16 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo3(uintXLEN_t a, uintXLEN_t b) {
  return __rv_urstsa16 (a, b);
}

static __attribute__ ((noinline))
vxUHI foo4(vxUHI a, vxUHI b) {
  return __rv_v_ustsa16 (a, b);
}

static __attribute__ ((noinline))
vxHI foo5(vxHI a, vxHI b) {
  return __rv_v_sstsa16 (a, b);
}

static __attribute__ ((noinline))
vxHI foo6(vxHI a, vxHI b) {
  return __rv_v_rstsa16 (a, b);
}

static __attribute__ ((noinline))
vxUHI foo7(vxUHI a, vxUHI b) {
  return __rv_v_urstsa16 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo8(uintXLEN_t a, uintXLEN_t b) {
  return __rv_kstsa16 (a, b);
}

static __attribute__ ((noinline))
vxHI foo9(vxHI a, vxHI b) {
  return __rv_v_kstsa16 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo10(uintXLEN_t a, uintXLEN_t b) {
  return __rv_ukstsa16 (a, b);
}

static __attribute__ ((noinline))
vxUHI foo11(vxUHI a, vxUHI b) {
  return __rv_v_ukstsa16 (a, b);
}
