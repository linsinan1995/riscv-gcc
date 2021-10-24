/* This is a test program for bpick instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t bpick (uint64_t ra, uint64_t rb, uint64_t rc)
{
  return __rv_bpick (ra, rb, rc);
}

int
main ()
{
  uint64_t a = bpick (0x1122334411223344, 0x1133224411332244, 0);

  if (a != 0x1133224411332244)
    abort ();
  else
    exit (0);
}
