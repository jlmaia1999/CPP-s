#include "Array.hpp"

#include <iostream>
#include <string>

int main(void)
{
    Array<int> empty;
    std::cout << "empty size: " << empty.size() << std::endl;

    Array<int> numbers(5);
    for (unsigned int i = 0; i < numbers.size(); ++i)
        numbers[i] = static_cast<int>(i) * 10;

    std::cout << "numbers:";
    for (unsigned int i = 0; i < numbers.size(); ++i)
        std::cout << ' ' << numbers[i];
    std::cout << std::endl;

    Array<int> copy(numbers);
    copy[2] = 42;
    std::cout << "original[2] = " << numbers[2] << std::endl;
    std::cout << "copy[2] = " << copy[2] << std::endl;

    Array<std::string> words(3);
    words[0] = "zero";
    words[1] = "one";
    words[2] = "two";

    std::cout << "words:";
    for (unsigned int i = 0; i < words.size(); ++i)
        std::cout << ' ' << words[i];
    std::cout << std::endl;

    try
    {
        numbers[10] = 99;
    }
    catch (const std::exception &e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return 0;
}

