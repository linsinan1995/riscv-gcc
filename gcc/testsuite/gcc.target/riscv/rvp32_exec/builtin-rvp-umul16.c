/* This is a test program for umul16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t umul16 (uint32_t ra, uint32_t rb)
{
  return __rv_umul16 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_umul16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv_v_umul16 (ra, rb);
}

int
main ()
{
  uint64_t a = umul16 (0xffff0000, 0x0001ffff);
  uint32x2_t va = v_umul16 ((uint16x2_t) {0xffff, 0},
			    (uint16x2_t) {0x0001, 0xffff});
  if (a != 0xffff00000000)
    abort ();
  else if (va[0] != 0xffff
           || va[1] != 0)
    abort ();
  else
    exit (0);
}
