/* This is a test program for kmsr64 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t kmsr64 (int64_t rd, int64_t ra, int64_t rb)
{
  return __rv_kmsr64 (rd, ra, rb);
}

int
main ()
{
  int64_t a = kmsr64 (0x1, 0xffff0000ffff0000ll, 0x0001ffff0001ffffll);

  if (a != 0x3fffe0001ll)
    abort ();
  else
    exit (0);
}
