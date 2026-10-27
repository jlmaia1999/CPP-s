#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::InvalidNumberException::what() const throw()
{
	return "Invalid number (numbers must be positive integers)";
}

const char *PmergeMe::InvalidInputException::what() const throw()
{
	return "Invalid input";
}

const char *PmergeMe::EmptyInputException::what() const throw()
{
    return "Empty input";
}

bool PmergeMe::isValidNumber(long value) {
    if (value < 0 || value > std::numeric_limits<int>::max())
    {
        return false;
    }
    return true;
}

void PmergeMe::isValidInput(int argc, char** argv) {
    long value = 0;
    if (argc < 2) {
        throw EmptyInputException();
    }
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        if (!(iss >> value) || !iss.eof()) {
            throw InvalidInputException();
        }
        if (!isValidNumber(value)) {
            throw InvalidNumberException();
        }
        _vec.push_back(static_cast<int>(value));
        _deq.push_back(static_cast<int>(value));
    }
}

void PmergeMe::displayVector() const {
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
}