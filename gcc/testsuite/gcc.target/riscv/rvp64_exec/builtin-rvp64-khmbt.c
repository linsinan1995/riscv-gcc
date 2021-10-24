/* This is a test program for khmbt instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t khmbt (uint32_t ra, uint32_t rb)
{
  return __rv_khmbt (ra, rb);
}

static __attribute__ ((noinline))
int64_t v_khmbt (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_khmbt (ra, rb);
}

int
main ()
{
  int64_t a = khmbt (0x0001f000, 0x00011000);
  int64_t v_sa = v_khmbt ((int16x2_t) {0xf777, 0xf111},
		       (int16x2_t) {0x1000, 0x2000});
  if (a != 0xffffffffffffffff)
    abort ();
  else if (v_sa != 0xfffffffffffffddd)
    abort ();
  else
    exit (0);
}
