/* This is a test program for ksubh instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int ksubh (int ra, int rb)
{
  return __rv_ksubh (ra, rb);
}

int
main ()
{
  int sa = ksubh (0x11223344, 0x55667788);

  if (sa != 0xffffffffffff8000)
    abort ();
  else
    exit (0);
}
