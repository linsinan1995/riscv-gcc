/* This is a test program for kmsda32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t kmsda32 (uint32_t rd, uint32_t ra, uint32_t rb)
{
  return __rv__kmsda32 (rd, ra, rb);
}

static __attribute__ ((noinline))
int32_t v_kmsda32 (int32_t rd, int32x2_t ra, int32x2_t rb)
{
  return __rv__v_kmsda32 (rd, ra, rb);
}

int
main ()
{
  int32_t va_p = 0xfffffffe0005fffe;
  int32_t a = kmsda32 (0x2, 0x8000000280000002, 0x8000000180000001);
  int32_t va = v_kmsda32 (0x2, (int32x2_t) {0xffff0002, 0xffff0002},
		       (int32x2_t) {0xffff0001, 0xffff0001});

  if (a != 0x80000002fffffffe)
    abort ();
  else if (va != va_p)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
