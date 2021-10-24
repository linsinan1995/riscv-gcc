/* This is a test program for rsub8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t rsub8 (uint64_t ra, uint64_t rb)
{
  return __rv_rsub8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t v_rsub8 (int8x8_t ra, int8x8_t rb)
{
  return __rv_v_rsub8 (ra, rb);
}

int
main ()
{
  uint64_t a = rsub8 (0x5566778855667788, 0x1122334411223344);
  int8x8_t va = v_rsub8 ((int8x8_t) {0x7f, 0x80, 0x80, 0xaa, 0x7f, 0x80, 0x80, 0xaa},
			 (int8x8_t) {0x80, 0x7f, 0x40, 0xaa, 0x80, 0x7f, 0x40, 0xaa});

  if (a != 0x222222a2222222a2)
    abort ();
  else if (va[0] != 0x7f
	   || va[1] != (signed char) 0x80
	   || va[2] != (signed char) 0xa0
	   || va[3] != 0
	   || va[4] != 0x7f
	   || va[5] != (signed char) 0x80
	   || va[6] != (signed char) 0xa0
	   || va[7] != 0)
    abort ();
  else
    exit (0);
}
