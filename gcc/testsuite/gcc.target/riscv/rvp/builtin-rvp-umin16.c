/* This is a test program for umin16 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t umin16 (uint32_t ra, uint32_t rb)
{
  return __rv__umin16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_umin16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_umin16 (ra, rb);
}

int
main ()
{
  uint32_t a = umin16 (0xfffe0001, 0xffff0000);
  uint16x2_t va = v_umin16 ((uint16x2_t) {0x7fff, 0},
			    (uint16x2_t) {0x7ffe, 1});
  if (a != 0xfffe0000)
    abort ();
  else if (va[0] != 0x7ffe
           || va[1] != 0)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
