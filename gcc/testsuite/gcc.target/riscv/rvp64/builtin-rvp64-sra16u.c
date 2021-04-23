/* This is a test program for sra16.u instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t sra16u (uint32_t ra, uint32_t rb)
{
  return __rv__sra16_u (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_sra16u (int16x4_t ra, uint32_t rb)
{
  return __rv__v_sra16_u (ra, rb);
}

int
main ()
{
  int16x4_t va_p = {0x800, 0xf800, 0x800, 0xf800};
  uint32_t a = sra16u (0x0ffff0000ffff000, 4);
  int16x4_t va = v_sra16u ((int16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000}, 4);

  if (a != 0x100ff000100ff00)
    abort ();
  else if (!vec64_all_eq (s, 16, va_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
