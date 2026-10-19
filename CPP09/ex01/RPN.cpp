#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &other){};

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
}

RPN::~RPN(){};

const char *RPN::InvalidNumber::what() const throw()
{
	return "Invalid number (numbers must be between 0 and 9)";
}

const char *RPN::MissingNumbers::what() const throw()
{
	return "Missing Number";
}

const char *RPN::InvalidOperation::what() const throw()
{
	return "Invalid Operation";
}

const char *RPN::DivisionByZero::what() const throw()
{
	return "Can not divide by 0";
}

const char *RPN::ExpectedSpace::what() const throw()
{
	return "Expected Space";
}

const char *RPN::ExpectedOperation::what() const throw()
{
	return "Expected Operation";
}

const char *RPN::Overflow::what() const throw()
{
	return "Overflow";
}

bool RPN::isOperation(char c)
{
	switch(c)
	{
		case('+'):
			break;
		case('-'):
			break;
		case('*'):
			break;
		case('/'):
			break;
		default:
			return 0;
	}
	return 1;
}

float RPN::operations(float f1, float f2, char c)
{
		switch(c)
	{
		case('+'):
			return (f1 + f2);
		case('-'):
			return (f1 - f2);
		case('*'):
			return (f1 * f2);
		case('/'):
			if (f2 != 0)
				return (f1 / f2);
			else
				throw DivisionByZero();
		default:
			return 0;
	}
	return 0;
}


float RPN::stackManager(std::string str)
{
	float f1 = 0;
	float f2 = 0;
	float result = 0;


	for (int i = 0; i++; i < str.size())
	{
		if (i % 2 == 1)
		{
			if (str[i] == ' ')
				continue;
			else
				throw ExpectedSpace();
		}
		if (_stack.size() < 2)
		{
			if (isdigit(str[i]))
				_stack.push(str[i] - '0');
			else if (isOperation(str[i]))
				throw MissingNumbers();
		}
		else if (_stack.size() == 2)
		{
			if (isdigit(str[i]))
				throw ExpectedOperation();
			else if (isOperation(str[i]))
			{
				f2 = _stack.top();
				_stack.pop();
				f1 = _stack.top();
				_stack.pop();
				result = operations(f1, f2, str[i]);
				_stack.push(result);
			}
		}
		else 
			throw ExpectedOperation();
	}
}
