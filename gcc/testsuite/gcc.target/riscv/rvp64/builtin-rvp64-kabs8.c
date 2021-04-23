/* This is a test program for kabs8 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t kabs8 (uint32_t ra)
{
  return __rv__kabs8 (ra);
}

static __attribute__ ((noinline))
int8x8_t v_kabs8 (int8x8_t ra)
{
  return __rv__v_kabs8 (ra);
}

int
main ()
{
  int8x8_t v_sa_p = {0x7f, 0x0, 0x40, 0x0, 0x7f, 0x0, 0x40, 0x0};
  uint32_t a = kabs8 (0x7fff7fff7fff7fff);
  int8x8_t va = v_kabs8 ((int8x8_t) {0x80, 0x0, 0x40, 0x0, 0x80, 0x0, 0x40, 0x0});

  if (a != 0x7f017f017f017f01)
    abort ();
  else if (!vec64_all_eq (s, 8, v_sa_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
