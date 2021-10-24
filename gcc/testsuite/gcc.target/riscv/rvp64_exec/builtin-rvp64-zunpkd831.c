/* This is a test program for zunpkd831 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t zunpkd831 (uint64_t a)
{
  return __rv_zunpkd831 (a);
}

static __attribute__ ((noinline))
uint16x4_t v_zunpkd831 (uint8x8_t a)
{
  return __rv_v_zunpkd831 (a);
}

int
main ()
{
  uint16x4_t va_p = {0xf8, 0x12, 0xf8, 0x12};
  uint64_t a = zunpkd831 (0x1200f8001200f800);
  uint16x4_t va = v_zunpkd831 ((uint8x8_t) {0, 0xf8, 0, 0x12, 0, 0xf8, 0, 0x12});

  if (a != 0x001200f8001200f8)
    abort ();
  else if (!vec_all_eq_uint16x4_t ( va_p, va))
    abort ();
  else
    exit (0);
}
