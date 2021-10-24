/* This is a test program for uradd8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t uradd8 (uint64_t ra, uint64_t rb)
{
  return __rv_uradd8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t v_uradd8 (uint8x8_t ra, uint8x8_t rb)
{
  return __rv_v_uradd8 (ra, rb);
}

int
main ()
{
  uint64_t a = uradd8 (0x1122334411223344, 0x5566778855667788);
  uint8x8_t va = v_uradd8 ((uint8x8_t) {0x7f, 0x80, 0x40, 0xaa, 0x7f, 0x80, 0x40, 0xaa},
			   (uint8x8_t) {0x7f, 0x80, 0x80, 0xaa, 0x7f, 0x80, 0x80, 0xaa});

  if (a != 0x3344556633445566)
    abort ();
  else if (va[0] != 0x7f
	   || va[1] != 0x80
	   || va[2] != 0x60
	   || va[3] != 0xaa
	   || va[4] != 0x7f
	   || va[5] != 0x80
	   || va[6] != 0x60
	   || va[7] != 0xaa)
    abort ();
  else
    exit (0);
}
