/* This is a test program for radd32 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t radd32 (uint64_t ra, uint64_t rb)
{
  return __rv_radd32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_radd32 (int32x2_t ra, int32x2_t rb)
{
  return __rv_v_radd32 (ra, rb);
}

int
main ()
{
  int32x2_t sa_p = {0x3bc0888, 0x3bc0888};
  uint64_t a = radd32 (0x0001f0000001f000, 0x0001100000011000);
  int32x2_t v_sa = v_radd32 ((int32x2_t) {0xf777f111, 0xf777f111},
			     (int32x2_t) {0x10002000, 0x10002000});

  if (a != 0x1800000018000)
    abort ();
  else if (sa_p[0] != v_sa[0]
	   || sa_p[1] != v_sa[1])
    abort ();
  else
    exit (0);
}
