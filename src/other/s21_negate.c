#include "other.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  s21_set_sign_decimal(result, !s21_get_sign_decimal(value));

  return 0;
}