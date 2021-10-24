/* This is a test program for sra.u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int srau (int ra, uint32_t rb)
{
  return __rv_sra_u (ra, rb);
}

int
main ()
{
  int a = srau (0xf00ff, 8);

  if (a != 0xf01)
    abort ();
  else
    exit (0);
}
