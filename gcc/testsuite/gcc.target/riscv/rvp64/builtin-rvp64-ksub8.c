/* This is a test program for sub8 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t ksub8 (uint32_t ra, uint32_t rb)
{
  return __rv__ksub8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t v_ksub8 (int8x8_t ra, int8x8_t rb)
{
  return __rv__v_ksub8 (ra, rb);
}

int
main ()
{
  uint32_t a = ksub8 (0x5566778855667788, 0x1122334411223344);
  int8x8_t v_sa = v_ksub8 ((int8x8_t) {0x81, 0x0, 0xdd, 0xaa, 0x81, 0x0, 0xdd, 0xaa},
			   (int8x8_t) {0x80, 0x1, 0xcc, 0xaa, 0x80, 0x1, 0xcc, 0xaa});

  if (a != 0x4444448044444480)
    abort ();
  else if (v_sa[0] != 1
	   || v_sa[1] != (signed char) 0xff
	   || v_sa[2] != 0x11
	   || v_sa[3] != 0
	   || v_sa[4] != 1
	   || v_sa[5] != (signed char) 0xff
	   || v_sa[6] != 0x11
	   || v_sa[7] != 0)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
