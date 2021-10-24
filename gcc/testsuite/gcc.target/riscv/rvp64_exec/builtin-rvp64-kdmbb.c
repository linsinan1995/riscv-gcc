/* This is a test program for kdmbb instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int32_t kdmbb (uint32_t ra, uint32_t rb)
{
  return __rv_kdmbb (ra, rb);
}

static __attribute__ ((noinline))
int32_t v_kdmbb (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_kdmbb (ra, rb);
}

int
main ()
{
  // SE64
  int64_t a = kdmbb (0x0001f000, 0x00011000);
  int64_t v_sa = v_kdmbb ((int16x2_t) {0xf777, 0xf111},
		       (int16x2_t) {0x1000, 0x2000});
  if (a != 0xfffffffffe000000)
    abort ();
  else if (v_sa != 0xfffffffffeeee000ll)
    abort ();
  else
    exit (0);
}
