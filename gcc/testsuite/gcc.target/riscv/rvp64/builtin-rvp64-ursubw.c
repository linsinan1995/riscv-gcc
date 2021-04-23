/* This is a test program for ursubw instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t ursubw (unsigned int ra, unsigned int rb)
{
  return __rv__ursubw (ra, rb);
}

int
main ()
{
  uint32_t a = ursubw (0x80000000, 0x40000000);

  if (a != 0x20000000)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
