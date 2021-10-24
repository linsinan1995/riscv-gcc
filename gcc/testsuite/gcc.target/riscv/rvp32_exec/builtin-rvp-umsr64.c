/* This is a test program for umsr64 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t umsr64 (uint64_t t, unsigned int a, unsigned int b)
{
  return __rv_umsr64 (t, a, b);
}

int
main ()
{
  uint64_t a = umsr64 (0x5000000300000000ull, 0x12345678, 0x23);

  if (a != 0x5000000082D82D98ull)
    abort ();
  else
    exit (0);
}
