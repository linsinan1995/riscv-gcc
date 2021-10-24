/* This is a test program for umin8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t umin8 (uint64_t ra, uint64_t rb)
{
  return __rv_umin8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t v_umin8 (uint8x8_t ra, uint8x8_t rb)
{
  return __rv_v_umin8 (ra, rb);
}

int
main ()
{
  uint8x8_t v_sa_p = {0x7f, 0xfe, 0, 0x15, 0x7f, 0xfe, 0, 0x15};
  uint64_t a = umin8 (0xfffe0001fffe0001, 0xffff0000ffff0000);
  uint8x8_t v_sa = v_umin8 ((uint8x8_t) {0x7f, 0xff, 0x0, 0x15, 0x7f, 0xff, 0x0, 0x15},
			    (uint8x8_t) {0x7f, 0xfe, 0x1, 0x23, 0x7f, 0xfe, 0x1, 0x23});
  if (a != 0xfffe0000fffe0000)
    abort ();
  else if (!vec_all_eq_uint8x8_t (v_sa_p, v_sa))
    abort ();
  else
    exit (0);
}
