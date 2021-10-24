/* This is a test program for kmsxda instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t kmsxda (int64_t rd, uint64_t ra, uint64_t rb)
{
  return __rv_kmsxda (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kmsxda (int32x2_t rd, int16x4_t ra, int16x4_t rb)
{
  return __rv_v_kmsxda (rd, ra, rb);
}

int
main ()
{
  int64_t va_p = 0x600000006;
  int64_t a = kmsxda (0x300000003, 0x8000000280000002, 0x8000000180000001);
  int32x2_t va = v_kmsxda ((int32x2_t) {0x3, 0x3},
			   (int16x4_t) {0xffff, 0x0002, 0xffff, 0x0002},
			   (int16x4_t) {0xffff, 0x0001, 0xffff, 0x0001});

  if (a != 0x1800300018003)
    abort ();
  else if (va[0] != 6
	   || va[1] != 6)
    abort ();
  else
    exit (0);
}
