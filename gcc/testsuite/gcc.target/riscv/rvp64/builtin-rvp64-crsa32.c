/* This is a test program for crsa32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t crsa32 (uint32_t ra, uint32_t rb)
{
  return __rv__crsa32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_ucrsa32 (uint32x2_t ra, uint32x2_t rb)
{
  return __rv__v_ucrsa32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_scrsa32 (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_scrsa32 (ra, rb);
}

int
main ()
{
  uint32x2_t ua_p = {0x11000, 0xe000d000};
  int32x2_t sa_p = {0x7781111, 0xe777d111};
  uint32_t a = crsa32 (0x0001f0000001f000, 0x0001100000011000);
  uint32x2_t v_ua = v_ucrsa32 ((uint32x2_t) {0xf000f000, 0xf000f000},
			      (uint32x2_t) {0x10002000, 0x10002000});
  int32x2_t v_sa = v_scrsa32 ((int32x2_t) {0xf777f111, 0xf777f111},
			     (int32x2_t) {0x10002000, 0x10002000});

  if (a != 0x0000e00000030000)
    abort ();
  else if (ua_p[0] != v_ua[0]
	   || ua_p[1] != v_ua[1])
    abort ();
  else if (sa_p[0] != v_sa[0]
	   || sa_p[1] != v_sa[1])
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
