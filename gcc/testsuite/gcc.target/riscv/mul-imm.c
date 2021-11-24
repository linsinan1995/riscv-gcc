/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zcea -mzce-muli -Os -mabi=lp64d" } */

long
foo (long a)
{
  return a * 3;
}

/* { dg-final { scan-assembler "muli\t" } } */
