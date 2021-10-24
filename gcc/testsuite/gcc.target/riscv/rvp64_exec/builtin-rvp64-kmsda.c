/* This is a test program for kmsda instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t kmsda (int64_t rd, uint64_t ra, uint64_t rb)
{
  return __rv_kmsda (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kmsda (int32x2_t rd, int16x4_t ra, int16x4_t rb)
{
  return __rv_v_kmsda (rd, ra, rb);
}

int
main ()
{
  int64_t va_p = 0;
  int64_t a = kmsda (0x300000003, 0x8000000280000002, 0x8000000180000001);
  int32x2_t va = v_kmsda ((int32x2_t) {0x3, 0x3},
			  (int16x4_t) {0xffff, 0x0002, 0xffff, 0x0002},
			  (int16x4_t) {0xffff, 0x0001, 0xffff, 0x0001});

  if (a != 0xc0000001c0000001)
    abort ();
  else if (va[0] != 0
	   || va[1] != 0)
    abort ();
  else
    exit (0);
}
