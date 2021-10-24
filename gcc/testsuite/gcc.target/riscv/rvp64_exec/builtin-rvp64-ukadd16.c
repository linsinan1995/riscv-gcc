/* This is a test program for add16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t ukadd16 (uint64_t ra, uint64_t rb)
{
  return __rv_ukadd16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_ukadd16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_ukadd16 (ra, rb);
}

int
main ()
{
  uint64_t a = ukadd16 (0x0001f0000001f000, 0x0001100000011000);
  uint16x4_t v_ua = v_ukadd16 ((uint16x4_t) {0xf000, 0xf000, 0xf000, 0xf000},
			       (uint16x4_t) {0x1000, 0x2000, 0x1000, 0x2000});

  if (a != 0x0002ffff0002ffff)
    abort ();
  else if (v_ua[0] != 0xffff
	   || v_ua[1] != 0xffff
	   || v_ua[2] != 0xffff
	   || v_ua[3] != 0xffff)
    abort ();
  else
    exit (0);
}
