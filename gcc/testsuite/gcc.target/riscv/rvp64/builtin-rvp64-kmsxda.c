/* This is a test program for kmsxda instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t kmsxda (uint32_t rd, uint32_t ra, uint32_t rb)
{
  return __rv__kmsxda (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kmsxda (int32x2_t rd, int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kmsxda (rd, ra, rb);
}

int
main ()
{
  int32_t va_p = 0x600000006;
  int32_t a = kmsxda (0x300000003, 0x8000000280000002, 0x8000000180000001);
  int32x2_t va = v_kmsxda ((int32x2_t) {0x3, 0x3},
			   (int16x4_t) {0xffff, 0x0002, 0xffff, 0x0002},
			   (int16x4_t) {0xffff, 0x0001, 0xffff, 0x0001});

  if (a != 0x1800300018003)
    abort ();
  else if (va[0] != 6
	   || va[1] != 6)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
