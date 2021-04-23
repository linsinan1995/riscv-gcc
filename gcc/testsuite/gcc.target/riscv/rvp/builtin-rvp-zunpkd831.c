/* This is a test program for zunpkd831 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t zunpkd831 (uint32_t a)
{
  return __rv__zunpkd831 (a);
}

static __attribute__ ((noinline))
uint16x2_t v_zunpkd831 (uint8x4_t a)
{
  return __rv__v_zunpkd831 (a);
}

int
main ()
{
  int16x2_t va_p = {0xf8, 0x12};
  uint32_t a = zunpkd831 (0x1200f800);
  uint16x2_t va = v_zunpkd831 ((uint8x4_t) {0, 0xf8, 0, 0x12});

  if (a != 0x001200f8)
    abort ();
  else if (va[0] != va_p[0]
           || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
