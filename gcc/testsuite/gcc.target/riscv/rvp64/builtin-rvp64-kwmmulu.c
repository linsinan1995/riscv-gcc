/* This is a test program for kwmmulu instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t kwmmulu (int32_t ra, int32_t rb)
{
  return __rv__kwmmul_u (ra, rb);
}

int
main ()
{
  int32_t a = kwmmulu (0x8000000080000000, 0x8000000080000000);

  if (a != 0x7fffffff7fffffff)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
