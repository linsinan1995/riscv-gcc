/* This is a test program for raddw instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int32_t raddw (int32_t ra, int32_t rb)
{
  return __rv_raddw (ra, rb);
}

int
main ()
{
  int32_t a = raddw (0x80000000, 0x80000000);

  if (a != 0xffffffff80000000)
    abort ();
  else
    exit (0);
}
