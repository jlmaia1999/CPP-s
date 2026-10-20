#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <limits>


class RPN
{
	public:
		class InvalidNumber: public std::exception
		{
			virtual const char *what() const throw();
		};
		class MissingNumbers: public std::exception
		{
			virtual const char *what() const throw();
		};
		class InvalidOperation: public std::exception
		{
			virtual const char *what() const throw();
		};
		class DivisionByZero: public std::exception
		{
			virtual const char *what() const throw();
		};
		class ExpectedSpace: public std::exception
		{
			virtual const char *what() const throw();
		};
		class ExpectedOperation: public std::exception
		{
			virtual const char *what() const throw();
		};
		class Overflow: public std::exception
		{
			virtual const char *what() const throw();
		};

		static float stackManager(std::string str);
		static bool isOperation(char c);
		static float operations(float f1, float f2, char c);

	private:
		static std::stack<float>_stack;
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

};