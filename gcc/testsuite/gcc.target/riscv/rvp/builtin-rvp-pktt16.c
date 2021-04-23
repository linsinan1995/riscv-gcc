/* This is a test program for pktt16 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t pktt16 (uint32_t ra, uint32_t rb)
{
  return __rv__pktt16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_pktt16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_pktt16 (ra, rb);
}

int
main ()
{
  uint16x2_t va_p = {0xdddd, 0xbbbb};
  uint32_t a = pktt16 (0x11223344, 0x55667788);
  uint16x2_t va = v_pktt16 ((uint16x2_t) {0xaaaa, 0xbbbb},
			    (uint16x2_t) {0xcccc, 0xdddd});

  if (a != 0x11225566)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
