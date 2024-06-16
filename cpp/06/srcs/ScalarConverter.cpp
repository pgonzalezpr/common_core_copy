#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void) other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void) other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& str) {

    if (str.length() == 1 && !std::isdigit(str[0])) {
        printInt(str[0]);
        return;
    }

    std::stringstream int_stream(str);
    int int_value;
    int_stream >> int_value;
    if (!int_stream.fail() && int_stream.eof()) {
        std::cout << "hello" << std::endl;
        printInt(int_value);
        return;
    }

    float f_value;
    std::stringstream f_stream(str);
    if (str[str.length() - 1] == 'f') {
       std::stringstream f_stream(str.substr(0, str.length() - 1));
       f_stream >> f_value;
       if (!f_stream.fail() && f_stream.eof()) { 
        printDouble(f_value);
        return;
       }
    }

    double d_value;
    std::stringstream d_stream(str);
    d_stream >> d_value;
    if (!d_stream.fail() && d_stream.eof()) {
        printDouble(d_value);
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printInt(int value) {
    if (value < 0 || value > 127)
        std::cout << "char: " << "impossible" << std::endl;
    else if (value < 32 || value > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << value << ".0f" << std::endl;
    std::cout << "double: " << value << ".0" << std::endl;
}

void ScalarConverter::printDouble(double value) {
    if (value < 0 || value > 127)
        std::cout << "char: " << "impossible" << std::endl;
    else if (value < 32 || value > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << static_cast<char>(value) << "'" << std::endl;
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}



