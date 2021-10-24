/* This is a test program for ucmplt16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t ucmplt16 (uint64_t ra, uint64_t rb)
{
  return __rv_ucmplt16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_ucmplt16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_ucmplt16 (ra, rb);
}

int
main ()
{
  uint16x4_t va_p = {0, 0xffff, 0, 0xffff};
  uint64_t a = ucmplt16 (0xfffe0001fffe0001, 0xffff0000ffff0000);
  uint16x4_t va = v_ucmplt16 ((uint16x4_t) {0x7fff, 0x7ffe, 0x7fff, 0x7ffe},
			      (uint16x4_t) {0x7ffe, 0x7fff, 0x7ffe, 0x7fff});
  if (a != 0xffff0000ffff0000)
    abort ();
  else if (!vec_all_eq_uint16x4_t ( va_p, va))
    abort ();
  else
    exit (0);
}
