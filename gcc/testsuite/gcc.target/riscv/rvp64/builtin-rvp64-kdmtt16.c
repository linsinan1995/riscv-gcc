/* This is a test program for kdmtt16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t kdmtt16 (uint32_t ra, uint32_t rb)
{
  return __rv__kdmtt16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kdmtt16 (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kdmtt16 (ra, rb);
}

int
main ()
{
  int32_t a = kdmtt16 (0x0001f0000001f000, 0x0001100000011000);
  int32x2_t va = v_kdmtt16 ((int16x4_t) {0xf777, 0xf111, 0xf777, 0xf111},
			    (int16x4_t) {0x1000, 0x2000, 0x1000, 0x2000});
  if (a != 0x0000000200000002)
    abort ();
  else if (va[0] != 0xfc444000
	   || va[1] != 0xfc444000)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
