/* This is a test program for khmtt instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int32_t khmtt (uint32_t ra, uint32_t rb)
{
  return __rv_khmtt (ra, rb);
}

static __attribute__ ((noinline))
int32_t v_khmtt (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_khmtt (ra, rb);
}

int
main ()
{
  int32_t a = khmtt (0x0001f000, 0x00011000);
  int32_t v_sa = v_khmtt ((int16x2_t) {0xf777, 0xf111},
		       (int16x2_t) {0x1000, 0x2000});
  if (a != 0)
    abort ();
  else if (v_sa != 0xfffffffffffffc44)
    abort ();
  else
    exit (0);
}
