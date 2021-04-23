/* This is a test program for ursub64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
unsigned long long ursub64 (unsigned long long ra, unsigned long long rb)
{
  return __rv__ursub64 (ra, rb);
}

int
main ()
{
  unsigned long long a = ursub64 (0xeull, 0xfull);

  if (a != 0xffffffffffffffffull)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
