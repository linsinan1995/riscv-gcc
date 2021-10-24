/* This is a test program for urcras16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t urcras16 (uint64_t ra, uint64_t rb)
{
  return __rv_urcras16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_urcras16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_urcras16 (ra, rb);
}

int
main ()
{
  uint16x4_t va_p = {0xffff, 0x8000, 0xffff, 0x8000};
  uint64_t a = urcras16 (0x7fff7fff7fff7fff, 0x80007fff80007fff);
  uint16x4_t va = v_urcras16 ((uint16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000},
			      (uint16x4_t) {0x8000, 0x8000, 0x8000, 0x8000});

  if (a != 0x7fffffff7fffffff)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1]
	   || va[2] != va_p[2]
	   || va[3] != va_p[3])
    abort ();
  else
    exit (0);
}
