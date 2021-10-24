/* This is a test program for smax16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t smax16 (uint64_t ra, uint64_t rb)
{
  return __rv_smax16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_smax16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_smax16 (ra, rb);
}

int
main ()
{
  int16x4_t va_p = {0x7fff, 1, 0x7fff, 1};
  uint64_t a = smax16 (0xfffe0001fffe0001, 0xffff0000ffff0000);
  int16x4_t va = v_smax16 ((int16x4_t) {0x7fff, 0, 0x7fff, 0},
			   (int16x4_t) {0x7ffe, 1, 0x7ffe, 1});
  if (a != 0xffff0001ffff0001)
    abort ();
  else if (!vec_all_eq_int16x4_t ( va_p, va))
    abort ();
  else
    exit (0);
}
