/* This is a test program for umar64 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t umar64 (uint64_t t,unsigned int a,unsigned int b)
{
  return __rv_umar64 (t, a, b);
}

int
main ()
{
  uint64_t a = umar64 (0xf000000000000000ull, 0x12345678, 0x23);

  if (a != 0xf00000027d27d268ull)
    abort ();
  else
    exit (0);
}
