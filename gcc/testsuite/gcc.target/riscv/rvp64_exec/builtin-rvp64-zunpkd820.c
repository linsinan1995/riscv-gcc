/* This is a test program for zunpkd820 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t zunpkd820 (uint64_t a)
{
  return __rv_zunpkd820 (a);
}

static __attribute__ ((noinline))
uint16x4_t v_zunpkd820 (uint8x8_t a)
{
  return __rv_v_zunpkd820 (a);
}

int
main ()
{
  uint16x4_t va_p = {0xf8, 0x34, 0xf8, 0x34};
  uint64_t a = zunpkd820 (0x003400f8003400f8);
  uint16x4_t va = v_zunpkd820 ((uint8x8_t) {0xf8, 0, 0x34, 0, 0xf8, 0, 0x34, 0});

  if (a != 0x003400f8003400f8)
    abort ();
  else if (!vec_all_eq_uint16x4_t ( va_p, va))
    abort ();
  else
    exit (0);
}
