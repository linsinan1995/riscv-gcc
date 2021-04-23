/* This is a test program for sunpkd830 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t sunpkd830 (uint32_t a)
{
  return __rv__sunpkd830 (a);
}

static __attribute__ ((noinline))
int16x2_t v_sunpkd830 (int8x4_t a)
{
  return __rv__v_sunpkd830 (a);
}

int
main ()
{
  uint32_t a = sunpkd830 (0x120000f8);
  int16x2_t va = v_sunpkd830 ((int8x4_t) {0xf8, 0x00, 0, 0x12});

  if (a != 0x0012fff8)
    abort ();
  else if (va[0] != (short) 0xfff8
           || va[1] != 0x0012)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
