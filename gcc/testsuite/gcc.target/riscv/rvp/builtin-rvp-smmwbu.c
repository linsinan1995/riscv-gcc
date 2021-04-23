/* This is a test program for smmwb.u instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t smmwb_u (int32_t ra, uint32_t rb)
{
  return __rv__smmwb_u (ra, rb);
}

static __attribute__ ((noinline))
int32_t v_smmwb_u (int32_t ra, int16x2_t rb)
{
  return __rv__v_smmwb_u (ra, rb);
}

int
main ()
{
  int32_t va_p = 1;

  int32_t a = smmwb_u (0x80000002, 0x80000001);

  int32_t va = v_smmwb_u (0xffff0002, (int16x2_t) {0xffff, 0x0001});

  if (a != 0xffff8000)
    abort ();
  else if (va != va_p)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
