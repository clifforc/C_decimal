#include "other.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag_error = 0;
  int sign = s21_get_sign_decimal(value);
  int pow = s21_get_scale(value);

  s21_big_decimal num;
  s21_from_decimal_to_big_decimal(value, &num);
  s21_set_sign_big_decimal(&num, 0);

  s21_big_decimal ten_pow;
  s21_pow_ten_big(pow, &ten_pow);

  s21_div_big(num, ten_pow, &num);
  copy_big_decimal_1_cells_to_decimal(num, result);
  s21_set_sign_decimal(result, sign);

  if (!is_zero_big_2_cells(num)) {
    flag_error = 1;
  }

  return flag_error;
}