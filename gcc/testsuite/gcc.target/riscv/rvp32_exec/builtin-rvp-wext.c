/* This is a test program for wext instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t wext (int64_t ra, uint32_t rb)
{
  return __rv_wext (ra, rb);
}

int
main ()
{
  uint32_t a = wext (0x1234ffff0000ll, 16);

  if (a != 0x1234ffff)
    abort ();
  else
    exit (0);
}
