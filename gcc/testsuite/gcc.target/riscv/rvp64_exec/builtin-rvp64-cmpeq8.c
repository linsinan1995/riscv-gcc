/* This is a test program for cmpeq8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t cmpeq8 (uint64_t ra, uint64_t rb)
{
  return __rv_cmpeq8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t v_scmpeq8 (int8x8_t ra, int8x8_t rb)
{
  return __rv_v_scmpeq8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t v_ucmpeq8 (uint8x8_t ra, uint8x8_t rb)
{
  return __rv_v_ucmpeq8 (ra, rb);
}

int
main ()
{
  uint8x8_t v_ua_p = {0xff, 0xff, 0, 0, 0xff, 0xff, 0, 0};
  uint8x8_t v_sa_p = {0xff, 0xff, 0, 0, 0xff, 0xff, 0, 0};
  uint64_t a = cmpeq8 (0xffff0000ffff0000, 0xffff0101ffff0101);
  uint8x8_t v_sa = v_scmpeq8 ((int8x8_t) {0x7f, 0x7f, 0x01, 0x01, 0x7f, 0x7f, 0x01, 0x01},
			      (int8x8_t) {0x7f, 0x7f, 0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00});
  uint8x8_t v_ua = v_ucmpeq8 ((uint8x8_t) {0x7f, 0x7f, 0x01, 0x01, 0x7f, 0x7f, 0x01, 0x01},
			      (uint8x8_t) {0x7f, 0x7f, 0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00});

  if (a != 0xffff0000ffff0000)
    abort ();
  else if (!vec_all_eq_uint8x8_t (v_sa_p, v_sa))
    abort ();
  else if (!vec_all_eq_uint8x8_t (v_ua_p, v_ua))
    abort ();
  else
    exit (0);
}
