#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstring>

template<typename T>
void iter(T *arr, int size, void (*fun)(T&));

template<typename T>
void printArr(T *arr, int size);

template<typename T>
void triple(T& a);

#endif