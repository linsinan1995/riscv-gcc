/* This is a test program for srai16.u instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t srai16u (uint32_t ra)
{
  return __rv__sra16_u (ra, 4);
}

static __attribute__ ((noinline))
int16x2_t v_srai16u (int16x2_t ra)
{
  return __rv__v_sra16_u (ra, 4);
}

int
main ()
{
  uint32_t a = srai16u (0x0ffff000);
  int16x2_t va = v_srai16u ((int16x2_t) {0x7fff, 0x8000});

  if (a != 0x100ff00)
    abort ();
  else if (va[0] != 0x800
	   || va[1] != (short) 0xf800)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
