/* This is a test program for zunpkd830 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t zunpkd830 (uint32_t a)
{
  return __rv__zunpkd830 (a);
}

static __attribute__ ((noinline))
uint16x2_t v_zunpkd830 (uint8x4_t a)
{
  return __rv__v_zunpkd830 (a);
}

int
main ()
{
  uint32_t a = zunpkd830 (0x120000f8);
  uint16x2_t va = v_zunpkd830 ((uint8x4_t) { 0xf8, 0x00, 0, 0x12});

  if (a != 0x001200f8)
    abort ();
  else if (va[0] != 0x00f8
           || va[1] != 0x0012)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
