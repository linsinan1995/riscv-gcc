/* This is a test program for kaddh instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"


static __attribute__ ((noinline))
int32_t kaddh (int32_t ra, int32_t rb)
{
  return __rv_kaddh (ra, rb);
}

int
main ()
{
  int32_t sa = kaddh (0x11223344, 0x55667788);

  if (sa != 0x7fff)
    abort ();
  else
    exit (0);
}
