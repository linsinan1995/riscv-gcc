/* This is a test program for smsr64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
long long smsr64 (long long rd, long ra, long rb)
{
  return __rv__smsr64 (rd, ra, rb);
}

int
main ()
{
  long long a = smsr64 (0x1, 0xffff0000ffff0000ll, 0x0001ffff0001ffffll);

  if (a != 0x3fffe0001ll)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
