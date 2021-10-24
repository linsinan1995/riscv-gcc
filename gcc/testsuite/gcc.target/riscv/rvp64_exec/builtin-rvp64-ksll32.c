/* This is a test program for ksll32 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t ksll32 (uint64_t ra, uint32_t rb)
{
  return __rv_ksll32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_ksll32 (int32x2_t ra, uint32_t rb)
{
  return __rv_v_ksll32 (ra, rb);
}

int
main ()
{
  int32x2_t va_p = {0x7fffffff, 0x7fffffff};
  uint64_t a = ksll32 (0x0f00f0000f00f000, 4);
  int32x2_t va = v_ksll32 ((int32x2_t) {0x7fff8000, 0x7fff8000}, 4);

  if (a != 0x7fffffff7fffffff)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
