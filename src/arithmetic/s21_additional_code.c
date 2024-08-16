#include "arithmetic.h"

void s21_additional_code(s21_big_decimal *value) {
  for (int i = 0; i < S21_BIG_DECIMAL_NUMBER_CELLS; i++) {
    value->bits[i] = ~(value->bits[i]);
  }
  // FIIIIXXXX MMMEEEE: когда сделаем преобразование из int, заменить тут
  s21_big_decimal one;
  create_zero_big_decimal(&one);
  one.bits[0] = 1;
  s21_summ_all_cell(*value, one, value);
}