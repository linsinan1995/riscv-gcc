/* This is a test program for sub16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t sub16 (uint64_t ra, uint64_t rb)
{
  return __rv_sub16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_usub16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_usub16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_ssub16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_ssub16 (ra, rb);
}

int
main ()
{
  uint64_t a = sub16 (0x0001000000010000, 0x0001000100010001);
  uint16x4_t v_ua = v_usub16 ((uint16x4_t) {0x1000, 0x0001, 0x1000, 0x0001},
			      (uint16x4_t) {0xf000, 0x0000, 0xf000, 0x0000});
  int16x4_t v_sa = v_ssub16 ((int16x4_t) {0x7777, 0x2111, 0x7777, 0x2111},
			     (int16x4_t) {0x1000, 0x2000, 0x1000, 0x2000});

  if (a != 0x0000ffff0000ffff)
    abort ();
  else if (v_ua[0] != 0x2000
	   || v_ua[1] != 0x0001
	   || v_ua[2] != 0x2000
	   || v_ua[3] != 0x0001)
    abort ();
  else if (v_sa[0] != 0x6777
	   || v_sa[1] != 0x0111
	   || v_sa[2] != 0x6777
	   || v_sa[3] != 0x0111)
    abort ();
  else
    exit (0);
}
