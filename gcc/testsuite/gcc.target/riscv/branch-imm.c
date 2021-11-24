/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zcea -mzce-beqi -mzce-bnei -mabi=lp64d" } */

int foo (int a, int b)
{
  if (a != 1)
    return 4;
  if (b == 3)
    return 5;
  return 1;
}

/* { dg-final { scan-assembler "beqi\t" } } */
/* { dg-final { scan-assembler "bnei\t" } } */
