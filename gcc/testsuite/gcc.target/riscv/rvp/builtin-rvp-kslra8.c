/* This is a test program for add8 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t uclip8 (uint32_t ra)
{
  return __rv__uclip8 (ra, 2);
}

static __attribute__ ((noinline))
uint8x4_t v_uclip8 (uint8x4_t ra)
{
  return __rv__v_uclip8 (ra, 3);
}

int
main ()
{
  signed int32_t a = uclip8 (0x10101010);
  uint8x4_t v_sa = v_uclip8 ((uint8x4_t) {1, -20, 11, 3});

  if (a != 0x03030303)
    abort ();
  else if (v_sa[0] != 1
	   || v_sa[1] != 0
	   || v_sa[2] != 7
	   || v_sa[3] != 3)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
