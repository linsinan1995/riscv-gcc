/* This is a test program for umar64 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
unsigned long long umar64 (unsigned long long t,unsigned int a,unsigned int b)
{
  return __rv__umar64 (t, a, b);
}

int
main ()
{
  unsigned long long a = umar64 (0xf000000000000000ull, 0x12345678, 0x23);

  if (a != 0xf00000027d27d268ull)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
