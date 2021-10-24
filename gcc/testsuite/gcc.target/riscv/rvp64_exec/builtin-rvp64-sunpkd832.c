/* This is a test program for sunpkd832 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t sunpkd832 (uint64_t a)
{
  return __rv_sunpkd832 (a);
}

static __attribute__ ((noinline))
int16x4_t v_sunpkd832 (int8x8_t a)
{
  return __rv_v_sunpkd832 (a);
}

int
main ()
{
  int16x4_t va_p = {0xfff8, 0x0012, 0xfff8, 0x0012};
  uint64_t a = sunpkd832 (0x12f8000012f80000);
  int16x4_t va = v_sunpkd832 ((int8x8_t) {0, 0, 0xf8, 0x12, 0, 0, 0xf8, 0x12});

  if (a != 0x0012fff80012fff8)
    abort ();
  else if (!vec_all_eq_int16x4_t ( va_p, va))
    abort ();
  else
    exit (0);
}
