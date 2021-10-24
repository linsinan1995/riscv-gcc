/* This is a test program for wsbh instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t swap8 (uint32_t a)
{
  return __rv_swap8 (a);
}

int
main ()
{
  uint32_t a = 0x03020100;
  uint32_t b;

  b = __rv_swap8 (a);

  if (b != 0x02030001)
    abort ();
  else
    exit (0);
}
