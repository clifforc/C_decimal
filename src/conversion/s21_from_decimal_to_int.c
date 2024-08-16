#include "conversion.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (dst == NULL) {
    return 1;
  }
  int res = 0;
  *dst = 0;
  if (!src.bits[1] && !src.bits[2]) {
    unsigned int scale = s21_get_scale(src);
    long int temp = src.bits[0];

    if (scale <= 28) {
      temp /= pow(10, scale);
    } else
      res = 1;

    unsigned int sign = s21_get_sign_decimal(src);
    if (temp == (long int)INT_MAX + 1 && sign) {
      // случай отрицательного числа с мантиссой 2147483648
      *dst = temp * (-1);
    } else if (temp <= INT_MAX) {
      *dst = temp;
      if (sign) *dst *= -1;
    } else
      res = 1;
  } else
    res = 1;
  return res;
}
