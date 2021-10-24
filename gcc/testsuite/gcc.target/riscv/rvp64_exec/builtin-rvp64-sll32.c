/* This is a test program for sll32 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t sll32 (uint64_t ra, uint32_t rb)
{
  return __rv_sll32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_sll32 (uint32x2_t ra, uint32_t rb)
{
  return __rv_v_sll32 (ra, rb);
}

int
main ()
{
  uint64_t a = sll32 (0x0ffff0000ffff000, 4);
  uint32x2_t va = v_sll32 ((uint32x2_t) {0x7fff8000, 0x7fff8000}, 4);

  if (a != 0xffff0000ffff0000)
    abort ();
  else if (va[0] != 0xfff80000
	   || va[1] != 0xfff80000)
    abort ();
  else
    exit (0);
}
