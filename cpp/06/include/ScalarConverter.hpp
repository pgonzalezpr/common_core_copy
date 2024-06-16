#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits.h>
#include <cfloat>

class ScalarConverter {
public:
    static void convert(const std::string& str);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static void printDouble(double value);
    static bool handleSpecial(const std::string& str);
};

#endif