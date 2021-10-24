#include <rvp_intrinsic.h>
#include <stdio.h>

#define vec_all_eq_(type, n) \
unsigned vec_all_eq_ ## type (type vec1, type vec2) {  \
  unsigned i, ret = 1, size = n;                            \
  for (i = 0; i < size; i++) {          \
    ret &= (vec1[i] == vec2[i]);                    \
  }                                                     \
  return ret;                                           \
}

vec_all_eq_ (int8x4_t, 4)
vec_all_eq_ (int8x8_t, 8)
vec_all_eq_ (int16x2_t, 2)
vec_all_eq_ (int16x4_t, 4)
vec_all_eq_ (int32x2_t, 2)
vec_all_eq_ (uint8x4_t, 4)
vec_all_eq_ (uint8x8_t, 8)
vec_all_eq_ (uint16x2_t, 2)
vec_all_eq_ (uint16x4_t, 4)
vec_all_eq_ (uint32x2_t, 2)