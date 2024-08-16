#ifndef S21_COMPARISON
#define S21_COMPARISON

#include "../s21_decimal.h"

int s21_is_less_big(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_less_or_equal_big(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_greater_big(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_greater_or_equal_big(s21_big_decimal num_1, s21_big_decimal num_2);
int s21_is_equal_big(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_not_equal_big(s21_big_decimal value_1, s21_big_decimal value_2);

#endif