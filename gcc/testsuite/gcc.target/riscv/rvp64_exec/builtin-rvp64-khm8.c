/* This is a test program for khm8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t khm8 (uint64_t ra, uint64_t rb)
{
  return __rv_khm8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t v_khm8 (int8x8_t ra, int8x8_t rb)
{
  return __rv_v_khm8 (ra, rb);
}

int
main ()
{
  int8x8_t v_sa_p = {0x7f, 0x00, 0xc0, 0x0, 0x7f, 0x00, 0xc0, 0x0};
  uint64_t a = khm8 (0x7fff7fff7fff7fff, 0x7fff7fff7fff7fff);
  int8x8_t va = v_khm8 ((int8x8_t) {0x80, 0x5, 0x40, 0x0, 0x80, 0x5, 0x40, 0x0},
			(int8x8_t) {0x80, 0x0, 0x80, 0x5, 0x80, 0x0, 0x80, 0x5});

  if (a != 0x7e007e007e007e00)
    abort ();
  else if (!vec_all_eq_int8x8_t (v_sa_p, va))
    abort ();
  else
    exit (0);
}
