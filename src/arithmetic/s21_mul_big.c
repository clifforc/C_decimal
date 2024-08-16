#include "arithmetic.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag_error = 0;

  unsigned int sign_1 = s21_get_sign_decimal(value_1);
  unsigned int sign_2 = s21_get_sign_decimal(value_2);

  int pow_1 = s21_get_scale(value_1);
  int pow_2 = s21_get_scale(value_2);

  s21_big_decimal num_1;
  s21_big_decimal num_2;
  s21_big_decimal ans;

  s21_from_decimal_to_big_decimal(value_1, &num_1);
  s21_from_decimal_to_big_decimal(value_2, &num_2);

  s21_mul_big(num_1, num_2, &ans);

  // Устанавливаем знак и степень
  s21_set_sign_big_decimal(&ans, sign_1 ^ sign_2);
  flag_error = s21_from_big_decimal_to_decimal(ans, result, pow_1 + pow_2);

  return flag_error;
}

void s21_mul_big(s21_big_decimal num_1, s21_big_decimal num_2,
                 s21_big_decimal *result) {
  create_zero_big_decimal(result);
  for (int i = (S21_BIG_DECIMAL_NUMBER_CELLS)*S21_DECIMAL_NUMBER_BITS - 1;
       i >= 0; i--) {
    if (s21_get_bit_big_decimal(num_1, i) == 1) {
      s21_add_big(*result, num_2, result);
    }
    if (i != 0) s21_shift_big_decimal_left_one(result);
  }
}