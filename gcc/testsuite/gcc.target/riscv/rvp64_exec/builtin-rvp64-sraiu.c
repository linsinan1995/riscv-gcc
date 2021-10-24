/* This is a test program for srai.u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t sraiu (int64_t ra)
{
  return __rv_sra_u (ra, 8);
}

int
main ()
{
  int a = sraiu (0xf00ff);

  if (a != 0xf01)
    abort ();
  else
    exit (0);
}
