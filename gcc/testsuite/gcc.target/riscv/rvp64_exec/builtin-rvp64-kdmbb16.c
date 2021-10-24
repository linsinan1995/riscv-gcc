/* This is a test program for kdmbb16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t kdmbb16 (uint64_t ra, uint64_t rb)
{
  return __rv_kdmbb16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kdmbb16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_kdmbb16 (ra, rb);
}

int
main ()
{
  uint64_t a = kdmbb16 (0x0001f0000001f000, 0x0001100000011000);
  int32x2_t va = v_kdmbb16 ((int16x4_t) {0xf777, 0xf111, 0xf777, 0xf111},
			    (int16x4_t) {0x1000, 0x2000, 0x1000, 0x2000});
  if (a != 0xfe000000fe000000)
    abort ();
  else if (va[0] != 0xfeeee000
	   || va[1] != 0xfeeee000)
    abort ();
  else
    exit (0);
}
