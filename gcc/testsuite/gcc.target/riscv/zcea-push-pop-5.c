/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zcea -mabi=ilp32d -mzce-push-pop -O1" } */

int foo2 (int, int);

/* Test reglist of push and pop. */
int foo1(int n, int k)
{
  int mat[n + 1][k + 1];
  mat[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= foo2(i, k); j++)
      mat[i][j] = j * mat[i - 1][j - 1];
  return mat[n][k];
}

/* { dg-final { scan-assembler "push\t{ra,s0-s11},-*" } } */
/* { dg-final { scan-assembler "popret\t{ra,s0-s11},*" } } */
