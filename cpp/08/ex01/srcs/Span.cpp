#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : _capacity(n) {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    this->_capacity = other._capacity;
    this->_v = other._v;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int nbr) {
    if (this->_v.size() >= this->_capacity)
        throw InsufficientCapacityException();
    this->_v.push_back(nbr);
}

void Span::addNumberRange(iterator start, iterator end) {
    if (this->_v.size() + std::distance(start, end) > this->_capacity)
        throw InsufficientCapacityException();
    this->_v.insert(this->_v.end(), start, end);
}

unsigned int Span::shortestSpan() const {
    if (this->_v.size() < 2)
        throw Span::InsufficientElementsException();
    std::vector<int> sorted = this->_v;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = INT_MAX;
    int currentSpan;
    for (iterator it = sorted.begin(); it != sorted.end() - 1; ++it) {
        currentSpan = *(it + 1) - *it;
        if (currentSpan == 0)
            return 0;
        if (currentSpan < minSpan)
            minSpan = currentSpan;
    }
    return (unsigned int) minSpan;
}

unsigned int Span::longestSpan() const {
    if (this->_v.size() < 2)
        throw Span::InsufficientElementsException();
    return (*(std::max_element(this->_v.begin(), this->_v.end()))
    - *(std::min_element(this->_v.begin(), this->_v.end())));
}

void Span::print() {
    std::cout << "Size: " << this->_v.size() << ", [ ";
    for (iterator it = this->_v.begin(); it != this->_v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

unsigned int Span::size() const { return this->_v.size(); }

const char *Span::InsufficientCapacityException::what() const throw() {
    return "Span does not have enough capacity to add elements";
}

const char *Span::InsufficientElementsException::what() const throw() {
    return "Span does not have enough stored elements to get a valid span";
}