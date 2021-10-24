/* This is a test program for umulx8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t umulx8 (uint32_t ra, uint32_t rb)
{
  return __rv_umulx8 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_umulx8 (uint8x4_t ra, uint8x4_t rb)
{
  return __rv_v_umulx8 (ra, rb);
}

int
main ()
{
  uint64_t a = umulx8 (0xffff0000, 0x0001ffff);
  uint16x4_t va = v_umulx8 ((uint8x4_t) {0xff, 0xee, 0xdd, 0xcc},
			    (uint8x4_t) {0x11, 0x22, 0x33, 0x44});

  if (a != 0xff000000000000)
    abort ();
  else if (va[0] != 0x21de
           || va[1] != 0xfce
           || va[2] != 0x3ab4
           || va[3] != 0x28a4)
    abort ();
  else
    exit (0);
}
