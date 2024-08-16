#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../s21_decimal.h"
#include "test_conversion.h"

START_TEST(test_dit) {
  for (size_t i = 0, j = 0; i < sizeof(src1) / sizeof(s21_decimal); ++i) {
    int tmp;
    int res = s21_from_decimal_to_int(src1[i], &tmp);
    ck_assert_int_eq(tmp, dst1[j]);
    ++j;
    ck_assert_int_eq(res, 0);
  }
}
END_TEST

START_TEST(test_dtf) {
  for (size_t i = 0; i < sizeof(src2) / sizeof(s21_decimal); ++i) {
    for (size_t i = 0; i < sizeof(src2) / sizeof(s21_decimal); ++i) {
      float tmp;
      int ret = s21_from_decimal_to_float(src2[i], &tmp);

      ck_assert_float_eq(tmp, dst2[i]);
      ck_assert_int_eq(ret, 0);
    }
  }
}
END_TEST

START_TEST(tes_ftd) {
  for (size_t i = 0; i < sizeof(src3) / sizeof(float); ++i) {
    s21_decimal tmp;
    int ret = s21_from_float_to_decimal(src3[i], &tmp);
    ck_assert_int_eq(tmp.bits[0], dst3[i].bits[0]);
    ck_assert_int_eq(tmp.bits[1], dst3[i].bits[1]);
    ck_assert_int_eq(tmp.bits[2], dst3[i].bits[2]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

START_TEST(test_itd) {
  for (size_t i = 0; i < sizeof(dst1) / sizeof(int); ++i) {
    s21_decimal tmp;
    int ret = s21_from_int_to_decimal(dst1[i], &tmp);
    ck_assert_int_eq(tmp.bits[0], src1[i].bits[0]);
    ck_assert_int_eq(tmp.bits[1], src1[i].bits[1]);
    ck_assert_int_eq(tmp.bits[2], src1[i].bits[2]);
    ck_assert_int_eq(tmp.bits[3], src1[i].bits[3]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_dit);
  tcase_add_test(tc1_1, test_dtf);
  tcase_add_test(tc1_1, tes_ftd);
  tcase_add_test(tc1_1, test_itd);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
