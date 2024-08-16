#include "conversion.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 0;
  create_zero_decimal(dst);
  if (!dst || (0 < fabsf(src) && fabsf(src) < 1e-28) || isnan(src) ||
      isinf(src) || 79228162514264337593543950335.f < src) {
    res = 1;
  } else {
    char part[128] = {0};
    int scale = 0;
    int fract = 0;  // дробная часть после точки
    int fract_length = 0;
    // считываем дробную часть
    sprintf(part, "%.7g", src);
    s21_get_float_part(part, &scale, &fract_length, &fract);
    //  но у нас есть ограничение 0 <= scale <= 28
    //  поэтому если scale отрицательный, то считываем число заново,обозначив
    //  точность для флага g
    if (scale < 0 && 28 < (abs(scale) + fract_length)) {
      memset(part, 0, 128);
      sprintf(part, "%.*g", 29 - abs(scale), src);
      s21_get_float_part(part, &scale, &fract_length, &fract);
    }
    // считываем целую часть и прибавляем дробную
    int number = abs(atoi(part));
    for (int i = 0; i < fract_length; ++i) {
      number *= 10;
    }
    number += fract;
    // записываем знак
    if (src < 0) {
      s21_set_sign_decimal(dst, 1);
    }
    // записываем степень
    // если степень < 0, то к ней нужно добавить длину после точки
    if (scale < 0) {
      s21_set_scale(dst, abs(scale) + fract_length);
    } else if (!scale) {
      s21_set_scale(dst, fract_length);
    }
    // записываем в мантиссу
    for (int i = 0; number; ++i, number /= 2) {
      if (number % 2) {
        s21_set_bit_decimal(dst, i, 1);
      }
    }
    // домножаем мантиссу на 10
    if (0 < scale - fract_length) {
      s21_decimal dec_10 = {{10, 0, 0, 0}};
      for (int i = 0; !res && i < (scale - fract_length); i++) {
        res = s21_mul(*dst, dec_10, dst);
      }
    }
  }
  return res;
}

void s21_get_float_part(char *part, int *scale, int *fract_length, int *fract) {
  char *dot = strchr(part, '.');
  char *exp = strchr(part, 'e');
  *scale = 0;
  *fract = 0;
  *fract_length = 0;

  if (exp) {
    *exp++ = '\0';
    *scale = atoi(exp);
  }

  if (dot) {
    *dot++ = '\0';
    *fract_length = strlen(dot);
    *fract = atoi(dot);
  }
}
