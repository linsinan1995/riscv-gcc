/* This is a test program for srai16.u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t srai16u (uint64_t ra)
{
  return __rv_sra16_u (ra, 4);
}

static __attribute__ ((noinline))
int16x4_t v_srai16u (int16x4_t ra)
{
  return __rv_v_sra16_u (ra, 4);
}

int
main ()
{
  int16x4_t va_p = {0x800, 0xf800, 0x800, 0xf800};
  uint64_t a = srai16u (0x0ffff0000ffff000);
  int16x4_t va = v_srai16u ((int16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000});

  if (a != 0x100ff000100ff00)
    abort ();
  else if (!vec_all_eq_int16x4_t ( va_p, va))
    abort ();
  else
    exit (0);
}
