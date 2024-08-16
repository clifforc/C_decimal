#include "binary_operations.h"

int s21_shift_big_decimal_right(s21_big_decimal *num, int shift_value) {
  int flag = 0;
  for (int i = 0; i < shift_value && !flag; i++) {
    flag = s21_shift_big_decimal_right_one(num);
  }

  return flag;
}

int s21_shift_big_decimal_right_one(s21_big_decimal *num) {
  int flag = 0;
  unsigned int transfer = 0;
  for (int i = S21_BIG_DECIMAL_NUMBER_CELLS - 1; i >= 0; i--) {
    unsigned int temp = num->bits[i];
    num->bits[i] >>= 1;
    s21_set_bit_big_decimal(
        num, i * (S21_DECIMAL_NUMBER_BITS) + (S21_DECIMAL_NUMBER_BITS - 1),
        transfer);
    transfer = s21_get_bit(temp, 0);
  }

  if (transfer != 0) {
    flag = 1;
  }

  return flag;
}