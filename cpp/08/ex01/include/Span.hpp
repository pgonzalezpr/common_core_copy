#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstdlib>
#include <ctime>

class Span {
private:
    typedef std::vector<int>::iterator iterator;
    Span();
    unsigned int _capacity;
    std::vector<int> _v;
    
    class InsufficientCapacityException : public std::exception {
    public:
        const char *what() const throw();
    };

    class InsufficientElementsException : public std::exception {
    public:
        const char *what() const throw();
    };
public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(int nbr);
    void addNumberRange(iterator start, iterator end);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    unsigned int size() const;
    void print();
};

#endif