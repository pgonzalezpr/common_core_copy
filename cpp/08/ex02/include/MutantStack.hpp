#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    
    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif