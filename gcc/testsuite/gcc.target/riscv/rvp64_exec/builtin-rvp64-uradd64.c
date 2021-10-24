/* This is a test program for radd64 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t radd64 (int64_t ra, int64_t rb)
{
  return __rv_radd64 (ra, rb);
}

int
main ()
{
  int64_t a = radd64 (0xf000000000000000ll, 0xf000000000000000ll);

  if (a != 0xf000000000000000ll)
    abort ();
  else
    exit (0);
}
