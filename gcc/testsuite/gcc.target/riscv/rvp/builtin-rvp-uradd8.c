/* This is a test program for uradd8 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t uradd8 (uint32_t ra, uint32_t rb)
{
  return __rv__uradd8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t v_uradd8 (uint8x4_t ra, uint8x4_t rb)
{
  return __rv__v_uradd8 (ra, rb);
}

int
main ()
{
  uint32_t a = uradd8 (0x11223344, 0x55667788);
  uint8x4_t va = v_uradd8 ((uint8x4_t) {0x7f, 0x80, 0x40, 0xaa},
			   (uint8x4_t) {0x7f, 0x80, 0x80, 0xaa});

  if (a != 0x33445566)
    abort ();
  else if (va[0] != 0x7f
	   || va[1] != 0x80
	   || va[2] != 0x60
	   || va[3] != 0xaa)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
