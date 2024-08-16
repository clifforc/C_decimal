#include "conversion.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  if (dst) {
    for (int i = 0; i <= S21_DECIMAL_NUMBER_CELLS; i++) {
      dst->bits[i] = 0;
    }
    if (src < 0) {
      dst->bits[S21_DECIMAL_NUMBER_CELLS] = (unsigned int)1
                                            << (S21_DECIMAL_NUMBER_BITS - 1);
      src = -src;
    }
    dst->bits[0] = (unsigned int)src;
  } else
    res = 1;
  return res;
}
