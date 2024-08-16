#include "arithmetic.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag_error = 0;

  s21_big_decimal num_1;
  s21_big_decimal num_2;
  s21_big_decimal ans;

  s21_from_decimal_to_big_decimal(value_1, &num_1);
  s21_from_decimal_to_big_decimal(value_2, &num_2);
  create_zero_big_decimal(&ans);

  normalization(&num_1, &num_2);

  s21_add_big(num_1, num_2, &ans);

  int pow_num = s21_get_scale_big(num_1);
  flag_error = s21_from_big_decimal_to_decimal(ans, result, pow_num);

  return flag_error;
}

int s21_add_big(s21_big_decimal num_1, s21_big_decimal num_2,
                s21_big_decimal *result) {
  // Дополнительный код(отрицательные значения)
  if (s21_get_sign_big_decimal(num_1) == 1) {
    s21_additional_code(&num_1);
  }

  if (s21_get_sign_big_decimal(num_2) == 1) {
    s21_additional_code(&num_2);
  }

  s21_summ_all_cell(num_1, num_2, result);

  if (s21_get_sign_big_decimal(*result) == 1) {
    s21_direct_code(result);
  }

  return 0;
}

void s21_summ_all_cell(s21_big_decimal num_1, s21_big_decimal num_2,
                       s21_big_decimal *result) {
  // Перенос знака при сложении 9+1 = 0  и 1 переносится
  int transfer = 0;

  for (int i = 0; i < S21_BIG_DECIMAL_NUMBER_CELLS; i++) {
    s21_summ_cell(num_1.bits[i], num_2.bits[i], &(result->bits[i]), &transfer);
  }

  // Узнаем знак
  unsigned int sign_val_1 = s21_get_sign_big_decimal(num_1);
  unsigned int sign_val_2 = s21_get_sign_big_decimal(num_2);
  // Нужна проверка на переполнение, но так как это биг, то переполнения не
  // будет.
  s21_set_sign_big_decimal(result, (sign_val_1 + sign_val_2 + transfer) % 2);
}

void s21_summ_cell(unsigned int value_1, unsigned int value_2,
                   unsigned int *value_3, int *transfer) {
  for (unsigned int i = 0; i < S21_DECIMAL_NUMBER_BITS; i++) {
    unsigned int a = s21_get_bit(value_1, i);
    unsigned int b = s21_get_bit(value_2, i);
    unsigned int sum = a + b + *transfer;
    // получили 10, то 1 переносится, а 0 устанавливается

    // Переносимый бит
    *transfer = s21_get_bit(sum, 1);
    // Устанавливаемый бит
    s21_set_bit(value_3, i, s21_get_bit(sum, 0));
  }
}
