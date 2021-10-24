/* This is a test program for kslraw instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t kslraw (int32_t ra, int32_t rb)
{
  return __rv_kslraw (ra, rb);
}

int
main ()
{
  int64_t a = kslraw (0x0f00f000, 4);

  if (a != 0x7fffffff)
    abort ();
  else
    exit (0);
}
