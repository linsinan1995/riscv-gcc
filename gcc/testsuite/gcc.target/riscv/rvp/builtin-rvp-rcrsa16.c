/* This is a test program for rcrsa16 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t rcrsa16 (uint32_t ra, uint32_t rb)
{
  return __rv__rcrsa16 (ra, rb);
}

static __attribute__ ((noinline))
int16x2_t v_rcrsa16 (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_rcrsa16 (ra, rb);
}

int
main ()
{
  int16x2_t va_p = {0x8000, 0x8000};
  uint32_t a = rcrsa16 (0x7fff7fff, 0x7fff8000);
  int16x2_t va = v_rcrsa16 ((int16x2_t) {0x8000, 0x8000},
			    (int16x2_t) {0x7fff, 0x8000});

  if (a != 0x7fff7fff)
    abort ();
  else if (va[0] != va_p [0]
	   || va[1] != va_p [1])
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
