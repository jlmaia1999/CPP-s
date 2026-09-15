#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private:
		std::vector<int> _numbers;
		unsigned int _size_max;
	public:
		Span(unsigned int size);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(const int num);
		int shortestSpan();
		int longestSpan();
};