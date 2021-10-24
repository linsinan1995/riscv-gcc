/* This is a test program for sra16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sra16 (uint32_t ra, uint32_t rb)
{
  return __rv_sra16 (ra, rb);
}

static __attribute__ ((noinline))
int16x2_t v_sra16 (int16x2_t ra, uint32_t rb)
{
  return __rv_v_sra16 (ra, rb);
}

int
main ()
{
  uint32_t a = sra16 (0x0ffff000, 4);
  int16x2_t va = v_sra16 ((int16x2_t) {0x7fff, 0x8000}, 4);

  if (a != 0x00ffff00)
    abort ();
  else if (va[0] != 0x7ff
	   || va[1] != (short) 0xf800)
    abort ();
  else
    exit (0);
}
