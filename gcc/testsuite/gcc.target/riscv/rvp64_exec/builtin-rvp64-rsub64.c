/* This is a test program for rsub64 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t rsub64 (int64_t ra, int64_t rb)
{
  return __rv_rsub64 (ra, rb);
}

int
main ()
{
  int64_t a = rsub64 (0xe, 0xf);

  if (a != 0xffffffffffffffff)
    abort ();
  else
    exit (0);
}
