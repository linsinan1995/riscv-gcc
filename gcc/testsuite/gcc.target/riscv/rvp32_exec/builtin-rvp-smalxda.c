/* This is a test program for smalxda instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t smalxda (int64_t t, uint32_t a, uint32_t b)
{
  return __rv_smalxda (t, a, b);
}

static __attribute__ ((noinline))
int64_t v_smalxda (int64_t t, int16x2_t a, int16x2_t b)
{
  return __rv_v_smalxda (t, a, b);
}


int
main ()
{
  int64_t a = smalxda (0x12345678ffffffffll, 0x67890000, 0x00001234);
  int64_t va = v_smalxda (0x12345678ffffffffll, (int16x2_t) {0, 0x6789},
						  (int16x2_t) {0x1234, 0});

  if (a != 0x12345679075CA9D3)
    abort ();
  else if (va != 0x12345679075CA9D3)
    abort ();
  else
    exit (0);
}
