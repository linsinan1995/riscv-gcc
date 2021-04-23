/* This is a test program for srl16 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t srl16 (uint32_t ra, uint32_t rb)
{
  return __rv__srl16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_srl16 (uint16x2_t ra, uint32_t rb)
{
  return __rv__v_srl16 (ra, rb);
}

int
main ()
{
  uint32_t a = srl16 (0x0f00f000, 4);
  uint16x2_t va = v_srl16 ((uint16x2_t) {0x7fff, 0x8000}, 4);

  if (a != 0xf00f00)
    abort ();
  else if (va[0] != 0x7ff
	   || va[1] != 0x0800)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
