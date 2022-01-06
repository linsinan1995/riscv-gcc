/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zcea -mabi=ilp32d -mzce-push-pop" } */

#include <stdio.h>

void __attribute__ ((interrupt ("user")))
foo (void)
{
  char buf[560] = {0};
  printf("%d", buf[1]);
}

/* { dg-final { scan-assembler "pop\t{ra,s0},*" } } */
