/* This is a test program for khmx16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t khmx16 (uint32_t ra, uint32_t rb)
{
  return __rv__khmx16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_khmx16 (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_khmx16 (ra, rb);
}

int
main ()
{
  int16x4_t v_sa_p = {0x7fff, 0xc000, 0x7fff, 0xc000};
  uint32_t a = khmx16 (0x7fff7fff7fff7fff, 0x7fff7fff7fff7fff);
  int16x4_t va = v_khmx16 ((int16x4_t) {0x8000, 0x4000, 0x8000, 0x4000},
			   (int16x4_t) {0x8000, 0x8000, 0x8000, 0x8000});

  if (a != 0x7ffe7ffe7ffe7ffe)
    abort ();
  else if (!vec64_all_eq (s, 16, v_sa_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
