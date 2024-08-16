#include "help_functions.h"

void round_bank_big(s21_big_decimal ramainder, s21_big_decimal divider,
                    s21_big_decimal *bank_round) {
  create_zero_big_decimal(bank_round);
  s21_shift_big_decimal_left(&ramainder, 1);

  // Доделать для банковского, т.е. если равны.
  if (s21_is_greater_or_equal_big(ramainder, divider)) {
    create_one_big_decimal(bank_round);
  }
}