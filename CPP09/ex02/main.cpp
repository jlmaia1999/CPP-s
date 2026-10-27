#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    try {
        PmergeMe pmergeMe;
        pmergeMe.isValidInput(argc, argv);
        pmergeMe.displayVector();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}