/* This is a test program for pbsada instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t pbsada (uint32_t ra, uint32_t rb, uint32_t rc)
{
  return __rv_pbsada (ra, rb, rc);
}

int
main ()
{
  uint32_t a = 0x09070605;
  uint32_t b = 0x04020301;
  uint32_t r = 1;

  r = pbsada(r, a, b);

  if (r != 18)
    abort ();
  else
    exit (0);
}
