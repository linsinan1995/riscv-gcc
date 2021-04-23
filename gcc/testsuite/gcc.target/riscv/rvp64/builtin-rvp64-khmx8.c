/* This is a test program for khmx8 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t khmx8 (uint32_t ra, uint32_t rb)
{
  return __rv__khmx8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t v_khmx8 (int8x8_t ra, int8x8_t rb)
{
  return __rv__v_khmx8 (ra, rb);
}

int
main ()
{
  int8x8_t v_sa_p = {0x0, 0xfb, 0x2, 0x0, 0x0, 0xfb, 0x2, 0x0};
  uint32_t a = khmx8 (0x7fff7fff7fff7fff, 0x7fff7fff7fff7fff);
  int8x8_t va = v_khmx8 ((int8x8_t) {0x80, 0x5, 0x40, 0x0, 0x80, 0x5, 0x40, 0x0},
			(int8x8_t) {0x80, 0x0, 0x80, 0x5, 0x80, 0x0, 0x80, 0x5});

  if (a != 0xffffffffffffffff)
    abort ();
  else if (!vec64_all_eq (s, 8, v_sa_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
