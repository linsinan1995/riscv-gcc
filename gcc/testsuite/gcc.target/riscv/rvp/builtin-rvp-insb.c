/* This is a test program for insb instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t insb (uint32_t ra, uint32_t rb)
{
  return __rv__insb (ra, rb, 1);
}

int
main ()
{
  uint32_t a = insb (0x11220044, 0x33);

  if (a != 0x11223344)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
