/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zcea -mabi=ilp32d -mzce-push-pop -O1" } */

void foo2 (int a, int b, int c, int d, int e);

int foo1(int a, int b, int c, int d, int e)
{
    if (b < a)
    {
        foo2(a, b, c, d, e);
        foo1(a, b, c, d, e);
    }
    return -1;
}

/* { dg-final { scan-assembler "push\t{ra,s0-s4},{a0-a3},-*" } } */
/* { dg-final { scan-assembler "popret\t{ra,s0-s4},{-1},*" } } */
