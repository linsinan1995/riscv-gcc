/* This is a test program for add16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t ukadd16 (uint32_t ra, uint32_t rb)
{
  return __rv__ukadd16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_ukadd16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv__v_ukadd16 (ra, rb);
}

int
main ()
{
  uint32_t a = ukadd16 (0x0001f0000001f000, 0x0001100000011000);
  uint16x4_t v_ua = v_ukadd16 ((uint16x4_t) {0xf000, 0xf000, 0xf000, 0xf000},
			       (uint16x4_t) {0x1000, 0x2000, 0x1000, 0x2000});

  if (a != 0x0002ffff0002ffff)
    abort ();
  else if (v_ua[0] != 0xffff
	   || v_ua[1] != 0xffff
	   || v_ua[2] != 0xffff
	   || v_ua[3] != 0xffff)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
