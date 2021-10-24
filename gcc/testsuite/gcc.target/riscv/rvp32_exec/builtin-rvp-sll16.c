/* This is a test program for sll16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sll16 (uint32_t ra, uint32_t rb)
{
  return __rv_sll16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_sll16 (uint16x2_t ra, uint32_t rb)
{
  return __rv_v_sll16 (ra, rb);
}

int
main ()
{
  uint32_t a = sll16 (0x0f00f000, 4);
  uint16x2_t va = v_sll16 ((uint16x2_t) {0x7fff, 0x8000}, 4);

  if (a != 0xf0000000)
    abort ();
  else if (va[0] != 0xfff0
	   || va[1] != 0)
    abort ();
  else
    exit (0);
}
