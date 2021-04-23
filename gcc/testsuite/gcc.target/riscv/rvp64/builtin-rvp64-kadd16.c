/* This is a test program for add16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t kadd16 (uint32_t ra, uint32_t rb)
{
  return __rv__kadd16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_kadd16 (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kadd16 (ra, rb);
}

int
main ()
{
  uint32_t a = kadd16 (0x0001f0000001f000, 0x0001100000011000);
  int16x4_t v_sa = v_kadd16 ((int16x4_t) {0xf777, 0xf111, 0xf777, 0xf111},
			     (int16x4_t) {0x1000, 0x2000, 0x1000, 0x2000});

  if (a != 0x0002000000020000)
    abort ();
  else if (v_sa[0] != 0x0777
	   || v_sa[1] != 0x1111
	   || v_sa[2] != 0x0777
	   || v_sa[3] != 0x1111)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
