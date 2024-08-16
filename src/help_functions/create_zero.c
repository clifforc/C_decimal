#include "help_functions.h"

void create_zero_decimal(s21_decimal *dcm) {
  for (int i = 0; i <= S21_DECIMAL_NUMBER_CELLS; i++) {
    dcm->bits[i] = 0;
  }
}

void create_zero_big_decimal(s21_big_decimal *dcm) {
  for (int i = 0; i <= S21_BIG_DECIMAL_NUMBER_CELLS; i++) {
    dcm->bits[i] = 0;
  }
}

void create_one_big_decimal(s21_big_decimal *dcm) {
  create_zero_big_decimal(dcm);
  dcm->bits[0] = 1;
}