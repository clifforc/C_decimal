.PHONY: all s21_decimal.a

CFLAGS = -Wall -Wextra -Werror

all: s21_decimal.a

s21_decimal.a: 
	gcc $(CFLAGS) -c help_functions/*.c
	gcc $(CFLAGS) -c arithmetic/*.c
	gcc $(CFLAGS) -c binary_operations/*.c
	gcc $(CFLAGS) -c other/*.c
	gcc $(CFLAGS) -lm -c conversion/*.c
	gcc $(CFLAGS) -c comparison/*.c
	gcc $(CFLAGS) -c fredatar_comparison/*.c
	ar rcs s21_decimal.a *.o

test: s21_decimal.a
	gcc $(CFLAGS) tests/arithmetic/test_add_500.c s21_decimal.a -o tests/arithmetic/test_add.out -lm -lcheck
	gcc $(CFLAGS) tests/arithmetic/test_sub_500.c s21_decimal.a -o tests/arithmetic/test_sub.out -lm -lcheck
	gcc $(CFLAGS) tests/arithmetic/test_mul_500.c s21_decimal.a -o tests/arithmetic/test_mul.out -lm -lcheck
	gcc $(CFLAGS) tests/arithmetic/test_div_500.c s21_decimal.a -o tests/arithmetic/test_div.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_less.c s21_decimal.a -o tests/compare/test_is_less.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_greater.c s21_decimal.a -o tests/compare/test_is_greater.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_lor.c s21_decimal.a -o tests/compare/test_is_lor.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_gor.c s21_decimal.a -o tests/compare/test_is_gor.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_equal.c s21_decimal.a -o tests/compare/test_is_equal.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_ne.c s21_decimal.a -o tests/compare/test_is_ne.out -lm -lcheck
	gcc $(CFLAGS) tests/conversion/conversion.c s21_decimal.a -o tests/conversion/test_conversion.out -lm -lcheck
	gcc $(CFLAGS) tests/other/test_other.c s21_decimal.a -o tests/other/test_other.out -lm -lcheck
	./tests/arithmetic/test_add.out
	./tests/arithmetic/test_sub.out
	./tests/arithmetic/test_mul.out
	./tests/arithmetic/test_div.out
	./tests/compare/test_is_less.out
	./tests/compare/test_is_greater.out
	./tests/compare/test_is_lor.out
	./tests/compare/test_is_gor.out
	./tests/compare/test_is_equal.out
	./tests/compare/test_is_ne.out
	./tests/conversion/test_conversion.out
	./tests/other/test_other.out

test_arithmetic: s21_decimal.a
	gcc $(CFLAGS) tests/arithmetic/test_add_500.c s21_decimal.a -o tests/arithmetic/test_add.out -lm -lcheck
	gcc $(CFLAGS) tests/arithmetic/test_sub_500.c s21_decimal.a -o tests/arithmetic/test_sub.out -lm -lcheck
	gcc $(CFLAGS) tests/arithmetic/test_mul_500.c s21_decimal.a -o tests/arithmetic/test_mul.out -lm -lcheck
	gcc $(CFLAGS) tests/arithmetic/test_div_500.c s21_decimal.a -o tests/arithmetic/test_div.out -lm -lcheck
	./tests/arithmetic/test_add.out
	./tests/arithmetic/test_sub.out
	./tests/arithmetic/test_mul.out
	./tests/arithmetic/test_div.out



test_compare: s21_decimal.a
	gcc $(CFLAGS) tests/compare/test_is_less.c s21_decimal.a -o tests/compare/test_is_less.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_greater.c s21_decimal.a -o tests/compare/test_is_greater.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_lor.c s21_decimal.a -o tests/compare/test_is_lor.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_gor.c s21_decimal.a -o tests/compare/test_is_gor.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_equal.c s21_decimal.a -o tests/compare/test_is_equal.out -lm -lcheck
	gcc $(CFLAGS) tests/compare/test_is_ne.c s21_decimal.a -o tests/compare/test_is_ne.out -lm -lcheck
	./tests/compare/test_is_less.out
	./tests/compare/test_is_greater.out
	./tests/compare/test_is_lor.out
	./tests/compare/test_is_gor.out
	./tests/compare/test_is_equal.out
	./tests/compare/test_is_ne.out
	

test_conversion: s21_decimal.a
	gcc $(CFLAGS) tests/conversion/conversion.c s21_decimal.a -o tests/conversion/test_conversion.out -lm -lcheck
	./tests/conversion/test_conversion.out

test_other: s21_decimal.a
	gcc $(CFLAGS) tests/other/test_other.c s21_decimal.a -o tests/other/test_other.out -lm -lcheck
	./tests/other/test_other.out

gcov_report: s21_decimal.a 
	gcc -fprofile-arcs -ftest-coverage tests/arithmetic/test_add_500.c s21_decimal.a -o tests/test_add.out -lm -lcheck

	gcc -fprofile-arcs -ftest-coverage tests/arithmetic/test_add_500.c s21_decimal.a -o tests/arithmetic/test_add.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/arithmetic/test_sub_500.c s21_decimal.a -o tests/arithmetic/test_sub.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/arithmetic/test_mul_500.c s21_decimal.a -o tests/arithmetic/test_mul.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/arithmetic/test_div_500.c s21_decimal.a -o tests/arithmetic/test_div.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/compare/test_is_less.c s21_decimal.a -o tests/compare/test_is_less.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/compare/test_is_greater.c s21_decimal.a -o tests/compare/test_is_greater.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/compare/test_is_lor.c s21_decimal.a -o tests/compare/test_is_lor.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/compare/test_is_gor.c s21_decimal.a -o tests/compare/test_is_gor.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/compare/test_is_equal.c s21_decimal.a -o tests/compare/test_is_equal.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/compare/test_is_ne.c s21_decimal.a -o tests/compare/test_is_ne.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/conversion/conversion.c s21_decimal.a -o tests/conversion/test_conversion.out -lm -lcheck
	gcc -fprofile-arcs -ftest-coverage tests/other/test_other.c s21_decimal.a -o tests/other/test_other.out -lm -lcheck
	./tests/arithmetic/test_add.out
	./tests/arithmetic/test_sub.out
	./tests/arithmetic/test_mul.out
	./tests/arithmetic/test_div.out
	./tests/compare/test_is_less.out
	./tests/compare/test_is_greater.out
	./tests/compare/test_is_lor.out
	./tests/compare/test_is_gor.out
	./tests/compare/test_is_equal.out
	./tests/compare/test_is_ne.out
	./tests/conversion/test_conversion.out
	./tests/other/test_other.out
	gcov -f s21_decimal.a
	lcov -t "gcov_report" -o tests.info -c -d .
	genhtml -o ./report tests.info
	open ./report/index.html

rebuild: clean all

clean:
	rm -f *.gcno *.gcda *.info *.gcov
	rm -f *.o tests/*out *.a
	rm -f *.o tests/arithmetic/*out *.a
	rm -f *.o tests/conversion/*out *.a
	rm -f *.o tests/compare/*out *.a
	rm -f *.o tests/compare/*out *.a
	rm -f *.o tests/other/*out *.a
	rm -rf ./report
	rm -f *.out



clang:
	cp ../materials/linters/.clang-format .
	# clang-format -n *.c
	clang-format -n *.h
	clang-format -n */*.c
	clang-format -n */*.h
	clang-format -n tests/*/*.c
	clang-format -n tests/*/*.h
	rm -f .clang-format

clang-i:
	cp ../materials/linters/.clang-format .
	# clang-format -i *.c
	clang-format -i *.h
	clang-format -i */*.c
	clang-format -i */*.h
	clang-format -i tests/*/*.c
	clang-format -i tests/*/*.h
	rm -f .clang-format

cppcheck:
	# cppcheck --enable=all --suppress=missingIncludeSystem *.c
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction */*.c
	cppcheck --enable=all --suppress=missingIncludeSystem */*.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.h




