#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <sstream>
# include <limits>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    class InvalidInputException : public std::exception {
        virtual const char* what() const throw();
    };

    class InvalidNumberException : public std::exception {
        virtual const char* what() const throw();
    };

    class EmptyInputException : public std::exception {
        virtual const char* what() const throw();
    };

    void isValidInput(int argc, char** argv);
    bool isValidNumber(long value);
    void displayVector() const;
    void sortVector(); // comment
    void sortDeque(); // comment
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
};

#endif