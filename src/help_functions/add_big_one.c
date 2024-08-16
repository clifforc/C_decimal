#include "help_functions.h"

void add_big_one(s21_big_decimal *num) {
  s21_big_decimal one;
  create_one_big_decimal(&one);
  s21_add_big(*num, one, num);
}

void sub_big_one(s21_big_decimal *num) {
  s21_big_decimal one;
  create_one_big_decimal(&one);
  s21_sub_big(*num, one, num);
}