/* This is a test program for cras16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t cras16 (uint32_t ra, uint32_t rb)
{
  return __rv__cras16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_ucras16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv__v_ucras16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_scras16 (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_scras16 (ra, rb);
}

int
main ()
{
  uint16x4_t v_ua_p = {1, 0, 1, 0};
  int16x4_t v_sa_p = {0x1000, 0x111, 0x1000, 0x111};
  uint32_t a = cras16 (0x0001f0000001f000, 0x0001f0000001f000);
  uint16x4_t v_ua = v_ucras16 ((uint16x4_t) {0x1235, 0xf000, 0x1235, 0xf000},
			       (uint16x4_t) {0x1000, 0x1234, 0x1000, 0x1234});
  int16x4_t v_sa = v_scras16 ((int16x4_t) {0x2000, 0xf111, 0x2000, 0xf111},
			      (int16x4_t) {0x1000, 0x1000, 0x1000, 0x1000});

  if (a != 0xf001effff001efff)
    abort ();
  else if (v_ua[0] != v_ua_p[0]
	   || v_ua[1] != v_ua_p[1]
	   || v_ua[2] != v_ua_p[2]
	   || v_ua[3] != v_ua_p[3])
    abort ();
  else if (v_sa[0] != v_sa_p[0]
	   || v_sa[1] != v_sa_p[1]
	   || v_sa[2] != v_sa_p[2]
	   || v_sa[3] != v_sa_p[3])
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
