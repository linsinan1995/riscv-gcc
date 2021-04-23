/* This is a test program for cmpeq16 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t cmpeq16 (uint32_t ra, uint32_t rb)
{
  return __rv__cmpeq16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_scmpeq16 (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_scmpeq16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_ucmpeq16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_ucmpeq16 (ra, rb);
}

int
main ()
{
  uint32_t a = cmpeq16 (0xffff0000, 0xffff0001);
  uint16x2_t v_sa = v_scmpeq16 ((int16x2_t) {0x7fff, 0x8000},
				(int16x2_t) {0x8000, 0x8000});
  uint16x2_t v_ua = v_ucmpeq16 ((uint16x2_t) {0x7fff, 0x8000},
				(uint16x2_t) {0x8000, 0x8000});

  if (a != 0xffff0000)
    abort ();
  else if (v_sa[0] != 0
	   || v_sa[1] != 0xffff)
    abort ();
  else if (v_ua[0] != 0
	   || v_ua[1] != 0xffff)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
