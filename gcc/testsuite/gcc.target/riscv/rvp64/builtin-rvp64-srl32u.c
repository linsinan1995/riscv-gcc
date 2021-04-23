/* This is a test program for srl32u instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t srl32u (uint32_t ra, uint32_t rb)
{
  return __rv__srl32_u (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_srl32u (uint32x2_t ra, uint32_t rb)
{
  return __rv__v_srl32_u (ra, rb);
}

int
main ()
{
  uint32_t a = srl32u (0x0ffff0000ffff000, 4);
  uint32x2_t va = v_srl32u ((uint32x2_t) {0x7fff8000, 0x7fff8000}, 4);

  if (a != 0xffff0000ffff00)
    abort ();
  else if (va[0] != 0x07fff800
	   || va[1] != 0x7fff800)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
