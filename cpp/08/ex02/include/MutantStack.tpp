#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
    if (this == other)
        return *this;
    this->c = other.c;
    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack() { this->c.clear(); }

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}