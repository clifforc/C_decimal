#include "comparison.h"

int s21_is_greater_or_equal_big(s21_big_decimal num_1, s21_big_decimal num_2) {
  signed int sign_1 = s21_get_sign_big_decimal(num_1);
  signed int sign_2 = s21_get_sign_big_decimal(num_2);

  int flag = 1;
  int flag_ravno = 1;
  for (int i = S21_BIG_DECIMAL_NUMBER_CELLS - 1; i >= 0 && flag_ravno; i--) {
    if (num_1.bits[i] < num_2.bits[i]) {
      flag = 0;
      flag_ravno = 0;
    } else if (num_1.bits[i] > num_2.bits[i]) {
      flag_ravno = 0;
    }
  }
  if (sign_1 && sign_2) {
    if (!flag) {
      flag = 1;
    } else if (!flag_ravno) {
      flag = 0;
    }
  } else if (sign_1 && !sign_2) {
    if (flag) {
      flag = 0;
    }
  } else if (!sign_1 && sign_2) {
    if (!flag) {
      flag = 1;
    }
  }
  return flag;
}
