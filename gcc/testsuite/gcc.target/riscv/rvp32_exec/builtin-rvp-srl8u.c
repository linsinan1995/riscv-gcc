/* This is a test program for srl8.u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t srl8_u (uint32_t ra, uint32_t rb)
{
  return __rv_srl8_u (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t v_srl8_u (uint8x4_t ra, uint32_t rb)
{
  return __rv_v_srl8_u (ra, rb);
}

int
main ()
{
  uint32_t a = srl8_u (0x11223344, 4);
  uint8x4_t va = v_srl8_u ((uint8x4_t) {0xff, 0xee, 0xdd, 0xcc}, 4);

  if (a != 0x1020304)
    abort ();
  else if (va[0] != 0x10
	   || va[1] != 0xf
	   || va[2] != 0xe
	   || va[3] != 0xd)
    abort ();
  else
    exit (0);
}
