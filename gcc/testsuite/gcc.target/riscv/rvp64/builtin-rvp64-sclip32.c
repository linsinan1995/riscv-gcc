/* This is a test program for add8 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
signed int32_t sclip32 (signed int32_t ra)
{
  return __rv__sclip32 (ra, 5);
}

int
main ()
{
  signed int32_t a = sclip32 (0x0000000100000100);

  if (a != 0x10000001f)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
