/* This is a test program for kslli instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int kslli (int ra)
{
  return __rv__ksllw (ra, 8);
}

int
main ()
{
  int a = kslli (0xf00ff);

  if (a != 0xf00ff00)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
