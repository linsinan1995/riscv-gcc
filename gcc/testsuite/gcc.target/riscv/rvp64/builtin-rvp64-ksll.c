/* This is a test program for ksll instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int ksll (int ra, uint32_t rb)
{
  return __rv__ksllw (ra, rb);
}

int
main ()
{
  int a = ksll (0xf00ff, 8);

  if (a != 0xf00ff00)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
