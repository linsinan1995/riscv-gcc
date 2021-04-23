/* This is a test program for kslraw instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int kslraw (int ra, int rb)
{
  return __rv__kslraw (ra, rb);
}

int
main ()
{
  int a = kslraw (0x0f00f000, 4);

  if (a != 0x7fffffff)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
