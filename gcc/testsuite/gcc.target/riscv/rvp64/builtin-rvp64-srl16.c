/* This is a test program for srl16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

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
uint16x4_t v_srl16 (uint16x4_t ra, uint32_t rb)
{
  return __rv__v_srl16 (ra, rb);
}

int
main ()
{
  uint16x4_t va_p = {0x7ff, 0x0800, 0x7ff, 0x0800};
  uint32_t a = srl16 (0x0f00f0000f00f000, 4);
  uint16x4_t va = v_srl16 ((uint16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000}, 4);

  if (a != 0x00f00f0000f00f00)
    abort ();
  else if (!vec64_all_eq (u, 16, va_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
