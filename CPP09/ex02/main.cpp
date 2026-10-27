#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    try {
        PmergeMe pmergeMe;
        pmergeMe.isValidInput(argc, argv);
        std::cout << "Before: ";
        pmergeMe.displayVector();

        std::clock_t vectorStart = std::clock();
        pmergeMe.sortVector();
        std::clock_t vectorEnd = std::clock();

        std::clock_t dequeStart = std::clock();
        pmergeMe.sortDeque();
        std::clock_t dequeEnd = std::clock();

        std::cout << "After: ";
        pmergeMe.displayVector();
        const double vectorMicroseconds =
            static_cast<double>(vectorEnd - vectorStart) * 1000000.0
            / CLOCKS_PER_SEC;
        const double dequeMicroseconds =
            static_cast<double>(dequeEnd - dequeStart) * 1000000.0
            / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << argc - 1
                  << " elements with std::vector: " << vectorMicroseconds
                  << " us" << std::endl;
        std::cout << "Time to process a range of " << argc - 1
                  << " elements with std::deque: " << dequeMicroseconds
                  << " us" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}