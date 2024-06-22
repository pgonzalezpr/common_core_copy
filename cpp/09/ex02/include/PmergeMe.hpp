#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

template <typename Container>
class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    typedef typename Container::iterator iterator;
    void fordJohnsonSort(Container& elements);
private:
    Container _c;
};

#include "PmergeMe.tpp"

#endif