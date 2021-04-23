/* This is a test program for wext instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
unsigned long wext (long long ra, unsigned long rb)
{
  return __rv__wext (ra, rb);
}

int
main ()
{
  uint32_t a = wext (0x1234ffff0000ll, 16);

  if (a != 0x1234ffff)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
