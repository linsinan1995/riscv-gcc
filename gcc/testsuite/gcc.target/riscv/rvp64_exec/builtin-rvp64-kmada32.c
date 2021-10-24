/* This is a test program for kmada32 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t kmada32 (int64_t rd, uint64_t ra, uint64_t rb)
{
  return __rv_kmada32 (rd, ra, rb);
}

static __attribute__ ((noinline))
int64_t v_kmada32 (int64_t rd, int32x2_t ra, int32x2_t rb)
{
  return __rv_v_kmada32 (rd, ra, rb);
}

int
main ()
{
  int64_t va_p = 0x1fffa0006;
  int64_t a = kmada32 (0x2, 0x8000000280000002, 0x8000000180000001);
  int64_t va = v_kmada32 (0x2, (int32x2_t) {0xffff0002, 0xffff0002},
		       (int32x2_t) {0xffff0001, 0xffff0001});

  if (a != 0x7ffffffd00000006)
    abort ();
  else if (va != va_p)
    abort ();
  else
    exit (0);
}
