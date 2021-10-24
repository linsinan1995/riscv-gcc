/* This is a test program for smds instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t smds (uint64_t ra, uint64_t rb)
{
  return __rv_smds (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_smds (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_smds (ra, rb);
}

int
main ()
{
  int64_t a = smds (0x8000000280000002, 0x8000000180000001);
  int32x2_t va = v_smds ((int16x4_t) {0xffff, 0x0002, 0xffff, 0x0002},
			 (int16x4_t) {0xffff, 0x0001, 0xffff, 0x0001});

  if (a != 0x3ffffffe3ffffffe)
    abort ();
  else if (va[0] != 0x1
	   || va[1] != 0x1)
    abort ();
  else
    exit (0);
}
