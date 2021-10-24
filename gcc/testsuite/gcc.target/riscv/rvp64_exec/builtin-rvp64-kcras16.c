/* This is a test program for cras16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t cras16 (uint64_t ra, uint64_t rb)
{
  return __rv_kcras16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_kcras16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_kcras16 (ra, rb);
}

int
main ()
{
  int16x4_t v_sa_p = {0x1000, 0x111, 0x1000, 0x111};
  uint64_t a = cras16 (0x0001f0000001f000, 0x0001f0000001f000);
  int16x4_t v_sa = v_kcras16 ((int16x4_t) {0x2000, 0xf111, 0x2000, 0xf111},
			      (int16x4_t) {0x1000, 0x1000, 0x1000, 0x1000});

  if (a != 0xf001effff001efffllu)
    abort ();
  else if (v_sa[0] != v_sa_p[0]
	   || v_sa[1] != v_sa_p[1]
	   || v_sa[2] != v_sa_p[2]
	   || v_sa[3] != v_sa_p[3])
    abort ();
  else
    exit (0);
}
