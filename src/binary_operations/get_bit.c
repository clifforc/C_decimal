#include "binary_operations.h"

// Возвращает бит от 0 - 89 --> для Decimal
unsigned int s21_get_bit_decimal(s21_decimal num, unsigned int bit) {
  if (bit > S21_DECIMAL_BIT_SIGN) {
    return 0;
  }
  return s21_get_bit(num.bits[bit / S21_DECIMAL_NUMBER_BITS],
                     bit % S21_DECIMAL_NUMBER_BITS);
}

unsigned int s21_get_bit_big_decimal(s21_big_decimal num, unsigned int bit) {
  if (bit > S21_BIG_DECIMAL_BIT_SIGN) {
    return 0;
  }
  return s21_get_bit(num.bits[bit / S21_DECIMAL_NUMBER_BITS],
                     bit % S21_DECIMAL_NUMBER_BITS);
}

unsigned int s21_get_sign_decimal(s21_decimal num) {
  return s21_get_bit_decimal(num, S21_DECIMAL_BIT_SIGN);
}

unsigned int s21_get_sign_big_decimal(s21_big_decimal num) {
  return s21_get_bit_big_decimal(num, S21_BIG_DECIMAL_BIT_SIGN);
}

// Возвращает бит от 0 - 32
unsigned int s21_get_bit(unsigned int num, unsigned int bit) {
  return (num >> bit) & 1;
}

// scale
unsigned int s21_get_scale(s21_decimal num) {
  int mask = 0b11111111;
  mask <<= 16;
  return (num.bits[S21_DECIMAL_NUMBER_CELLS] & mask) >> 16;
}

unsigned int s21_get_scale_big(s21_big_decimal num) {
  int mask = 0b11111111;
  mask <<= 16;
  return (num.bits[S21_BIG_DECIMAL_NUMBER_CELLS] & mask) >> 16;
}
