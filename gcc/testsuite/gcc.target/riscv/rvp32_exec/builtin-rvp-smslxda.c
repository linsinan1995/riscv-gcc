/* This is a test program for smslxda instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t smslxda (int64_t rt, uint32_t ra, uint32_t rb)
{
  return __rv_smslxda (rt, ra, rb);
}

static __attribute__ ((noinline))
int64_t v_smslxda (int64_t rt, int16x2_t ra, int16x2_t rb)
{
  return __rv_v_smslxda (rt, ra, rb);
}

int
main ()
{
  int64_t a = smslxda (0xff0000000000ll, 0xffffffff, 0x2);
  int64_t va = v_smslxda (0x100000000ll,
			    (int16x2_t) {0xf000, 0}, (int16x2_t) {0, 3});

  if (a != 0xff0000000002ll)
    abort ();
  else if (va != 0x100003000ll)
    abort ();
  else
    exit (0);
}
