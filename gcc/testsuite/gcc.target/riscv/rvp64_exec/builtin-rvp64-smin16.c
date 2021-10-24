/* This is a test program for smin16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t smin16 (uint64_t ra, uint64_t rb)
{
  return __rv_smin16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_smin16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_smin16 (ra, rb);
}

int
main ()
{
  int16x4_t v_sa_p = {0x7ffe, 0, 0x7ffe, 0};
  uint64_t a = smin16 (0xfffe0001fffe0001, 0xffff0000ffff0000);
  int16x4_t v_sa = v_smin16 ((int16x4_t) {0x7fff, 0, 0x7fff, 0},
			     (int16x4_t) {0x7ffe, 1, 0x7ffe, 1});
  if (a != 0xfffe0000fffe0000)
    abort ();
  else if (!vec_all_eq_int16x4_t ( v_sa_p, v_sa))
    abort ();
  else
    exit (0);
}
