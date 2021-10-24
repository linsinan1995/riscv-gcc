/* This is a test program for srl16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t srl16 (uint64_t ra, uint32_t rb)
{
  return __rv_srl16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_srl16 (uint16x4_t ra, uint32_t rb)
{
  return __rv_v_srl16 (ra, rb);
}

int
main ()
{
  uint16x4_t va_p = {0x7ff, 0x0800, 0x7ff, 0x0800};
  uint64_t a = srl16 (0x0f00f0000f00f000, 4);
  uint16x4_t va = v_srl16 ((uint16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000}, 4);

  if (a != 0x00f00f0000f00f00)
    abort ();
  else if (!vec_all_eq_uint16x4_t ( va_p, va))
    abort ();
  else
    exit (0);
}
