/* This is a test program for rsubw instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t rsubw (int32_t ra, int32_t rb)
{
  return __rv__rsubw (ra, rb);
}

int
main ()
{
  int32_t a = rsubw (0x80000000, 0x7fffffff);

  if (a != 0xffffffff80000000)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
