#ifndef ARRAY_TPP
#define ARRAY_HPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) {
    this->_arr = new T[n];
    for (unsigned int i = 0; i < n; i++) {
        new (&_arr[i]) T();
    }
    this->_size = n;
}

template <typename T>
Array<T>::Array(const Array& other) : _arr(NULL), _size(0) {
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other)
        return *this;

    delete[] this->_arr;

    this->_size = other._size;
    this->_arr = (this->_size > 0) ? new T[this->_size] : NULL;

    for (unsigned int i = 0; i < this->_size; i++) {
        this->_arr[i] = other._arr[i];
    }

    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= this->_size)
        throw std::exception();
    return this->_arr[index];
}

template <typename T>
void Array<T>::print() {
    std::cout << "Size: " << this->_size << ", [ ";
    for (unsigned int i = 0; i < this->_size; i++) {
        std::cout << this->_arr[i] << " ";
    }
    std::cout << "]"<< std::endl;
}

template <typename T>
unsigned int Array<T>::size() const { return this->_size; }

template <typename T>
Array<T>::~Array() {
    if (this->_arr)
        delete[] this->_arr;
}

#endif