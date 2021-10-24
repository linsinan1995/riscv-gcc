/* This is a test program for ksll16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t ksll16 (uint64_t ra, uint32_t rb)
{
  return __rv_ksll16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_ksll16 (int16x4_t ra, uint32_t rb)
{
  return __rv_v_ksll16 (ra, rb);
}

int
main ()
{
  int16x4_t va_p = {0x7fff, 0x8000, 0x7fff, 0x8000};
  uint64_t a = ksll16 (0x0f00f0000f00f000, 4);
  int16x4_t va = v_ksll16 ((int16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000}, 4);

  if (a != 0x7fff80007fff8000)
    abort ();
  else if (!vec_all_eq_int16x4_t ( va_p, va))
    abort ();
  else
    exit (0);
}
