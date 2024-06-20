#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
public:
    class InvalidIndexException : public std::exception {
    public:
        const char *what() const throw ();
    };
    
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    T& operator[] (unsigned int index);
    unsigned int size() const;
    void print();
    ~Array();
private:
    T *_arr;
    unsigned int _size;
};

#include "Array.tpp"

#endif