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


void PmergeMe::sortVector() {
     if (_vec.size() < 2) {
        return;
    }

    std::vector<std::pair<int, int> > pairs;
    pairs.reserve(_vec.size() / 2);
    for (std::size_t index = 0; index + 1 < _vec.size(); index += 2) {
        int smaller = _vec[index];
        int larger = _vec[index + 1];
        if (larger < smaller) {
            std::swap(smaller, larger);
        }
        pairs.push_back(std::make_pair(smaller, larger));
    }

    const bool hasStraggler = _vec.size() % 2 != 0;
    const int straggler = hasStraggler ? _vec.back() : 0;

    std::vector<int> largerValues;
    largerValues.reserve(pairs.size());
    for (std::size_t index = 0; index < pairs.size(); ++index) {
        largerValues.push_back(pairs[index].second);
    }
    PmergeMe recursiveSort;
    recursiveSort._vec.swap(largerValues);
    recursiveSort.sortVector();
    largerValues.swap(recursiveSort._vec);

    std::vector<std::pair<int, int> > sortedPairs;
    std::vector<bool> used(pairs.size(), false);
    sortedPairs.reserve(pairs.size());
    for (std::size_t sortedIndex = 0; sortedIndex < largerValues.size();
         ++sortedIndex) {
        for (std::size_t pairIndex = 0; pairIndex < pairs.size(); ++pairIndex) {
            if (!used[pairIndex]
                && pairs[pairIndex].second == largerValues[sortedIndex]) {
                sortedPairs.push_back(pairs[pairIndex]);
                used[pairIndex] = true;
                break;
            }
        }
    }

    std::vector<int> chain;
    chain.reserve(_vec.size());
    if (!sortedPairs.empty()) {
        chain.push_back(sortedPairs[0].first);
        for (std::size_t index = 0; index < sortedPairs.size(); ++index) {
            chain.push_back(sortedPairs[index].second);
        }
    }

    const std::size_t largestPendingIndex = sortedPairs.size()
        + (hasStraggler ? 1 : 0);
    std::size_t previousJacobsthal = 1;
    std::size_t currentJacobsthal = 3;
    while (previousJacobsthal < largestPendingIndex) {
        const std::size_t end = currentJacobsthal < largestPendingIndex ? currentJacobsthal : largestPendingIndex;
        for (std::size_t pendingIndex = end;
             pendingIndex > previousJacobsthal; --pendingIndex) {
            if (pendingIndex <= sortedPairs.size()) {
                const int value = sortedPairs[pendingIndex - 1].first;
                std::vector<int>::iterator partner = std::lower_bound(
                    chain.begin(), chain.end(),
                    sortedPairs[pendingIndex - 1].second);
                std::vector<int>::iterator position = std::upper_bound(
                    chain.begin(), partner + 1, value);
                chain.insert(position, value);
            } else {
                std::vector<int>::iterator position = std::upper_bound(
                    chain.begin(), chain.end(), straggler);
                chain.insert(position, straggler);
            }
        }

        const std::size_t maxSize = static_cast<std::size_t>(-1);
        if (previousJacobsthal > (maxSize - currentJacobsthal) / 2) {
            previousJacobsthal = currentJacobsthal;
            currentJacobsthal = largestPendingIndex;
        } else {
            const std::size_t nextJacobsthal = currentJacobsthal
                + 2 * previousJacobsthal;
            previousJacobsthal = currentJacobsthal;
            currentJacobsthal = nextJacobsthal;
        }
    }

    _vec.swap(chain);
}

void PmergeMe::sortDeque() {
    if (_deq.size() < 2) {
        return;
    }

    std::deque<std::pair<int, int> > pairs;
    for (std::size_t index = 0; index + 1 < _deq.size(); index += 2) {
        int smaller = _deq[index];
        int larger = _deq[index + 1];
        if (larger < smaller) {
            std::swap(smaller, larger);
        }
        pairs.push_back(std::make_pair(smaller, larger));
    }

    const bool hasStraggler = _deq.size() % 2 != 0;
    const int straggler = hasStraggler ? _deq.back() : 0;

    std::deque<int> largerValues;
    for (std::size_t index = 0; index < pairs.size(); ++index) {
        largerValues.push_back(pairs[index].second);
    }
    PmergeMe recursiveSort;
    recursiveSort._deq.swap(largerValues);
    recursiveSort.sortDeque();
    largerValues.swap(recursiveSort._deq);

    std::deque<std::pair<int, int> > sortedPairs;
    std::deque<bool> used(pairs.size(), false);
    for (std::size_t sortedIndex = 0; sortedIndex < largerValues.size();
         ++sortedIndex) {
        for (std::size_t pairIndex = 0; pairIndex < pairs.size(); ++pairIndex) {
            if (!used[pairIndex]
                && pairs[pairIndex].second == largerValues[sortedIndex]) {
                sortedPairs.push_back(pairs[pairIndex]);
                used[pairIndex] = true;
                break;
            }
        }
    }

    std::deque<int> chain;
    if (!sortedPairs.empty()) {
        chain.push_back(sortedPairs[0].first);
        for (std::size_t index = 0; index < sortedPairs.size(); ++index) {
            chain.push_back(sortedPairs[index].second);
        }
    }

    const std::size_t largestPendingIndex = sortedPairs.size()
        + (hasStraggler ? 1 : 0);
    std::size_t previousJacobsthal = 1;
    std::size_t currentJacobsthal = 3;
    while (previousJacobsthal < largestPendingIndex) {
        const std::size_t end = currentJacobsthal < largestPendingIndex
            ? currentJacobsthal : largestPendingIndex;
        for (std::size_t pendingIndex = end;
             pendingIndex > previousJacobsthal; --pendingIndex) {
            if (pendingIndex <= sortedPairs.size()) {
                const int value = sortedPairs[pendingIndex - 1].first;
                std::deque<int>::iterator partner = std::lower_bound(
                    chain.begin(), chain.end(),
                    sortedPairs[pendingIndex - 1].second);
                std::deque<int>::iterator position = std::upper_bound(
                    chain.begin(), partner + 1, value);
                chain.insert(position, value);
            } else {
                std::deque<int>::iterator position = std::upper_bound(
                    chain.begin(), chain.end(), straggler);
                chain.insert(position, straggler);
            }
        }

        const std::size_t maxSize = static_cast<std::size_t>(-1);
        if (previousJacobsthal > (maxSize - currentJacobsthal) / 2) {
            previousJacobsthal = currentJacobsthal;
            currentJacobsthal = largestPendingIndex;
        } else {
            const std::size_t nextJacobsthal = currentJacobsthal
                + 2 * previousJacobsthal;
            previousJacobsthal = currentJacobsthal;
            currentJacobsthal = nextJacobsthal;
        }
    }

    _deq.swap(chain);
}