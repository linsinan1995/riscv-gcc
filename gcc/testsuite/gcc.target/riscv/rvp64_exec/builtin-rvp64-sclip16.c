/* This is a test program for sclip16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t sclip16 (int64_t ra)
{
  return __rv_sclip16 (ra, 2);
}

static __attribute__ ((noinline))
int16x4_t v_sclip16 (int16x4_t ra)
{
  return __rv_v_sclip16 (ra, 4);
}

int
main ()
{
  int16x4_t v_sa_p = {0, -16, 15, 3};
  int64_t a = sclip16 (0x1010101010101010);
  int16x4_t v_sa = v_sclip16 ((int16x4_t) {0, -20, 20, 3});

  if (a != 0x3000300030003)
    abort ();
  else if (!vec_all_eq_int16x4_t ( v_sa_p, v_sa))
    abort ();
  else
    exit (0);
}
