/* This is a test program for uraddw instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t uraddw (uint32_t ra, uint32_t rb)
{
  return __rv_uraddw (ra, rb);
}

int
main ()
{
  uint64_t a = uraddw (0x80000000, 0x80000000);

  if (a != 0xffffffff80000000)
    abort ();
  else
    exit (0);
}
