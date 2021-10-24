/* This is a test program for kwmmulu instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t kwmmulu (int64_t ra, int64_t rb)
{
  return __rv_kwmmul_u (ra, rb);
}

int
main ()
{
  int64_t a = kwmmulu (0x8000000080000000, 0x8000000080000000);

  if (a != 0x7fffffff7fffffff)
    abort ();
  else
    exit (0);
}
