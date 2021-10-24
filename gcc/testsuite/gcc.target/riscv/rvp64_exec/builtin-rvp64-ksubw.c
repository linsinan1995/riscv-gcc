/* This is a test program for ksubw instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int ksubw (int ra, int rb)
{
  return __rv_ksubw (ra, rb);
}

int
main ()
{
  int sa = ksubw (0x11223344, 0x55667788);

  if (sa != 0xbbbbbbbc)
    abort ();
  else
    exit (0);
}
