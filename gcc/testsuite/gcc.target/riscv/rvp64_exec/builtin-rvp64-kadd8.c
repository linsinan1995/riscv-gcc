/* This is a test program for add8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t kadd8 (uint64_t ra, uint64_t rb)
{
  return __rv_kadd8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t v_kadd8 (int8x8_t ra, int8x8_t rb)
{
  return __rv_v_kadd8 (ra, rb);
}

int
main ()
{
  uint64_t a = kadd8 (0x1122334411223344, 0x5566778855667788);
  int8x8_t v_sa = v_kadd8 ((int8x8_t) {0x80, 0x7f, 0xbb, 0xaa, 0x80, 0x7f, 0xbb, 0xaa},
			   (int8x8_t) {0x80, 0x7f, 0xbb, 0xaa, 0x80, 0x7f, 0xbb, 0xaa});

  if (a != 0x667f7fcc667f7fccllu)
    abort ();
  else if (v_sa[0] != (signed char) 0x80
	   || v_sa[1] != 0x7f
	   || v_sa[2] != (signed char) 0x80
	   || v_sa[3] != (signed char) 0x80
	   || v_sa[4] != (signed char) 0x80
	   || v_sa[5] != 0x7f
	   || v_sa[6] != (signed char) 0x80
	   || v_sa[7] != (signed char) 0x80)
    abort ();
  else
    exit (0);
}
