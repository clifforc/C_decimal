#include "conversion.h"

int s21_from_decimal_to_big_decimal(s21_decimal src, s21_big_decimal *dst) {
  create_zero_big_decimal(dst);
  for (int i = 0; i < S21_DECIMAL_NUMBER_CELLS; i++) {
    dst->bits[i] = src.bits[i];
  }
  dst->bits[S21_BIG_DECIMAL_NUMBER_CELLS] = src.bits[S21_DECIMAL_NUMBER_CELLS];
  return 0;
}