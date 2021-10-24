/* bpick also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for bpick instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t kcipb (uint64_t ra, uint64_t rb, uint64_t rc)
{
  return __rv_bpick (ra, rb, rc);
}
/* { dg-final { scan-assembler-times "bpick" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
