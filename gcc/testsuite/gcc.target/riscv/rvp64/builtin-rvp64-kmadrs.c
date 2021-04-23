/* This is a test program for kmadrs instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t kmadrs (uint32_t rd, uint32_t ra, uint32_t rb)
{
  return __rv__kmadrs (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kmadrs (int32x2_t rd, int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kmadrs (rd, ra, rb);
}

int
main ()
{
  int32_t a = kmadrs (0x300000003, 0x8000000280000002, 0x8000000180000001);
  int32x2_t va = v_kmadrs ((int32x2_t) {0x3, 0x3},
			   (int16x4_t) {0xffff, 0x0002, 0xffff, 0x0002},
			   (int16x4_t) {0xffff, 0x0001, 0xffff, 0x0001});

  if (a != 0xc0000005c0000005)
    abort ();
  else if (va[0] != 2
	   || va[1] != 2)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
