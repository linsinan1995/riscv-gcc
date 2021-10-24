/* This is a test program for scmple8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t scmple8 (uint64_t ra, uint64_t rb)
{
  return __rv_scmple8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t v_scmple8 (int8x8_t ra, int8x8_t rb)
{
  return __rv_v_scmple8 (ra, rb);
}

int
main ()
{
  uint8x8_t va_p = {0xff, 0xff, 0, 0, 0xff, 0xff, 0, 0};
  uint64_t a = scmple8 (0xfefe0101fefe0101, 0xffff0000ffff0000);
  uint8x8_t va = v_scmple8 ((int8x8_t) {0x7e, 0x7e, 0x01, 0x01, 0x7e, 0x7e, 0x01, 0x01},
			    (int8x8_t) {0x7f, 0x7f, 0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00});

  if (a != 0xffff0000ffff0000)
    abort ();
  else if (!vec_all_eq_uint8x8_t (va_p, va))
    abort ();
  else
    exit (0);
}
