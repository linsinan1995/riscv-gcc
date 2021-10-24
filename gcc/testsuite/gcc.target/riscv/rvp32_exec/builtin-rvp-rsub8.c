/* This is a test program for rsub8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t rsub8 (uint32_t ra, uint32_t rb)
{
  return __rv_rsub8 (ra, rb);
}

static __attribute__ ((noinline))
int8x4_t v_rsub8 (int8x4_t ra, int8x4_t rb)
{
  return __rv_v_rsub8 (ra, rb);
}

int
main ()
{
  uint32_t a = rsub8 (0x55667788, 0x11223344);
  int8x4_t va = v_rsub8 ((int8x4_t) {0x7f, 0x80, 0x80, 0xaa},
			 (int8x4_t) {0x80, 0x7f, 0x40, 0xaa});

  if (a != 0x222222a2)
    abort ();
  else if (va[0] != 0x7f
	   || va[1] != (signed char) 0x80
	   || va[2] != (signed char) 0xa0
	   || va[3] != 0)
    abort ();
  else
    exit (0);
}
