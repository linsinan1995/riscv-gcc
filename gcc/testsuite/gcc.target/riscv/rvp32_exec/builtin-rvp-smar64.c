/* This is a test program for smar64 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t smar64 (int64_t t, int a, int b)
{
  return __rv_smar64 (t, a, b);
}

int
main ()
{
  int64_t a = smar64 (0xf000000000000000ll, 0x12345678, 0x23);

  if (a != 0xf00000027d27d268ll)
    abort ();
  else
    exit (0);
}
