/* This is a test program for ursub64 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t ursub64 (uint64_t ra, uint64_t rb)
{
  return __rv_ursub64 (ra, rb);
}

int
main ()
{
  uint64_t a = ursub64 (0xeull, 0xfull);

  if (a != 0xffffffffffffffffull)
    abort ();
  else
    exit (0);
}
