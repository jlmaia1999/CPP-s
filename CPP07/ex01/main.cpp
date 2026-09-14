#include "iter.hpp"

void printnum(const int &num)
{
	std::cout << num << " ";
}

void incnum(int &num)
{
	num++;
}

void printchar(const char &c)
{
	std::cout << c << " ";
}

int main()
{
	int arr1[] = {1, 2, 3, 4, 5};
	char arr2[] = {'a', 'b', 'c', 'd', 'e'};

	iter(arr1, 5, printnum);
	std::cout << std::endl;
	iter(arr1, 5, incnum);
	iter(arr1, 5, printnum);
	std::cout << std::endl;
	iter(arr2, 5, printchar);
	std::cout << std::endl;
	iter(arr2, 5, printchar);
}
