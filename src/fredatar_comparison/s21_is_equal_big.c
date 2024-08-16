#include "comparison.h"

int s21_is_equal_big(s21_big_decimal num_1, s21_big_decimal num_2) {
  signed int sign_num_1 = s21_get_sign_big_decimal(num_1);
  signed int sign_num_2 = s21_get_sign_big_decimal(num_2);

  int flag = 1;
  int i = S21_BIG_DECIMAL_NUMBER_CELLS - 1;

  if (!is_zero_big(num_1) || !is_zero_big(num_2)) {
    if (sign_num_1 != sign_num_2) {
      flag = 0;
    } else {
      while (i >= 0 && flag == 1) {
        if (num_1.bits[i] == num_2.bits[i]) {
          flag = 1;
        } else {
          flag = 0;
        }
        --i;
      }
    }
  }
  return flag;
}
