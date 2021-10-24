/* This is a test program for srli32u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int16x4_t v_kstas16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_kstas16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_ukstas16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_ukstas16 (ra, rb);
}

int main()
{
  uint16x4_t va = { 0x2, 0xfffe, 0x2, 0xffff }, vb = { 0x2, 0x1, 0x1, 0x1 }, gt_vr = { 0x0, 0xffff, 0x1, 0x0 };
  int16x4_t vsa = { 0x2, 0xfffe, 0x2, 0xfffe }, vsb = { 0x2, 0x1, 0x2, 0x1 }, gt_vsr = { 0, -1, 0, -1 };
  uint64_t a = 0xffff0002fffe0002, b = 0x1000100010002, gt_r = 0x1ffff0000;
  int16x4_t k_r = v_kstas16 ((int16x4_t) {0x7777, 0xf111, 0x7777, 0xf111}, (int16x4_t) {0x1000, 0x0eef, 0x1000, 0x2000});
  uint16x4_t uk_r = v_ukstas16 ((uint16x4_t) {0x7777, 0xf111, 0x7777, 0xf111}, (uint16x4_t) {0x1000, 0x0eef, 0x1000, 0x2000});
  int i = 0;
  for (i = 0; i < 4; i++)
  fprintf(stderr, "%lu ", uk_r[i]);
  printf("\n");
  for (i = 0; i < 4; i++)
  fprintf(stderr, "%d ", k_r[i]);
  printf("\n%lu\n", __rv_ukstas16 (0x0001f0000001f000, 0x7fff100000011000));
  /* stas16 */
  if (!vec_all_eq_uint16x4_t (__rv_v_ustas16 (va, vb), gt_vr))
    abort();
  else if (!vec_all_eq_int16x4_t (__rv_v_sstas16 (vsa, vsb), gt_vsr))
    abort();
  else if (__rv_stas16 (a, b) != gt_r)
    abort();
  /* kstas16 */
  else if (k_r[0] != 0x6777
	   || k_r[1] != 0x1111
	   || k_r[2] != 0x6777
	   || k_r[3] != 0x1111)
    abort();
  else if (__rv_kstas16 (0x0001f0000001f000, 0x7fff100000011000) != 0x7fffe0000002e000llu)
    abort();
  /* ukstas16 */
  else if (uk_r[0] != 0x6777
	   || uk_r[1] != 0xffff
	   || uk_r[2] != 0x6777
	   || uk_r[3] != 0xffff)
    abort();
  else if (__rv_ukstas16 (0x0001f0000001f000, 0x7fff100000011000) != 0x8000e0000002e000llu)
    abort();
}