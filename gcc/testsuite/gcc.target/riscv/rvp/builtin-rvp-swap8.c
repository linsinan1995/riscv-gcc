/* This is a test program for wsbh instruction.  */
/* { dg-do run } */
/* { dg-options "-O0" } */
/* { dg-require-effective-target riscv32 } */

#include <p_ext_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
int
main ()
{
  unsigned int a = 0x03020100;
  unsigned int b;

  b = __rv__swap8 (a);

  if (b != 0x02030001)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
