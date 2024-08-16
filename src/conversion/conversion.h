#ifndef S21_CONVERSION_H
#define S21_CONVERSION_H

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_from_decimal_to_big_decimal(s21_decimal src, s21_big_decimal *dst);
int s21_from_big_decimal_to_decimal(s21_big_decimal big_dcm, s21_decimal *dcm,
                                    int pow_add);
void copy_big_decimal_1_cells_to_decimal(s21_big_decimal big_dcm,
                                         s21_decimal *dcm);

int get_float_exp(float *value);
void s21_get_float_part(char *part, int *scale, int *fract_length, int *fract);
#endif
