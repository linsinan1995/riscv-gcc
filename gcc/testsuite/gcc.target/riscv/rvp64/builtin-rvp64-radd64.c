/* This is a test program for radd64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <p_ext_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
long long radd64 (long long ra, long long rb)
{
  return __rv__radd64 (ra, rb);
}

int
main ()
{
  long long a = radd64 (0xf000000000000000ll, 0xf000000000000000ll);

  if (a != 0xf000000000000000ll)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
