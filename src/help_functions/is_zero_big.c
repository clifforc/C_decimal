#include "help_functions.h"

int is_zero(s21_decimal num) {
  int flag = 1;
  for (int i = 0; i < S21_DECIMAL_NUMBER_CELLS && flag; i++) {
    if (num.bits[i] != 0) {
      flag = 0;
    }
  }

  return flag;
}

int is_zero_big(s21_big_decimal num) {
  int flag = 1;
  int i = S21_BIG_DECIMAL_NUMBER_CELLS - 1;
  while (i >= 0 && flag) {
    if (num.bits[i] != 0) {
      flag = 0;
    }
    --i;
  }
  return flag;
}

int is_zero_big_2_cells(s21_big_decimal num) {
  int flag = 1;
  for (int i = S21_DECIMAL_NUMBER_CELLS;
       i < S21_BIG_DECIMAL_NUMBER_CELLS && flag; i++) {
    if (num.bits[i] != 0) {
      flag = 0;
    }
  }

  return flag;
}