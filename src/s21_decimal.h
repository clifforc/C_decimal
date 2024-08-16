#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#define S21_DECIMAL_NUMBER_CELLS 3
#define S21_DECIMAL_NUMBER_BITS 32

#define S21_BIG_DECIMAL_NUMBER_CELLS S21_DECIMAL_NUMBER_CELLS * 2

typedef struct {
  unsigned int bits[S21_DECIMAL_NUMBER_CELLS + 1];
} s21_decimal;

typedef struct {
  unsigned int bits[S21_BIG_DECIMAL_NUMBER_CELLS + 1];
} s21_big_decimal;

#define S21_DECIMAL_BIT_SIGN \
  ((S21_DECIMAL_NUMBER_CELLS + 1) * S21_DECIMAL_NUMBER_BITS - 1)
#define S21_BIG_DECIMAL_BIT_SIGN \
  ((S21_BIG_DECIMAL_NUMBER_CELLS + 1) * S21_DECIMAL_NUMBER_BITS - 1)

// Для тестов, содержит функции вывода
#include "arithmetic/arithmetic.h"
#include "binary_operations/binary_operations.h"
#include "comparison/s21_comparison.h"
#include "conversion/conversion.h"
#include "fredatar_comparison/comparison.h"
#include "help_functions/help_functions.h"
#include "other/other.h"
#endif
