#include "arithmetic.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (is_zero(value_2)) {
    // Деление на 0
    return 3;
  }

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

  s21_big_decimal ten;
  create_zero_big_decimal(&ten);
  ten.bits[0] = 10;

  s21_big_decimal max_div_ten = {{4294967295, 4294967295, 4294967295,
                                  4294967295, 4294967295, 4294967295 / 100, 0}};

  int pow_3 = 0;
  while (s21_is_greater_or_equal_big(max_div_ten, num_1)) {
    s21_mul_ten_big(&num_1);
    pow_3++;
  }

  s21_div_big(num_1, num_2, &ans);

  s21_set_sign_big_decimal(&ans, sign_1 ^ sign_2);
  flag_error =
      s21_from_big_decimal_to_decimal(ans, result, pow_1 - pow_2 + pow_3);
  return flag_error;
}

void s21_div_big(s21_big_decimal num_1, s21_big_decimal num_2,
                 s21_big_decimal *result) {
  create_zero_big_decimal(result);
  // Увеличить максимально число(умножая на 10), чтобы не потерять знач. числа
  // Но пока не реализовано
  s21_set_sign_big_decimal(&num_1, 0);
  s21_set_sign_big_decimal(&num_2, 0);

  // целое
  s21_big_decimal whole;
  s21_mod_big(num_1, num_2, &whole);
  // остаток
  s21_big_decimal remainder;
  s21_remainder_big(num_1, num_2, &remainder);
  // округление остатка
  s21_big_decimal round;
  round_bank_big(remainder, num_2, &round);

  s21_add_big(whole, round, result);
}
