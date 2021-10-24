/* This is a test program for sub8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t uksub8 (uint64_t ra, uint64_t rb)
{
  return __rv_uksub8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t v_uksub8 (uint8x8_t ra, uint8x8_t rb)
{
  return __rv_v_uksub8 (ra, rb);
}

int
main ()
{
  uint64_t a = uksub8 (0x5566778855667788, 0x1122334411223344);
  uint8x8_t v_ua = v_uksub8 ((uint8x8_t) {0xff, 0xee, 0xee, 0xcc, 0xff, 0xee, 0xee, 0xcc},
			     (uint8x8_t) {0x1, 0xee, 0xdd, 0xdd, 0x1, 0xee, 0xdd, 0xdd});

  if (a != 0x4444444444444444ull)
    abort ();
  else if (v_ua[0] != 0xfe
	   || v_ua[1] != 0
	   || v_ua[2] != 0x11
	   || v_ua[3] != 0
	   || v_ua[4] != 0xfe
	   || v_ua[5] != 0
	   || v_ua[6] != 0x11
	   || v_ua[7] != 0)
    abort ();
  else
    exit (0);
}
