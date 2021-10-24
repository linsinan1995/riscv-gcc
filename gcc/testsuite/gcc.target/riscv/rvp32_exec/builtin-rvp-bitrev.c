/* This is a test program for bitrev instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t bitrev (uint32_t ra, uint32_t rb)
{
  return __rv_bitrev (ra, rb);
}

int
main ()
{
  uint32_t a = bitrev (0xd, 1);

  if (a != 0x2)
    abort ();
  else
    exit (0);
}
