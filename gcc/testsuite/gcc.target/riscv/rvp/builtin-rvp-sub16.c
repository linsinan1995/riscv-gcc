/* This is a test program for sub16 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t sub16 (uint32_t ra, uint32_t rb)
{
  return __rv__sub16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_usub16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_usub16 (ra, rb);
}

static __attribute__ ((noinline))
int16x2_t v_ssub16 (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_ssub16 (ra, rb);
}

int
main ()
{
  uint32_t a = sub16 (0x00010000, 0x00010001);
  uint16x2_t v_ua = v_usub16 ((uint16x2_t) {0x1000, 0x0001},
			      (uint16x2_t) {0xf000, 0x0000});
  int16x2_t v_sa = v_ssub16 ((int16x2_t) {0x7777, 0x2111},
			     (int16x2_t) {0x1000, 0x2000});

  if (a != 0x0000ffff)
    abort ();
  else if (v_ua[0] != 0x2000
	   || v_ua[1] != 0x0001)
    abort ();
  else if (v_sa[0] != 0x6777
	   || v_sa[1] != 0x0111)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
