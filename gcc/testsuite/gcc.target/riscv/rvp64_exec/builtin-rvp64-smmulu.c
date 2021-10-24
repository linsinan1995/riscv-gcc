/* This is a test program for smmul.u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t smmul_u (int64_t ra, int64_t rb)
{
  return __rv_smmul_u (ra, rb);
}

int
main ()
{
  int64_t a = smmul_u (0x8000000280000002, 0x8000000180000001);

  if (a != 0x3fffffff3fffffff)
    abort ();
  else
    exit (0);
}
