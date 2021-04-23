/* This is a test program for smmul instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t smmul (int32_t ra, int32_t rb)
{
  return __rv__smmul (ra, rb);
}

int
main ()
{
  int32_t a = smmul (0x80000000, 0x80000000);

  if (a != 0x40000000)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
