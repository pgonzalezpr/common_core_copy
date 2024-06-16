#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits.h>

class ScalarConverter {
public:
    static void convert(const std::string& str);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static void printInt(int value);
    static void printDouble(double value);
};

#endif