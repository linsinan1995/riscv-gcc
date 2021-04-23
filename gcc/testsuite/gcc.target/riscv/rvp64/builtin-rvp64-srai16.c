/* This is a test program for srai16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t srai16 (uint32_t ra)
{
  return __rv__sra16 (ra, 4);
}

static __attribute__ ((noinline))
int16x4_t v_srai16 (int16x4_t ra)
{
  return __rv__v_sra16 (ra, 4);
}

int
main ()
{
  int16x4_t va_p = {0x7ff, 0xf800, 0x7ff, 0xf800};
  uint32_t a = srai16 (0x0ffff0000ffff000);

  int16x4_t aa;
  int16x4_t va = v_srai16 ((int16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000});

  if (a != 0x00ffff0000ffff00)
    abort ();
  else if (!vec64_all_eq (s, 16, va_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
