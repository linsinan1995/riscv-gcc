/* This is a test program for kslra16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t kslra16 (uint32_t ra, uint32_t rb)
{
  return __rv__kslra16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_kslra16 (int16x4_t ra, uint32_t rb)
{
  return __rv__v_kslra16 (ra, rb);
}

int
main ()
{
  int16x4_t va_p = {0x7fff, 0x8000, 0x7fff, 0x8000};
  uint32_t a = kslra16 (0x0f00f0000f00f000, 4);
  int16x4_t va = v_kslra16 ((int16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000}, 4);

  if (a != 0x7fff80007fff8000)
    abort ();
  else if (!vec64_all_eq (s, 16, va_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
