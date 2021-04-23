/* This is a test program for add8 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t ukadd8 (uint32_t ra, uint32_t rb)
{
  return __rv__ukadd8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t v_ukadd8 (uint8x8_t ra, uint8x8_t rb)
{
  return __rv__v_ukadd8 (ra, rb);
}

int
main ()
{
  uint32_t a = ukadd8 (0x1122334411223344, 0x5566778855667788);
  uint8x8_t v_ua = v_ukadd8 ((uint8x8_t) {0xff, 0xee, 0xdd, 0xcc, 0xff, 0xee, 0xdd, 0xcc},
			     (uint8x8_t) {0x1, 0xee, 0xdd, 0xcc, 0x1, 0xee, 0xdd, 0xcc});

  if (a != 0x6688aacc6688aacc)
    abort ();
  else if (v_ua[0] != 0xff
	   || v_ua[1] != 0xff
	   || v_ua[2] != 0xff
	   || v_ua[3] != 0xff
	   || v_ua[4] != 0xff
	   || v_ua[5] != 0xff
	   || v_ua[6] != 0xff
	   || v_ua[7] != 0xff)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
