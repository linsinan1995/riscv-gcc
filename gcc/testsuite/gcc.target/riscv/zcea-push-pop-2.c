/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zcea -mabi=ilp32d -mzce-push-pop -O1" } */

void foo2 (int a, int b);

int foo1(int a, int b)
{ 
    if (b < a)
    {
        foo2(a, b);
        foo1(a, b);
    }
    return 1;
}

/* { dg-final { scan-assembler "push\t{ra,s0-s1},{a0-a1},-*" } } */
/* { dg-final { scan-assembler "popret\t{ra,s0-s1},{1},*" } } */
