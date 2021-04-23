/* This is a test program for add8 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t add8 (uint32_t ra, uint32_t rb)
{
  return __rv__add8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t v_uadd8 (uint8x8_t ra, uint8x8_t rb)
{
  return __rv__v_uadd8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t v_sadd8 (int8x8_t ra, int8x8_t rb)
{
  return __rv__v_sadd8 (ra, rb);
}

int
main ()
{
  uint32_t a = add8 (0x1122334411223344, 0x5566778855667788);
  uint8x8_t v_ua = v_uadd8 ((uint8x8_t) {0xff, 0xee, 0xdd, 0xcc, 0xff, 0xee, 0xdd, 0xcc},
			    (uint8x8_t) {0x1, 0xee, 0xdd, 0xcc, 0x1, 0xee, 0xdd, 0xcc});
  int8x8_t v_sa = v_sadd8 ((int8x8_t) {0x80, 0x7f, 0xbb, 0xaa, 0x80, 0x7f, 0xbb, 0xaa},
			   (int8x8_t) {0x80, 0x7f, 0xbb, 0xaa, 0x80, 0x7f, 0xbb, 0xaa});

  if (a != 0x6688aacc6688aaccll)
    abort ();
  else if (v_ua[0] != 0
	   || v_ua[1] != 0xdc
	   || v_ua[2] != 0xba
	   || v_ua[3] != 0x98
	   || v_ua[4] != 0
	   || v_ua[5] != 0xdc
	   || v_ua[6] != 0xba
	   || v_ua[7] != 0x98)
    abort ();
  else if (v_sa[0] != 0
	   || v_sa[1] != (signed char) 0xfe
	   || v_sa[2] != 0x76
	   || v_sa[3] != 0x54
	   || v_sa[4] != 0
	   || v_sa[5] != (signed char) 0xfe
	   || v_sa[6] != 0x76
	   || v_sa[7] != 0x54)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
