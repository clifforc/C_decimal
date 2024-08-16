#ifndef S21_HELP_FUNCTION
#define S21_HELP_FUNCTION

#include "../s21_decimal.h"

// create zero
void create_zero_decimal(s21_decimal *dcm);
void create_zero_big_decimal(s21_big_decimal *dcm);

// create one
void create_one_big_decimal(s21_big_decimal *dcm);

// add one
void add_big_one(s21_big_decimal *num);
void sub_big_one(s21_big_decimal *num);

// copy
void s21_copy_big_decimal(s21_big_decimal num_1, s21_big_decimal *num_2);

// is zero
int is_zero(s21_decimal num);
int is_zero_big(s21_big_decimal num);
int is_zero_big_2_cells(s21_big_decimal num);

// rounds
void round_bank_big(s21_big_decimal ramainder, s21_big_decimal divider,
                    s21_big_decimal *bank_round);

// normalization
void normalization(s21_big_decimal *num_1, s21_big_decimal *num_2);

#endif