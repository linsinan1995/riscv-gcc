/* This is a test program for add8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t ukadd8 (uint64_t ra, uint64_t rb)
{
  return __rv_ukadd8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t v_ukadd8 (uint8x8_t ra, uint8x8_t rb)
{
  return __rv_v_ukadd8 (ra, rb);
}

int
main ()
{
  uint64_t a = ukadd8 (0x1122334411223344, 0x5566778855667788);
  uint8x8_t v_ua = v_ukadd8 ((uint8x8_t) {0xff, 0xee, 0xdd, 0xcc, 0xff, 0xee, 0xdd, 0xcc},
			     (uint8x8_t) {0x1, 0xee, 0xdd, 0xcc, 0x1, 0xee, 0xdd, 0xcc});

  if (a != 0x6688aacc6688aacc)
    abort ();
  else if (v_ua[0] != 0xff
	   || v_ua[1] != 0xff
	   || v_ua[2] != 0xff
	   || v_ua[3] != 0xff
	   || v_ua[4] != 0xff
	   || v_ua[5] != 0xff
	   || v_ua[6] != 0xff
	   || v_ua[7] != 0xff)
    abort ();
  else
    exit (0);
}
