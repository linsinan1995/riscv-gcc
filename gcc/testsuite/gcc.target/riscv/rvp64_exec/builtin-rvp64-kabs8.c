/* This is a test program for kabs8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t kabs8 (uint64_t ra)
{
  return __rv_kabs8 (ra);
}

static __attribute__ ((noinline))
int8x8_t v_kabs8 (int8x8_t ra)
{
  return __rv_v_kabs8 (ra);
}

int
main ()
{
  int8x8_t v_sa_p = {0x7f, 0x0, 0x40, 0x0, 0x7f, 0x0, 0x40, 0x0};
  uint64_t a = kabs8 (0x7fff7fff7fff7fff);
  int8x8_t va = v_kabs8 ((int8x8_t) {0x80, 0x0, 0x40, 0x0, 0x80, 0x0, 0x40, 0x0});

  if (a != 0x7f017f017f017f01)
    abort ();
  else if (!vec_all_eq_int8x8_t (v_sa_p, va))
    abort ();
  else
    exit (0);
}
