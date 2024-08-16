#include "arithmetic.h"

void s21_pow_ten_big(int k, s21_big_decimal *ans) {
  if (k == 0) {
    create_one_big_decimal(ans);
    return;
  }
  create_zero_big_decimal(ans);
  ans->bits[0] = 10;
  s21_big_decimal a;
  s21_big_decimal b;

  for (int i = 1; i < k; i++) {
    s21_copy_big_decimal(*ans, &a);
    s21_copy_big_decimal(*ans, &b);

    s21_shift_big_decimal_left(&a, 3);
    s21_shift_big_decimal_left(&b, 1);
    s21_add_big(a, b, ans);
  }
}

void s21_mul_ten_big(s21_big_decimal *ans) {
  s21_big_decimal pow_ten;
  s21_pow_ten_big(1, &pow_ten);

  s21_mul_big(*ans, pow_ten, ans);
}