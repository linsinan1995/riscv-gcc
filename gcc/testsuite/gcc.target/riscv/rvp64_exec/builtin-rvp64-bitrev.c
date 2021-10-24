/* This is a test program for bitrev instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t bitrev (uint64_t ra, uint32_t rb)
{
  return __rv_bitrev (ra, rb);
}

int
main ()
{
  uint64_t a = bitrev (0xd, 1);

  if (a != 0x2)
    abort ();
  else
    exit (0);
}
