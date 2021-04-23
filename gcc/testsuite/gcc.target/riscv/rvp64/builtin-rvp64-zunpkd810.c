/* This is a test program for zunpkd810 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

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
uint16x4_t v_zunpkd810 (uint8x8_t a)
{
  return __rv__v_zunpkd810 (a);
}

int
main ()
{
  uint16x4_t va_p = {0xf8, 0x56, 0xf8, 0x56};
  uint32_t a = zunpkd810 (0x000056f8000056f8);
  uint16x4_t va = v_zunpkd810 ((uint8x8_t) {0xf8, 0x56, 0, 0, 0xf8, 0x56, 0, 0});

  if (a != 0x005600f8005600f8)
    abort ();
  else if (!vec64_all_eq (u, 16, va_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
