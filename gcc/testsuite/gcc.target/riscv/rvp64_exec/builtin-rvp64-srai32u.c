/* This is a test program for srai32u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t srai32u (uint64_t ra)
{
  return __rv_sra32_u (ra, 4);
}

static __attribute__ ((noinline))
int32x2_t v_srai32u (int32x2_t ra)
{
  return __rv_v_sra32_u (ra, 4);
}

int
main ()
{
  int32x2_t va_p = {0x07fff800, 0x07fff800};
  uint64_t a = srai32u (0x0ffff0000ffff000);
  int32x2_t va = v_srai32u ((int32x2_t) {0x7fff8000, 0x7fff8000});

  if (a != 0xffff0000ffff00)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
