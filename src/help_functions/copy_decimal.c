#include "help_functions.h"

void s21_copy_big_decimal(s21_big_decimal num_1, s21_big_decimal *num_2) {
  create_zero_big_decimal(num_2);
  for (int i = 0; i < S21_BIG_DECIMAL_NUMBER_CELLS; i++) {
    num_2->bits[i] = num_1.bits[i];
  }
}