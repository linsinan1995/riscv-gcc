/* This is a test program for kmar64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <p_ext_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
long long kmar64 (long long rd, long ra, long rb)
{
  return __rv__kmar64 (rd, ra, rb);
}

int
main ()
{
  long long a = kmar64 (0x1, 0xffff0000ffff0000ll, 0x0001ffff0001ffffll);

  if (a != 0xfffffffc00020001ll)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
