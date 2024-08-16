#include "arithmetic.h"

void s21_direct_code(s21_big_decimal *value) {
  // FIIIIXXXX MMMEEEE: когда сделаем преобразование из int, заменить тут
  s21_big_decimal one;
  create_zero_big_decimal(&one);
  one.bits[0] = 1;
  s21_set_sign_big_decimal(&one, 1);
  //-1
  // s21_set_bit(&one.bits[S21_DECIMAL_NUMBER_CELLS],S21_DECIMAL_NUMBER_BITS-1,
  // 1); one.bits[3] = 2147483648;
  s21_additional_code(&one);
  s21_summ_all_cell(*value, one, value);

  for (int i = 0; i < S21_BIG_DECIMAL_NUMBER_CELLS; i++) {
    value->bits[i] = ~(value->bits[i]);
  }
}