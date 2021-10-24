/* sub64 also appears on filename, so scan-assembler-times plus 1 */
/* sub64 will generate 'add' in rv64p */
/* This is a test program for sub64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t buss (int64_t ra, int64_t rb)
{
  return __rv_ssub64 (ra, rb);
}

static __attribute__ ((noinline))
uint64_t busu (uint64_t ra, uint64_t rb)
{
  return __rv_usub64 (ra, rb);
}
/* { dg-final { scan-assembler-times "sub64" 1 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
