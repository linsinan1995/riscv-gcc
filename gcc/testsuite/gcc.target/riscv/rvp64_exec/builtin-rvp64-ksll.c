/* This is a test program for ksll instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int32_t ksll (int32_t ra, uint32_t rb)
{
  return __rv_ksllw (ra, rb);
}

int
main ()
{
  int32_t a = ksll (0xf00ff, 8);

  if (a != 0xf00ff00)
    abort ();
  else
    exit (0);
}
