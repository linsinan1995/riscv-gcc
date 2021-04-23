/* This is a test program for add8 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t kadd8 (uint32_t ra, uint32_t rb)
{
  return __rv__kadd8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t v_kadd8 (int8x8_t ra, int8x8_t rb)
{
  return __rv__v_kadd8 (ra, rb);
}

int
main ()
{
  uint32_t a = kadd8 (0x1122334411223344, 0x5566778855667788);
  int8x8_t v_sa = v_kadd8 ((int8x8_t) {0x80, 0x7f, 0xbb, 0xaa, 0x80, 0x7f, 0xbb, 0xaa},
			   (int8x8_t) {0x80, 0x7f, 0xbb, 0xaa, 0x80, 0x7f, 0xbb, 0xaa});

  if (a != 0x667f7fcc667f7fcc)
    abort ();
  else if (v_sa[0] != (signed char) 0x80
	   || v_sa[1] != 0x7f
	   || v_sa[2] != (signed char) 0x80
	   || v_sa[3] != (signed char) 0x80
	   || v_sa[4] != (signed char) 0x80
	   || v_sa[5] != 0x7f
	   || v_sa[6] != (signed char) 0x80
	   || v_sa[7] != (signed char) 0x80)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
