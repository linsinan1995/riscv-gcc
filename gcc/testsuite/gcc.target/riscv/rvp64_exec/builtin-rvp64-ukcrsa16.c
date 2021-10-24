/* This is a test program for crsa16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t ukcrsa16 (uint64_t ra, uint64_t rb)
{
  return __rv_ukcrsa16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_ukcrsa16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_ukcrsa16 (ra, rb);
}

int
main ()
{
  uint16x4_t v_ua_p = {0x2469, 0xe000, 0x2469, 0xe000};
  uint64_t a = ukcrsa16 (0x0001f0000001f000, 0x0001f0000001f000);
  uint16x4_t v_ua = v_ukcrsa16 ((uint16x4_t) {0x1235, 0xf000, 0x1235, 0xf000},
			        (uint16x4_t) {0x1000, 0x1234, 0x1000, 0x1234});

  if (a != 0xf0010000f001)
    abort ();
  else if (v_ua[0] != v_ua_p[0]
	   || v_ua[1] != v_ua_p[1]
	   || v_ua[2] != v_ua_p[2]
	   || v_ua[3] != v_ua_p[3])
    abort ();
  else
    exit (0);
}
