/* This is a test program for rsub16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t rsub16 (uint32_t ra, uint32_t rb)
{
  return __rv__rsub16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_rsub16 (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_rsub16 (ra, rb);
}

int
main ()
{
  uint32_t a = rsub16 (0x7fff7fff7fff7fff, 0x8000800080008000);
  int16x4_t va = v_rsub16 ((int16x4_t) {0x8000, 0x8000, 0x8000, 0x8000},
			   (int16x4_t) {0x7fff, 0x4000, 0x7fff, 0x4000});

  if (a != 0x7fff7fff7fff7fff)
    abort ();
  else if (va[0] != (short) 0x8000
	   || va[1] != (short) 0xa000
	   || va[2] != (short) 0x8000
	   || va[3] != (short) 0xa000)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
