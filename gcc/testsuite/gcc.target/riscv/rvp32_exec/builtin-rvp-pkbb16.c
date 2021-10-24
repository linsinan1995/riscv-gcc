/* This is a test program for pkbb16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t pkbb16 (uint32_t ra, uint32_t rb)
{
  return __rv_pkbb16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_pkbb16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv_v_pkbb16 (ra, rb);
}

int
main ()
{
  uint16x2_t va_p = {0xcccc, 0xaaaa};
  uint32_t a = pkbb16 (0x11223344, 0x55667788);
  uint16x2_t va = v_pkbb16 ((uint16x2_t) {0xaaaa, 0xbbbb},
			    (uint16x2_t) {0xcccc, 0xdddd});

  if (a != 0x33447788)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
