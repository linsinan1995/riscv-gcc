/* This is a test program for srai.u instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int sraiu (int ra)
{
  return __rv__sra_u (ra, 8);
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
#else
int main(){return 0;}
#endif
