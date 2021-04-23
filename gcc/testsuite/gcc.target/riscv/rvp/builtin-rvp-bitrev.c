/* This is a test program for bitrev instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t bitrev (uint32_t ra, uint32_t rb)
{
  return __rv__bitrev (ra, rb);
}

int
main ()
{
  uint32_t a = bitrev (0xd, 1);

  if (a != 0x2)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
