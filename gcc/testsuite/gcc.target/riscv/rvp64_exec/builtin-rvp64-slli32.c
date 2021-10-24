/* This is a test program for slli32 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t slli32 (uint64_t ra)
{
  return __rv_sll32 (ra, 4);
}

static __attribute__ ((noinline))
uint32x2_t v_slli32 (uint32x2_t ra)
{
  return __rv_v_sll32 (ra, 4);
}

int
main ()
{
  uint32x2_t va_p = {0xfff80000, 0xfff80000};
  uint64_t a = slli32 (0x0ffff0000ffff000);
  uint32x2_t va = v_slli32 ((uint32x2_t) {0x7fff8000, 0x7fff8000});

  if (a != 0xffff0000ffff0000)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
