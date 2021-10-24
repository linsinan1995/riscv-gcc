/* This is a test program for srl32u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t srl32u (uint64_t ra, uint32_t rb)
{
  return __rv_srl32_u (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_srl32u (uint32x2_t ra, uint32_t rb)
{
  return __rv_v_srl32_u (ra, rb);
}

int
main ()
{
  uint64_t a = srl32u (0x0ffff0000ffff000, 4);
  uint32x2_t va = v_srl32u ((uint32x2_t) {0x7fff8000, 0x7fff8000}, 4);

  if (a != 0xffff0000ffff00)
    abort ();
  else if (va[0] != 0x07fff800
	   || va[1] != 0x7fff800)
    abort ();
  else
    exit (0);
}
