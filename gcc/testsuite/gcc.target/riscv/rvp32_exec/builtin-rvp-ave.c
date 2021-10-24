/* This is a test program for ave instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t ave (int32_t ra, int32_t rb)
{
  return __rv_ave (ra, rb);
}


int
main ()
{
  int a = 4;
  int b = 2;
  int r = ave (a, b);

  if (r != 3)
    abort ();
  else
    exit (0);
}
