/* This is a test program for sub16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t ksub16 (uint32_t ra, uint32_t rb)
{
  return __rv__ksub16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_ksub16 (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_ksub16 (ra, rb);
}

int
main ()
{
  uint32_t a = ksub16 (0x0001000000010000, 0x0001000100010001);
  int16x4_t v_sa = v_ksub16 ((int16x4_t) {0x7777, 0x2111, 0x7777, 0x2111},
			     (int16x4_t) {0x1000, 0x2000, 0x1000, 0x2000});

  if (a != 0x0000ffff0000ffff)
    abort ();
  else if (v_sa[0] != 0x6777
	   || v_sa[1] != 0x0111
	   || v_sa[2] != 0x6777
	   || v_sa[3] != 0x0111)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
