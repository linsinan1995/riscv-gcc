/* This is a test program for sunpkd810 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t sunpkd810 (uint64_t a)
{
  return __rv_sunpkd810 (a);
}

static __attribute__ ((noinline))
int16x4_t v_sunpkd810 (int8x8_t a)
{
  return __rv_v_sunpkd810 (a);
}

int
main ()
{
  int16x4_t va_p = {0xfff8, 0x56, 0xfff8, 0x56};
  uint64_t a = sunpkd810 (0x000056f8000056f8);
  int16x4_t va = v_sunpkd810 ((int8x8_t) {0xf8, 0x56, 0, 0, 0xf8, 0x56, 0, 0});

  if (a != 0x0056fff80056fff8)
    abort ();
  else if (!vec_all_eq_int16x4_t ( va_p, va))
    abort ();
  else
    exit (0);
}
