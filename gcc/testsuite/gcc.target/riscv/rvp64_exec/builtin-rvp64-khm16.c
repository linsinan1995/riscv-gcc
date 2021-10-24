/* This is a test program for khm16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t khm16 (uint64_t ra, uint64_t rb)
{
  return __rv_khm16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_khm16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_khm16 (ra, rb);
}

int
main ()
{
  int16x4_t v_sa_p = {0x7fff, 0xc000, 0x7fff, 0xc000};
  uint64_t a = khm16 (0x7fff7fff7fff7fff, 0x7fff7fff7fff7fff);
  int16x4_t va = v_khm16 ((int16x4_t) {0x8000, 0x4000, 0x8000, 0x4000},
			   (int16x4_t) {0x8000, 0x8000, 0x8000, 0x8000});

  if (a != 0x7ffe7ffe7ffe7ffe)
    abort ();
  else if (!vec_all_eq_int16x4_t ( v_sa_p, va))
    abort ();
  else
    exit (0);
}
