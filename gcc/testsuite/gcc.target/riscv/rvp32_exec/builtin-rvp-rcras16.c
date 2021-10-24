/* This is a test program for rcras16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t rcras16 (uint32_t ra, uint32_t rb)
{
  return __rv_rcras16 (ra, rb);
}

static __attribute__ ((noinline))
int16x2_t v_rcras16 (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_rcras16 (ra, rb);
}

int
main ()
{
  int16x2_t va_p = {0x7fff, 0x8000};
  uint32_t a = rcras16 (0x0fff0000, 0x00000fff);
  int16x2_t va = v_rcras16 ((int16x2_t) {0x7fff, 0x8000},
			    (int16x2_t) {0x8000, 0x8000});

  if (a != 0x0fff0000)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
