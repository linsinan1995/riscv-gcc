/* This is a test program for swap16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t swap16 (uint64_t a)
{
  return __rv_swap16 (a);
}

static __attribute__ ((noinline))
uint16x4_t v_swap16 (uint16x4_t a)
{
  return __rv_v_swap16 (a);
}

int
main ()
{
  int i;
  uint64_t a = 0x03020100;
  uint64_t b;
  uint16x4_t va = (uint16x4_t) {0x1000, 0x0001, 0x2000, 0x0002};
  uint16x4_t res;
  b = swap16 (a);
  res = v_swap16 (va);

  if (b != 0x01000302)
    abort ();
  else
    exit (0);
  
  if (vec_all_eq_uint16x4_t (res, (uint16x4_t) {0x0001, 0x1000, 0x0002, 0x2000}))
    abort ();
  else
    exit (0);
}
