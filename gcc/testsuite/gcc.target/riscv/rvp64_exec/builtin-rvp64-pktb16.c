/* This is a test program for pktb16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t pktb16 (uint64_t ra, uint64_t rb)
{
  return __rv_pktb16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_pktb16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_pktb16 (ra, rb);
}

int
main ()
{
  uint16x4_t va_p = {0xcccc, 0xbbbb, 0xcccc, 0xbbbb};
  uint64_t a = pktb16 (0x1122334411223344, 0x5566778855667788);
  uint16x4_t va = v_pktb16 ((uint16x4_t) {0xaaaa, 0xbbbb, 0xaaaa, 0xbbbb},
			    (uint16x4_t) {0xcccc, 0xdddd, 0xcccc, 0xdddd});

  if (a != 0x1122778811227788)
    abort ();
  else if (!vec_all_eq_uint16x4_t (va_p, va))
    abort ();
  else
    exit (0);
}
