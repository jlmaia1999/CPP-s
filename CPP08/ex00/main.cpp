#include "easyfind.hpp"

#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    std::vector<int>::iterator found = easyfind(numbers, 30);
    if (found != numbers.end())
        std::cout << "Found: " << *found << std::endl;
    else
        std::cout << "Not found" << std::endl;

    std::vector<int>::iterator missing = easyfind(numbers, 10);
    if (missing != numbers.end())
        std::cout << "Found: " << *missing << std::endl;
    else
        std::cout << "Not found" << std::endl;

    return 0;
}
