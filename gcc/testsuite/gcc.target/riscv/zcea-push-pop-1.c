/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zcea -mabi=lp64d -mzce-push-pop" } */

int foo1(int a)
{
    return a;
}

int foo2(int b)
{
    return foo1(b);
}

/* { dg-final { scan-assembler "push\t{ra,s0},{},-*" } } */
/* { dg-final { scan-assembler "popret\t{ra,s0},{},*" } } */
