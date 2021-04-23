/* This is a test program for ukadd64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <p_ext_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
unsigned long long ukadd64 (unsigned long long ra, unsigned long long rb)
{
  return __rv__ukadd64 (ra, rb);
}

int
main ()
{
  unsigned long long sa = ukadd64 (0x1122334400000000ll, 0x55667788ll);

  if (sa != 0x1122334455667788ll)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
