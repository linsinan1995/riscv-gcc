/* This is a test program for srai.u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int sraiu (int ra)
{
  return __rv_sra_u (ra, 8);
}

int
main ()
{
  int a = sraiu (0xf00ff);

  if (a != 0xf01)
    abort ();
  else
    exit (0);
}
