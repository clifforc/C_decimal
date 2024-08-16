#ifndef S21_ARITHMETIC_H
#define S21_ARITHMETIC_H

#include "../s21_decimal.h"

// sum
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_add_big(s21_big_decimal num_1, s21_big_decimal num_2,
                s21_big_decimal *result);
int s21_sub_big(s21_big_decimal num_1, s21_big_decimal num_2,
                s21_big_decimal *result);

void s21_additional_code(s21_big_decimal *value);
void s21_direct_code(s21_big_decimal *value);

void s21_summ_all_cell(s21_big_decimal num_1, s21_big_decimal num_2,
                       s21_big_decimal *result);
void s21_summ_cell(unsigned int value_1, unsigned int value_2,
                   unsigned int *value_3, int *transfer);

// div
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_mod_big(s21_big_decimal num_1, s21_big_decimal num_2,
                 s21_big_decimal *ans);
void s21_remainder_big(s21_big_decimal num_1, s21_big_decimal num_2,
                       s21_big_decimal *ans);
void s21_div_big(s21_big_decimal num_1, s21_big_decimal num_2,
                 s21_big_decimal *result);

// mul
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_mul_big(s21_big_decimal num_1, s21_big_decimal num_2,
                 s21_big_decimal *result);
void s21_mul_ten_big(s21_big_decimal *ans);

// pow
void s21_pow_ten_big(int k, s21_big_decimal *ans);
#endif