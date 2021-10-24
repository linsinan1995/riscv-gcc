/* This is a test program for rcrsa16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t rcrsa16 (uint64_t ra, uint64_t rb)
{
  return __rv_rcrsa16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_rcrsa16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_rcrsa16 (ra, rb);
}

int
main ()
{
  int16x4_t va_p = {0x8000, 0x8000, 0x8000, 0x8000};
  uint64_t a = rcrsa16 (0x7fff7fff7fff7fff, 0x7fff80007fff8000);
  int16x4_t va = v_rcrsa16 ((int16x4_t) {0x8000, 0x8000, 0x8000, 0x8000},
			    (int16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000});

  if (a != 0x7fff7fff7fff7fff)
    abort ();
  else if (va[0] != va_p [0]
	   || va[1] != va_p [1]
	   || va[2] != va_p [2]
	   || va[3] != va_p [3])
    abort ();
  else
    exit (0);
}
