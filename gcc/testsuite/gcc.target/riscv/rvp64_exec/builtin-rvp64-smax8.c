/* This is a test program for smax8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t smax8 (uint64_t ra, uint64_t rb)
{
  return __rv_smax8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t v_smax8 (int8x8_t ra, int8x8_t rb)
{
  return __rv_v_smax8 (ra, rb);
}

int
main ()
{
  int8x8_t v_sa_p = {0x7f, 0xff, 0x1, 0x23, 0x7f, 0xff, 0x1, 0x23};
  uint64_t a = smax8 (0xfffe0001fffe0001, 0xffff0000ffff0000);
  int8x8_t v_sa = v_smax8 ((int8x8_t) {0x7f, 0xff, 0x0, 0x15, 0x7f, 0xff, 0x0, 0x15},
			   (int8x8_t) {0x7f, 0xfe, 0x1, 0x23, 0x7f, 0xfe, 0x1, 0x23});
  if (a != 0xffff0001ffff0001)
    abort ();
  else if (!vec_all_eq_int8x8_t (v_sa_p, v_sa))
    abort ();
  else
    exit (0);
}
