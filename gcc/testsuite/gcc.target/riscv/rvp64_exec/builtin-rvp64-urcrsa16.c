/* This is a test program for urcrsa16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t urcrsa16 (uint64_t ra, uint64_t rb)
{
  return __rv_urcrsa16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_urcrsa16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_urcrsa16 (ra, rb);
}

int
main ()
{
  uint16x4_t va_p = {0x8000, 0xffff, 0x8000, 0xffff};
  uint64_t a = urcrsa16 (0x7fff7fff7fff7fff, 0x7fff80007fff8000);
  uint16x4_t va = v_urcrsa16 ((uint16x4_t) {0x8000, 0x7fff, 0x8000, 0x7fff},
			      (uint16x4_t) {0x8000, 0x8000, 0x8000, 0x8000});

  if (a != 0xffff7fffffff7fff)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1]
	   || va[2] != va_p[2]
	   || va[3] != va_p[3])
    abort ();
  else
    exit (0);
}
