/* This is a test program for sub16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t uksub16 (uint32_t ra, uint32_t rb)
{
  return __rv__uksub16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_uksub16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv__v_uksub16 (ra, rb);
}

int
main ()
{
  uint32_t a = uksub16 (0x0001000000010000, 0x0001000100010001);
  uint16x4_t v_ua = v_uksub16 ((uint16x4_t) {0x1000, 0x0001, 0x1000, 0x0001},
			       (uint16x4_t) {0xf000, 0x0000, 0xf000, 0x0000});

  if (a != 0)
    abort ();
  else if (v_ua[0] != 0
	   || v_ua[1] != 0x0001
	   || v_ua[2] != 0
	   || v_ua[3] != 0x0001)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
