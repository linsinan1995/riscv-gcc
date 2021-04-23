/* This is a test program for kmmacu instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t kmmacu (int32_t rd, int32_t ra, int32_t rb)
{
  return __rv__kmmac_u (rd, ra, rb);
}

int
main ()
{
  int32_t a = kmmacu (0, 0x8000000080000000, 0x8000000080000000);

  if (a != 0x4000000040000000)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
