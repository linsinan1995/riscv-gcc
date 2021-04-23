/* This is a test program for uclip16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t uclip16 (signed int32_t ra)
{
  return __rv__uclip16 (ra, 2);
}

static __attribute__ ((noinline))
int16x4_t v_uclip16 (int16x4_t ra)
{
  return __rv__v_uclip16 (ra, 4);
}

int
main ()
{
  int16x4_t v_sa_p = {0, 0, 15, 3};
  uint32_t a = uclip16 (0x1010101010101010);
  int16x4_t v_sa = v_uclip16 ((int16x4_t) {0, -20, 20, 3});

  if (a != 0x3000300030003)
    abort ();
  else if (!vec64_all_eq (s, 16, v_sa_p, v_sa))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
