/* This is a test program for smbt instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t smbt (uint32_t ra, uint32_t rb)
{
  return __rv__smbt16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_smbt (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_smbt16 (ra, rb);
}

int
main ()
{
  int32_t a = smbt (0x8000000280000002, 0x8000000180000001);
  int32x2_t va = v_smbt ((int16x4_t) {0xffff, 0x0002, 0xffff, 0x0002},
			 (int16x4_t) {0xffff, 0x0001, 0xffff, 0x0001});

  if (a != 0xffff0000ffff0000)
    abort ();
  else if (va[0] != 0xffffffff
	   || va[1] != 0xffffffff)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
