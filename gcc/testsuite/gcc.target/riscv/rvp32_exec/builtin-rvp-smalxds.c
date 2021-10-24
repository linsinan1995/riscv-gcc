/* This is a test program for smalxds instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t smalxds (int64_t t, uint32_t a, uint32_t b)
{
  return __rv_smalxds (t, a, b);
}

static __attribute__ ((noinline))
int64_t v_smalxds (int64_t t, int16x2_t a, int16x2_t b)
{
  return __rv_v_smalxds (t, a, b);
}


int
main ()
{
  int64_t a_p = 0x12345678ffffaaaall;
  int64_t va_p = 0x12345678ffffaaaall;
  int64_t a = smalxds (0x12345678ffffffffll, 0x12340001, 0x67890001);
  int64_t va = v_smalxds (0x12345678ffffffffll, (int16x2_t) {0x0001, 0x1234},
						  (int16x2_t) {0x0001, 0x6789});

  if (a != a_p)
    abort ();
  else if (va != va_p)
    abort ();
  else
    exit (0);
}
