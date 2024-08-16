#include "help_functions.h"

void normalization(s21_big_decimal *num_1, s21_big_decimal *num_2) {
  int scale1 = s21_get_sign_big_decimal(*num_1);
  int scale2 = s21_get_sign_big_decimal(*num_2);

  int pow1 = s21_get_scale_big(*num_1);
  int pow2 = s21_get_scale_big(*num_2);

  s21_big_decimal ten_pow;

  int k = pow1 - pow2;
  if (k < 0) {
    s21_pow_ten_big(-k, &ten_pow);
    s21_mul_big(*num_1, ten_pow, num_1);
    s21_set_scale_big(num_1, pow1 - k);

  } else if (k > 0) {
    s21_pow_ten_big(k, &ten_pow);
    s21_mul_big(*num_2, ten_pow, num_2);
    s21_set_scale_big(num_2, pow1 - k);
  }
  s21_set_sign_big_decimal(num_1, scale1);
  s21_set_sign_big_decimal(num_2, scale2);
}