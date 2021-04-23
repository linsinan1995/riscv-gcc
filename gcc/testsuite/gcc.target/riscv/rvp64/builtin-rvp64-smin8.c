/* This is a test program for smin8 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t smin8 (uint32_t ra, uint32_t rb)
{
  return __rv__smin8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t v_smin8 (int8x8_t ra, int8x8_t rb)
{
  return __rv__v_smin8 (ra, rb);
}

int
main ()
{
  int8x8_t v_sa_p = {0x7f, 0xfe, 0, 0x15, 0x7f, 0xfe, 0, 0x15};
  uint32_t a = smin8 (0xfffe0001fffe0001, 0xffff0000ffff0000);
  int8x8_t v_sa = v_smin8 ((int8x8_t) {0x7f, 0xff, 0x0, 0x15, 0x7f, 0xff, 0x0, 0x15},
			   (int8x8_t) {0x7f, 0xfe, 0x1, 0x23, 0x7f, 0xfe, 0x1, 0x23});
  if (a != 0xfffe0000fffe0000)
    abort ();
  else if (!vec64_all_eq (s, 8, v_sa_p, v_sa))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
