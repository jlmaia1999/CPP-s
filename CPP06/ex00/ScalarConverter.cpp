#include "ScalarConverter.hpp"

static bool isChar(const std::string &s)
{
	if(s.size() != 1)
		return false;
	unsigned char c = static_cast<unsigned char>(s[0]);
	if (c<=127 && !std::isdigit(c))
		return true;
	return false;
}

static bool isInt(const std::string &s, int &out)
{
	if(s.empty())
		return false;
	char* end;
	errno = 0;
	long i = std::strtol(s.c_str(), &end, 10);
	if (*end != '\0')
		return false;
	if (errno == ERANGE || i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		return false;
	out = static_cast<int>(i);
	return true;
}

static bool isFloat(const std::string &s, float &out)
{
	if(s.empty() ||s[s.size() - 1] != 'f')
		return false;
	std::string digits = s.substr(0, s.size() - 1);
	if (digits.empty())
		return false;
	char* end;
	errno = 0;
	double f = std::strtod(digits.c_str(), &end);
	if(*end != '\0')
		return false;
	if (errno == ERANGE || f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
		return false;
	out = static_cast<float>(f);
	return true;
}

static bool isDouble(const std::string &s, double &out)
{
	if(s.empty())
		return false;
	char* end;
	double d = std::strtod(s.c_str(), &end);
	if (*end != '\0')
		return false;
	out = d;
	return true;
}

static void	print_inf(const std::string &s)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (s == "nan" || s == "-inf" || s == "+inf")
	{
		std::cout << "float: " << s + "f" << std::endl;
		std::cout << "double: " << s << std::endl;
	}
	else
	{
		std::cout << "float: " << s << std::endl;
		std::cout << "double: "<< s.substr(0, s.size() - 1) << std::endl;
	}
}

void ScalarConverter::convert(std::string literal)
{
	if (literal == "nan" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "-inff" || literal == "+inff")
		return print_inf(literal);
	char c = literal[0];
	int i;
	float f;
	double d;
	bool ch = isChar(literal);
	bool in = isInt(literal, i);
	bool fl = isFloat(literal, f);
	bool db = isDouble(literal, d);

	if (ch)
	{
		if (std::isprint(c))
			std::cout << "1char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return ;
	}
	if (in)
	{
		if (i >= 0 && i <= 127)
		{
			c = static_cast<char>(i);
			if (std::isprint(c))
				std::cout << "2char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << std::endl;
		std::cout << "double: " << static_cast<double>(i);
		return ;
	}
	if (fl)
	{
		if ((roundf(f) == f) && (f >= 0 && f <= 127))
		{
			c = static_cast<char>(f);
			if(std::isprint(c))
				std::cout << "3char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		if (f > std::numeric_limits<int>::min() && f < std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return ;
	}
	if (db)
	{
		if ((roundf(d) == d) && (d >= 0 && d <= 127))
		{
			c = static_cast<char>(d);
			if(std::isprint(c))
				std::cout << "4char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		if (d > std::numeric_limits<int>::min() && d < std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return ;
	}
	std::cout << "5char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}