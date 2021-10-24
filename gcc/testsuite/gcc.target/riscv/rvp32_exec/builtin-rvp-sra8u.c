/* This is a test program for sra8.u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sra8u (uint32_t ra, uint32_t rb)
{
  return __rv_sra8_u (ra, rb);
}

static __attribute__ ((noinline))
int8x4_t v_sra8u (int8x4_t ra, uint32_t rb)
{
  return __rv_v_sra8_u (ra, rb);
}

int
main ()
{
  uint32_t a = sra8u (0x011223344, 4);
  int8x4_t va = v_sra8u ((int8x4_t) {0xff, 0xee, 0xdd, 0xcc}, 4);

  if (a != 0x1020304)
    abort ();
  else if (va[0] != 0
	   || va[1] != (signed char) 0xff
	   || va[2] != (signed char) 0xfe
	   || va[3] != (signed char) 0xfd)
    abort ();
  else
    exit (0);
}
