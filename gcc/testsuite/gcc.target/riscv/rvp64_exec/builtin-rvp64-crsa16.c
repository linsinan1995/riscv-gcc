/* This is a test program for crsa16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t crsa16 (uint64_t ra, uint64_t rb)
{
  return __rv_crsa16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_ucrsa16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_ucrsa16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_scrsa16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_scrsa16 (ra, rb);
}

int
main ()
{
  uint16x4_t v_ua_p = {0x2469, 0xe000, 0x2469, 0xe000};
  int16x4_t v_sa_p = {0x3000, 0x110, 0x3000, 0x110};
  uint64_t a = crsa16 (0x0001f0000001f000, 0x0001f0000001f000);
  uint16x4_t v_ua = v_ucrsa16 ((uint16x4_t) {0x1235, 0xf000, 0x1235, 0xf000},
			       (uint16x4_t) {0x1000, 0x1234, 0x1000, 0x1234});
  int16x4_t v_sa = v_scrsa16 ((int16x4_t) {0x2000, 0x0111, 0x2000, 0x0111},
			      (int16x4_t) {0x0001, 0x1000, 0x0001, 0x1000});

  if (a != 0x1001f0011001f001)
    abort ();
  else if (v_ua[0] != v_ua_p[0]
	   || v_ua[1] != v_ua_p[1]
	   || v_ua[2] != v_ua_p[2]
	   || v_ua[3] != v_ua_p[3])
    abort ();
  else if (v_sa[0] != v_sa_p[0]
	   || v_sa[1] != v_sa_p[1]
	   || v_sa[2] != v_sa_p[2]
	   || v_sa[3] != v_sa_p[3])
    abort ();
  else
    exit (0);
}
