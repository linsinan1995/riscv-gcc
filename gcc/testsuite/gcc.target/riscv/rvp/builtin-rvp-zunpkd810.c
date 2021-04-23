/* This is a test program for zunpkd810 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t zunpkd810 (uint32_t a)
{
  return __rv__zunpkd810 (a);
}

static __attribute__ ((noinline))
uint16x2_t v_zunpkd810 (uint8x4_t a)
{
  return __rv__v_zunpkd810 (a);
}

int
main ()
{
  int16x2_t va_p = {0xf8, 0x56};
  uint32_t a = zunpkd810 (0x000056f8);
  uint16x2_t va = v_zunpkd810 ((uint8x4_t) {0xf8, 0x56, 0, 0});

  if (a != 0x005600f8)
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
