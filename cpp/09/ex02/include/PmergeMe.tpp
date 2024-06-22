#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& other) { *this = other; }

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& other) {
    if (this == &other)
        return *this;
    this->_c = other._c;
    return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() { this->_c.clear(); }

template <typename Container>
void PmergeMe<Container>::fordJohnsonSort(Container& elements) {
    if (elements.size() <= 1)
        return;
    
    Container smaller, larger;
    for (iterator it = elements.begin(); it != elements.end(); ++it) {
        iterator next = it;
        std::advance(next, 1);
        if (next == elements.end()) {
            smaller.push_back(*it);
            break;
        }
        if (*it < *next) {
            smaller.push_back(*it);
            larger.push_back(*next);
        } else {
            smaller.push_back(*next);
            larger.push_back(*it);
        }
        ++it;
    }

    this->fordJohnsonSort(smaller);
    this->fordJohnsonSort(larger);

    iterator it1 = smaller.begin();
    iterator it2 = larger.begin();
    iterator out = elements.begin();

    while (it1 != smaller.end() && it2 != larger.end()) {
        if (*it1 < *it2) {
            *out++ = *it1++;
        } else {
            *out++ = *it2++;
        }
    }
    while (it1 != smaller.end()) {
        *out++ = *it1++;
    }
    while (it2 != larger.end()) {
        *out++ = *it2++;
    }
}