/* This is a test program for ukmar64 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t ukmar64 (uint64_t rd, uint64_t ra, uint64_t rb)
{
  return __rv_ukmar64 (rd, ra, rb);
}

int
main ()
{
  uint64_t a = ukmar64 (0x1, 0xffff0000ffff0000ll, 0x0001ffff0001ffffll);

  if (a != 0x3fffa00020001ll)
    abort ();
  else
    exit (0);
}
