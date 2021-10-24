/* This is a test program for uksub64 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t uksub64 (uint64_t ra, uint64_t rb)
{
  return __rv_uksub64 (ra, rb);
}

int
main ()
{
  uint64_t sa = uksub64 (0x1122334400000000ll, 0x55667788ll);

  if (sa != 0x11223343aa998878ll)
    abort ();
  else
    exit (0);
}
