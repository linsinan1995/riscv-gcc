/* This is a test program for insb instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t insb (uint32_t ra, uint32_t rb)
{
  return __rv_insb (ra, rb, 1);
}

int
main ()
{
  uint32_t a = insb (0x11220044, 0x33);

  if (a != 0x11223344)
    abort ();
  else
    exit (0);
}
