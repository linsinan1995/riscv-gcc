/* This is a test program for rsubw instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t rsubw (int32_t ra, int32_t rb)
{
  return __rv_rsubw (ra, rb);
}

int
main ()
{
  int32_t a = rsubw (0x80000000, 0x7fffffff);

  if (a != 0x80000000)
    abort ();
  else
    exit (0);
}
