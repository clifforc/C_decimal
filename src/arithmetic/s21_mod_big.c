#include "arithmetic.h"

void s21_remainder_big(s21_big_decimal num_1, s21_big_decimal num_2,
                       s21_big_decimal *ans) {
  create_zero_big_decimal(ans);
  s21_big_decimal one;
  create_one_big_decimal(&one);

  int k = 0;
  while (s21_get_bit_big_decimal(
             num_2,
             (S21_BIG_DECIMAL_NUMBER_CELLS)*S21_DECIMAL_NUMBER_BITS - 1) != 1) {
    k++;
    s21_shift_big_decimal_left_one(&num_2);
  }
  while (k >= 0) {
    s21_shift_big_decimal_left_one(ans);

    if (s21_is_greater_or_equal_big(num_1, num_2)) {
      s21_sub_big(num_1, num_2, &num_1);
      add_big_one(ans);
    }
    if (k != 0) {
      s21_shift_big_decimal_right_one(&num_2);
    }

    k--;
  }
  s21_copy_big_decimal(num_1, ans);
}

void s21_mod_big(s21_big_decimal num_1, s21_big_decimal num_2,
                 s21_big_decimal *ans) {
  create_zero_big_decimal(ans);
  s21_big_decimal one;
  create_one_big_decimal(&one);
  int k = 0;
  while (s21_get_bit_big_decimal(
             num_2,
             (S21_BIG_DECIMAL_NUMBER_CELLS)*S21_DECIMAL_NUMBER_BITS - 1) != 1) {
    k++;
    s21_shift_big_decimal_left_one(&num_2);
  }

  while (k >= 0) {
    s21_shift_big_decimal_left_one(ans);
    if (s21_is_greater_or_equal_big(num_1, num_2)) {
      s21_sub_big(num_1, num_2, &num_1);
      add_big_one(ans);
    }
    if (k != 0) {
      s21_shift_big_decimal_right_one(&num_2);
    }

    k--;
  }
}