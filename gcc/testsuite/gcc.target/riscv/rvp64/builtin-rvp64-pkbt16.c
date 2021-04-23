/* This is a test program for pkbt16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t pkbt16 (uint32_t ra, uint32_t rb)
{
  return __rv__pkbt16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_pkbt16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv__v_pkbt16 (ra, rb);
}

int
main ()
{
  uint16x4_t va_p = {0xdddd, 0xaaaa, 0xdddd, 0xaaaa};
  uint32_t a = pkbt16 (0x1122334411223344, 0x5566778855667788);
  uint16x4_t va = v_pkbt16 ((uint16x4_t) {0xaaaa, 0xbbbb, 0xaaaa, 0xbbbb},
			    (uint16x4_t) {0xcccc, 0xdddd, 0xcccc, 0xdddd});

  if (a != 0x3344556633445566)
    abort ();
  else if (!vec64_all_eq (u, 16, va_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
