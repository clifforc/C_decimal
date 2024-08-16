#ifndef S21_HELP_FUNCTION_H
#define S21_HELP_FUNCTION_H

#include "../s21_decimal.h"

// get
unsigned int s21_get_bit(unsigned int num, unsigned int bit);
//  bit
unsigned int s21_get_bit_decimal(s21_decimal num, unsigned int bit);
unsigned int s21_get_bit_big_decimal(s21_big_decimal num, unsigned int bit);
//  sign
unsigned int s21_get_sign_decimal(s21_decimal num);
unsigned int s21_get_sign_big_decimal(s21_big_decimal num);

// set
void s21_set_bit(unsigned int *num, unsigned int bit, unsigned int value);
//  bit
void s21_set_bit_decimal(s21_decimal *num, unsigned int bit,
                         unsigned int value);
void s21_set_bit_big_decimal(s21_big_decimal *num, unsigned int bit,
                             unsigned int value);
//  sign
void s21_set_sign_decimal(s21_decimal *num, unsigned int bit);
void s21_set_sign_big_decimal(s21_big_decimal *num, unsigned int bit);

// scale
unsigned int s21_get_scale_big(s21_big_decimal num);
unsigned int s21_get_scale(s21_decimal num);
void s21_set_scale_big(s21_big_decimal *num, int scale);
void s21_set_scale(s21_decimal *num, int scale);

// shift
int s21_shift_big_decimal_left(s21_big_decimal *num, int shift_value);
int s21_shift_big_decimal_left_one(s21_big_decimal *num);
int s21_shift_big_decimal_right(s21_big_decimal *num, int shift_value);
int s21_shift_big_decimal_right_one(s21_big_decimal *num);
#endif