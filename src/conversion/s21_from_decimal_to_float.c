#include "conversion.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 0;
  unsigned int scale = s21_get_scale(src);
  if (!dst || scale > 28) {
    res = 1;
  } else {
    double temp = 0;
    // получаем сумму мантиссы
    for (int i = 0; i < 96; ++i) {
      if (s21_get_bit_decimal(src, i)) {
        temp += pow(2, i);
      }
    }
    // делим с учетом scale
    temp /= pow(10, scale);

    // устанавливаем знак
    if (s21_get_sign_decimal(src)) {
      temp *= -1;
    }
    *dst = temp;
  }
  return res;
}
