/* This is a test program for kslli instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int32_t kslli (int32_t ra)
{
  return __rv_ksllw (ra, 8);
}

int
main ()
{
  int a = kslli (0xf00ff);

  if (a != 0xf00ff00)
    abort ();
  else
    exit (0);
}
