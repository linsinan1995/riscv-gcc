/* This is a test program for add8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t sclip8 (int32_t ra)
{
  return __rv_sclip8 (ra, 2);
}

static __attribute__ ((noinline))
int8x4_t v_sclip8 (int8x4_t ra)
{
  return __rv_v_sclip8 (ra, 3);
}

int
main ()
{
  int32_t a = sclip8 (0x10101010);
  int8x4_t v_sa = v_sclip8 ((int8x4_t) {0, -20, 11, 3});

  if (a != 0x03030303)
    abort ();
  else if (v_sa[0] != 0
	   || v_sa[1] != -8
	   || v_sa[2] != 7
	   || v_sa[3] != 3)
    abort ();
  else
    exit (0);
}
