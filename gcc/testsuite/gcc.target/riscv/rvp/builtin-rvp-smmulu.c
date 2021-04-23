/* This is a test program for smmul.u instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t smmul_u (int32_t ra, int32_t rb)
{
  return __rv__smmul_u (ra, rb);
}

int
main ()
{
  int32_t a = smmul_u (0x80000002, 0x80000001);

  if (a != 0x3fffffff)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
