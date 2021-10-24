/* This is a test program for smul8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t smul8 (uint32_t ra, uint32_t rb)
{
  return __rv_smul8 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_smul8 (int8x4_t ra, int8x4_t rb)
{
  return __rv_v_smul8 (ra, rb);
}

int
main ()
{
  uint64_t a = smul8 (0xffff0000, 0x0001ffff);
  int16x4_t va = v_smul8 ((int8x4_t) {0xff, 0xee, 0xdd, 0xcc},
			   (int8x4_t) {0x11, 0x22, 0x33, 0x44});

  if (a != 0x0000ffff00000000)
    abort ();
  else if (va[0] != (short) 0xffef
           || va[1] != (short) 0xfd9c
           || va[2] != (short) 0xf907
           || va[3] != (short) 0xf230)
    abort ();
  else
    exit (0);
}
