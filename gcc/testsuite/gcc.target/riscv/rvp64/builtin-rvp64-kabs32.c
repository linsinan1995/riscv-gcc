/* This is a test program for kabs32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t kabs32 (uint32_t ra)
{
  return __rv__kabs32 (ra);
}

static __attribute__ ((noinline))
int32x2_t v_kabs32 (int32x2_t ra)
{
  return __rv__v_kabs32 (ra);
}

int
main ()
{
  int32x2_t va_p = {0x7fffc000, 0x7fffc000};
  uint32_t a = kabs32 (0x7fff7fff7fff7fff);
  int32x2_t va = v_kabs32 ((int32x2_t) {0x80004000, 0x80004000});

  if (a != 0x7fff7fff7fff7fff)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
