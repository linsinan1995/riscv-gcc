/* This is a test program for pbsad instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t pbsad (uint32_t ra, uint32_t rb)
{
  return __rv_pbsad (ra, rb);
}

int
main ()
{
  unsigned int a = 0x09070605;
  unsigned int b = 0x04020301;
  unsigned int r = __rv_pbsad (a, b);

  if (r != 17)
    abort ();
  else
    exit (0);
}
