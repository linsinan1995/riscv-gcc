/* This is a test program for smbb instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t smbb (uint32_t ra, uint32_t rb)
{
  return __rv__smbb16 (ra, rb);
}

static __attribute__ ((noinline))
int v_smbb (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_smbb16 (ra, rb);
}

int
main ()
{
  int32_t va_p = 1;

  int32_t a = smbb (0x80000002, 0x80000001);

  int32_t va = v_smbb ((int16x2_t) {0xffff, 0x0002},
		   (int16x2_t) {0xffff, 0x0001});

  if (a != 2)
    abort ();
  else if (va != va_p)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
