/* This is a test program for kabs16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t kabs16 (uint64_t ra)
{
  return __rv_kabs16 (ra);
}

static __attribute__ ((noinline))
int16x4_t v_kabs16 (int16x4_t ra)
{
  return __rv_v_kabs16 (ra);
}

int
main ()
{
  int16x4_t v_sa_p = {0x7fff, 0x4000, 0x7fff, 0x4000};
  uint64_t a = kabs16 (0x7fff7fff7fff7fff);
  int16x4_t va = v_kabs16 ((int16x4_t) {0x8000, 0x4000, 0x8000, 0x4000});

  if (a != 0x7fff7fff7fff7fff)
    abort ();
  else if (!vec_all_eq_int16x4_t ( v_sa_p, va))
    abort ();
  else
    exit (0);
}
