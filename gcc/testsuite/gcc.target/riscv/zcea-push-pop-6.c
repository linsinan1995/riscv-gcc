/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zcea -mabi=ilp32d -mzce-push-pop" } */

#include <stdio.h>

/* Test pop instruction. */
void __attribute__ ((interrupt ("user")))
foo (void)
{
  printf("%u", 1);
}

/* { dg-final { scan-assembler "pop\t{ra,s0-s11},*" } } */
