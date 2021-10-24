/* This is a test program for sril16.u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t srli16_u (uint32_t ra)
{
  return __rv_srl16_u (ra, 4);
}

static __attribute__ ((noinline))
uint16x2_t v_srli16_u (uint16x2_t ra)
{
  return __rv_v_srl16_u (ra, 4);
}

int
main ()
{
  uint32_t a = srli16_u (0x0f00f000);
  uint16x2_t va = v_srli16_u ((uint16x2_t) {0x7fff, 0x8000});

  if (a != 0xf00f00)
    abort ();
  else if (va[0] != 0x800
	   || va[1] != 0x800)
    abort ();
  else
    exit (0);
}
