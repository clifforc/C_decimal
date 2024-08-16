#include "comparison.h"

int s21_is_less_or_equal_big(s21_big_decimal num_1, s21_big_decimal num_2) {
  signed int sign_num_1 = s21_get_sign_big_decimal(num_1);
  signed int sign_num_2 = s21_get_sign_big_decimal(num_2);

  int flag = 1;
  int i = S21_BIG_DECIMAL_NUMBER_CELLS - 1;

  if (!is_zero_big(num_1) || !is_zero_big(num_2)) {
    // sign num_1 > 0   &&   sign num_2 > 0
    int flag_tmp = 0;
    if (!sign_num_1 && !sign_num_2) {
      while (i >= 0 && flag_tmp == 0) {
        if (num_1.bits[i] > num_2.bits[i]) {
          flag = 0;
          flag_tmp = 1;
        } else if (num_1.bits[i] < num_2.bits[i]) {
          flag = 1;
          flag_tmp = 1;
        }
        --i;
      }
    }
    // sign num_1 < 0   &&   sign num_2 < 0
    else if (sign_num_1 && sign_num_2) {
      while (i >= 0 && flag_tmp == 0) {
        if (num_1.bits[i] < num_2.bits[i]) {
          flag = 0;
          flag_tmp = 1;
        } else if (num_1.bits[i] > num_2.bits[i]) {
          flag = 1;
          flag_tmp = 1;
        }
        --i;
      }
    }
    // sign num_1 < 0   &&   sign num_2 > 0
    else if (sign_num_1 && !sign_num_2) {
      flag = 1;
    }
    // sign num_1 > 0   &&   sing num_2 < 0
    else if (!sign_num_1 && sign_num_2) {
      flag = 0;
    }
  }
  return flag;
}
