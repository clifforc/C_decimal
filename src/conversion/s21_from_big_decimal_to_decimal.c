#include "conversion.h"

/*
 * Функция делящая на десять, пока big decimal не влезет в decimal
 * Ошибки:
 * 0 - ОК
 * 1 - Слишком велико
 */

int s21_from_big_decimal_to_decimal(s21_big_decimal big_dcm, s21_decimal *dcm,
                                    int pow_add) {
  int flag_error = 0;

  s21_big_decimal ans;
  s21_copy_big_decimal(big_dcm, &ans);
  s21_big_decimal ten_pow;

  // Делим на 10 в k степени, чтобы можно было перевести в Decimal
  int k = 0;
  while (!is_zero_big_2_cells(ans)) {
    k++;
    s21_pow_ten_big(k, &ten_pow);
    s21_div_big(big_dcm, ten_pow, &ans);
  }

  // Изменяем степень
  int pow = pow_add - k;

  // Пытаемся нормировать степень
  if (pow < 0) {
    while (pow < 0 && !flag_error) {
      s21_mul_ten_big(&ans);
      pow++;
      if (!is_zero_big_2_cells(ans)) {
        flag_error = 1;
        pow = 0;
      }
    }
  } else if (pow > 28 && !flag_error) {
    s21_big_decimal ans_2;
    s21_copy_big_decimal(ans, &ans_2);
    int k2 = 0;
    while (pow > 28) {
      k2++;
      s21_pow_ten_big(k2, &ten_pow);
      s21_div_big(ans_2, ten_pow, &ans);
      pow--;
      if (is_zero_big(ans)) {
        pow = 0;
        flag_error = 2;
      }
    }
  }

  copy_big_decimal_1_cells_to_decimal(ans, dcm);
  // Устанавливаем степень и знак
  s21_set_scale(dcm, pow);
  s21_set_sign_decimal(dcm, s21_get_sign_big_decimal(big_dcm));

  // Минус бесконечность
  if (flag_error == 1) {
    if (s21_get_sign_decimal(*dcm) == 1) {
      flag_error = 2;
    }
  }

  return flag_error;
}

void copy_big_decimal_1_cells_to_decimal(s21_big_decimal big_dcm,
                                         s21_decimal *dcm) {
  create_zero_decimal(dcm);
  for (int i = 0; i < S21_DECIMAL_NUMBER_CELLS; i++) {
    dcm->bits[i] = big_dcm.bits[i];
  }

  // Устанавливаем знак
  s21_set_sign_decimal(dcm, s21_get_sign_big_decimal(big_dcm));
}