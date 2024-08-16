#include "arithmetic.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (s21_get_sign_decimal(value_2) == 0) {
    s21_set_sign_decimal(&value_2, 1);
  } else {
    s21_set_sign_decimal(&value_2, 0);
  }

  return s21_add(value_1, value_2, result);
}

int s21_sub_big(s21_big_decimal num_1, s21_big_decimal num_2,
                s21_big_decimal *result) {
  if (s21_get_sign_big_decimal(num_2) == 0) {
    s21_set_sign_big_decimal(&num_2, 1);
  } else {
    s21_set_sign_big_decimal(&num_2, 0);
  }

  return s21_add_big(num_1, num_2, result);
}