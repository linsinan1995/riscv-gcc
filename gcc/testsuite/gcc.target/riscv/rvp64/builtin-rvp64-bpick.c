/* This is a test program for bpick instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t bpick (uint32_t ra, uint32_t rb, uint32_t rc)
{
  return __rv__bpick (ra, rb, rc);
}

int
main ()
{
  uint32_t a = bpick (0x1122334411223344, 0x1133224411332244, 0);

  if (a != 0x1133224411332244)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
