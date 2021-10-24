/* This is a test program for uraddw instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t uraddw (uint32_t ra, uint32_t rb)
{
  return __rv_uraddw (ra, rb);
}

int
main ()
{
  uint32_t a = uraddw (0x80000000, 0x80000000);

  if (a != 0x80000000)
    abort ();
  else
    exit (0);
}
