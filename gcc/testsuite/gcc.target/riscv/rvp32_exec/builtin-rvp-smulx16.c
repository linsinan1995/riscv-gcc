/* This is a test program for smulx16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t smulx16 (uint32_t ra, uint32_t rb)
{
  return __rv_smulx16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_smulx16 (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_smulx16 (ra, rb);
}

int
main ()
{
  uint64_t a = smulx16 (0xffff0000, 0xffff0001);
  int32x2_t va = v_smulx16 ((int16x2_t) {0xffff, 0xffff},
			    (int16x2_t) {1, 0});
  if (a != 0xffffffff00000000)
    abort ();
  else if (va[0] != 0
           || va[1] != 0xffffffff)
    abort ();
  else
    exit (0);
}
