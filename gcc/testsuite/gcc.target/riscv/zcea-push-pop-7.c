/* This testcase is to test whether push/pop can correctly split stack adjustment offset. */
/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zcea -mabi=ilp32d -mzce-push-pop" } */

void test (char *);

int foo()
{
  char m[512] = {0};
  test (m);
}

/* { dg-final { scan-assembler "push\t{ra,s0},-512" } } */
/* { dg-final { scan-assembler "addi\tsp,sp,-16" } } */
/* { dg-final { scan-assembler "addi\tsp,sp,16" } } */
/* { dg-final { scan-assembler "popret\t{ra,s0},512" } } */
