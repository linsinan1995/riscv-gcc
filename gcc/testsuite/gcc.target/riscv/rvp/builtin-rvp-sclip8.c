/* This is a test program for add8 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
signed int32_t sclip8 (signed int32_t ra)
{
  return __rv__sclip8 (ra, 2);
}

static __attribute__ ((noinline))
int8x4_t v_sclip8 (int8x4_t ra)
{
  return __rv__v_sclip8 (ra, 3);
}

int
main ()
{
  signed int32_t a = sclip8 (0x10101010);
  int8x4_t v_sa = v_sclip8 ((int8x4_t) {0, -20, 11, 3});

  if (a != 0x03030303)
    abort ();
  else if (v_sa[0] != 0
	   || v_sa[1] != -8
	   || v_sa[2] != 7
	   || v_sa[3] != 3)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
