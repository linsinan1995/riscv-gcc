/* This is a test program for kmda instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t kmda (uint32_t ra, uint32_t rb)
{
  return __rv__kmda (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kmda (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kmda (ra, rb);
}

int
main ()
{
  int32_t va_p = 0x300000003;
  int32_t a = kmda (0x8000000280000002, 0x8000000180000001);
  int32x2_t va = v_kmda ((int16x4_t) {0xffff, 0x0002, 0xffff, 0x0002},
			 (int16x4_t) {0xffff, 0x0001, 0xffff, 0x0001});

  if (a != 0x4000000240000002)
    abort ();
  else if (va[0] != 0x3
	   || va[1] != 0x3)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
