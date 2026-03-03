#pragma once
#include <charconv>
#include <climits>
#include <cmath>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

class ScalarConverter {
	private:
		enum valueType {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			NAND,
			POSINF,
			NEGINF,
			NANF,
			POSINFF,
			NEGINFF,
			NONE
		};
		static valueType deduceType(const std::string &literal);
		static void convertAndPrintValue(const double value, valueType type,
										 bool exceptionHappened);

	public:
		ScalarConverter(void) = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;
		~ScalarConverter(void) = delete;

		static void convert(const std::string &literal);
};
