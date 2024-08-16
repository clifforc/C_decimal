# s21_decimal

Implementation of the s21_decimal.h library in C.

## Project Description

The s21_decimal project is an implementation of a library for working with the "decimal" type in C. This data type is particularly important for financial calculations where high precision is required and rounding errors inherent to floating-point types are unacceptable.

The library is developed in C11 standard using the gcc compiler.</br>
The library is implemented as a static library named `s21_decimal.a`.</br>
The implementation is based on the binary representation of the number as an integer array of bits.</br>
The project is fully covered with unit tests using the Check library.

## Functionality

The library includes the following groups of functions:

1. Arithmetic operators (addition, subtraction, multiplication, division);
2. Comparison operators;
3. Converters (from int, from float, to int, to float);
4. Other mathematical operations (rounding, truncation, etc.).

## Building and Usage

A Makefile is used to build the library and run tests with the following targets:

- `make all`: build the entire project;
- `make clean`: clean build files;
- `make test`: run unit tests;
- `make s21_decimal.a`: build the static library;
- `make gcov_report`: generate a test coverage report in HTML format.

## Project Team

The project was completed by a team of School 21 students.

## License

This project is part of the educational program at [School21](https://21-school.ru/) - an educational project by Sber for developers.
