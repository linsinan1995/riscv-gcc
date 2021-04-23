/* This is a test program for uradd64 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
unsigned long long uradd64 (unsigned long long ra, unsigned long long rb)
{
  return __rv__uradd64 (ra, rb);
}

int
main ()
{
  unsigned long long a = uradd64 (0xf000000000000000ull, 0xf000000000000000ull);

  if (a != 0xf000000000000000ull)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
