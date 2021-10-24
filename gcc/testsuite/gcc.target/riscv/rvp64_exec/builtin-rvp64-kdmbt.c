/* This is a test program for kdmbt instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int32_t kdmbt (uint32_t ra, uint32_t rb)
{
  return __rv_kdmbt (ra, rb);
}

static __attribute__ ((noinline))
int32_t v_kdmbt (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_kdmbt (ra, rb);
}

int
main ()
{
  int64_t a = kdmbt (0x0001f000, 0x00011000);
  int64_t v_sa = v_kdmbt ((int16x2_t) {0xf777, 0xf111},
		       (int16x2_t) {0x1000, 0x2000});
  if (a != 0xffffffffffffe000)
    abort ();
  else if (v_sa != 0xfffffffffdddc000ll)
    abort ();
  else
    exit (0);
}
