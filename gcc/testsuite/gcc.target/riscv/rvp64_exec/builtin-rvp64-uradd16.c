/* This is a test program for uradd16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t uradd16 (uint64_t ra, uint64_t rb)
{
  return __rv_uradd16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_uradd16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_uradd16 (ra, rb);
}

int
main ()
{
  uint64_t a = uradd16 (0x7fff7fff7fff7fff, 0x7fff7fff7fff7fff);
  uint16x4_t va = v_uradd16 ((uint16x4_t) {0x8000, 0x4000, 0x8000, 0x4000},
			     (uint16x4_t) {0x8000, 0x8000, 0x8000, 0x8000});

  if (a != 0x7fff7fff7fff7fff)
    abort ();
  else if (va[0] != 0x8000
	   || va[1] != 0x6000
	   || va[2] != 0x8000
	   || va[3] != 0x6000)
    abort ();
  else
    exit (0);
}
