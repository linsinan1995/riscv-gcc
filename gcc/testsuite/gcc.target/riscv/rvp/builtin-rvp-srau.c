/* This is a test program for sra.u instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int srau (int ra, uint32_t rb)
{
  return __rv__sra_u (ra, rb);
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
#else
int main(){return 0;}
#endif
