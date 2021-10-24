/* This is a test program for smal instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t smal (int64_t ra, int64_t rb)
{
  return __rv_smal (ra, rb);
}

static __attribute__ ((noinline))
int64_t v_smal (int64_t ra, int16x4_t rb)
{
  return __rv_v_smal (ra, rb);
}

int
main ()
{
  int64_t a = smal (0xffff0000ffff0000ll, 0x0001ffff0001ffffll);
  int64_t va = v_smal (0xffffff00ffffff00ll,
			 (int16x4_t) {0x0002, 0xffff, 0x0002, 0xffff});
  if (a != 0xffff0000fffefffe)
    abort ();
  else if (va != 0xffffff00fffffefc)
    abort ();
  else
    exit (0);
}
