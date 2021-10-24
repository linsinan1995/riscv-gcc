/* This is a test program for add16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t kadd16 (uint64_t ra, uint64_t rb)
{
  return __rv_kadd16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_kadd16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_kadd16 (ra, rb);
}

int
main ()
{
  uint64_t a = kadd16 (0x0001f0000001f000, 0x0001100000011000);
  int16x4_t v_sa = v_kadd16 ((int16x4_t) {0xf777, 0xf111, 0xf777, 0xf111},
			     (int16x4_t) {0x1000, 0x2000, 0x1000, 0x2000});

  if (a != 0x0002000000020000llu)
    abort ();
  else if (v_sa[0] != 0x0777
	   || v_sa[1] != 0x1111
	   || v_sa[2] != 0x0777
	   || v_sa[3] != 0x1111)
    abort ();
  else
    exit (0);
}
