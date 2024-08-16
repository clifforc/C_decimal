#include "binary_operations.h"

// Устанавливает бит для Decimal
void s21_set_bit_decimal(s21_decimal *num, unsigned int bit,
                         unsigned int value) {
  if (bit > S21_DECIMAL_BIT_SIGN) {
  }
  s21_set_bit(&(num->bits[bit / S21_DECIMAL_NUMBER_BITS]),
              bit % S21_DECIMAL_NUMBER_BITS, value);
}

void s21_set_bit_big_decimal(s21_big_decimal *num, unsigned int bit,
                             unsigned int value) {
  if (bit > S21_BIG_DECIMAL_BIT_SIGN) {
  }
  s21_set_bit(&(num->bits[bit / S21_DECIMAL_NUMBER_BITS]),
              bit % S21_DECIMAL_NUMBER_BITS, value);
}

// sign
void s21_set_sign_decimal(s21_decimal *num, unsigned int bit) {
  s21_set_bit_decimal(num, S21_DECIMAL_BIT_SIGN, bit);
}

void s21_set_sign_big_decimal(s21_big_decimal *num, unsigned int bit) {
  s21_set_bit_big_decimal(num, S21_BIG_DECIMAL_BIT_SIGN, bit);
}

// Устанавливает бит для int(unsignedы int)
void s21_set_bit(unsigned int *num, unsigned int bit, unsigned int value) {
  if (value == 1) {
    *num |= (1 << bit);
  } else if (value == 0) {
    *num &= ~(1 << bit);
  } else {
  }
}

// scale
void s21_set_scale(s21_decimal *num, int scale) {
  if (scale <= 28 && scale >= 0) {
    for (int i = 0; i < 8; i++) {
      s21_set_bit_decimal(
          num, i + 16 + S21_DECIMAL_NUMBER_CELLS * S21_DECIMAL_NUMBER_BITS,
          scale % 2);
      scale >>= 1;
    }
  } else {
  }
}

void s21_set_scale_big(s21_big_decimal *num, int scale) {
  if (scale <= 28 && scale >= 0) {
    for (int i = 0; i < 8; i++) {
      s21_set_bit_big_decimal(
          num, i + 16 + S21_BIG_DECIMAL_NUMBER_CELLS * S21_DECIMAL_NUMBER_BITS,
          scale % 2);
      scale >>= 1;
    }
  } else {
  }
}