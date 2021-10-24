/* This is a test program for insb instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t insb (uint64_t t, uint64_t a)
{
  return __rv_insb (t, a, 1);
}

int
main ()
{
  uint64_t a = insb (0x1122004411220044, 0x33);

  if (a != 0x1122004411223344)
    abort ();
  else
    exit (0);
}
