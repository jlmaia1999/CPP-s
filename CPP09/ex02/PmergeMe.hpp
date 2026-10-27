#ifndef "PMERGEME_HPP"
#define "PMERGEME_HPP"

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
};

#endif