#pragma once


#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <cmath>

class ScalarConverter
{
	public:
		static void convert(std::string literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &other);
};