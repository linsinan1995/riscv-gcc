/* This is a test program for sll32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t sll32 (uint32_t ra, uint32_t rb)
{
  return __rv__sll32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_sll32 (uint32x2_t ra, uint32_t rb)
{
  return __rv__v_sll32 (ra, rb);
}

int
main ()
{
  uint32_t a = sll32 (0x0ffff0000ffff000, 4);
  uint32x2_t va = v_sll32 ((uint32x2_t) {0x7fff8000, 0x7fff8000}, 4);

  if (a != 0xffff0000ffff0000)
    abort ();
  else if (va[0] != 0xfff80000
	   || va[1] != 0xfff80000)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
