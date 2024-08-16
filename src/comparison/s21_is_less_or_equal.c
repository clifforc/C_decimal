#include "s21_comparison.h"

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int flag_error = 0;

  s21_big_decimal num_1;
  s21_big_decimal num_2;

  s21_from_decimal_to_big_decimal(value_1, &num_1);
  s21_from_decimal_to_big_decimal(value_2, &num_2);

  normalization(&num_1, &num_2);

  flag_error = s21_is_less_or_equal_big(num_1, num_2);

  return flag_error;
}