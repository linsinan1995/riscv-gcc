/* This is a test program for smtt32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t smtt32 (uint32_t ra, uint32_t rb)
{
  return __rv__smtt32 (ra, rb);
}

static __attribute__ ((noinline))
int32_t v_smtt32 (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_smtt32 (ra, rb);
}

int
main ()
{
  int32_t va_p = 0x00000000fffd0002;
  int32_t a = smtt32 (0x8000000280000002, 0x8000000180000001);
  int32_t va = v_smtt32 ((int32x2_t) {0xffff0002, 0xffff0002},
		      (int32x2_t) {0xffff0001, 0xffff0001});

  if (a != 0x3ffffffe80000002)
    abort ();
  else if (va != va_p)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
