/* This is a test program for smaltt instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t smaltt (int64_t t, uint64_t a, uint64_t b)
{
  return __rv_smaltt (t, a, b);
}

static __attribute__ ((noinline))
int64_t v_smaltt (int64_t t, int16x4_t a, int16x4_t b)
{
  return __rv_v_smaltt (t, a, b);
}


int
main ()
{
  int64_t a = smaltt (0x12345678ffffffffll, 0x6789000067890000, 0x1234000012340000);
  int64_t va = v_smaltt (0x12345678ffffffffll, (int16x4_t) {0, 0x6789, 0, 0x6789},
						 (int16x4_t) {0, 0x1234, 0, 0x1234});

  if (a != 0x123456790eb953a7ll)
    abort ();
  else if (va != 0x123456790eb953a7ll)
    abort ();
  else
    exit (0);
}
