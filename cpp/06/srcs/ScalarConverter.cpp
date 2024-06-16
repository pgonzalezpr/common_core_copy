#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void) other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void) other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& input) {

    std::string str = input;

    if (handleSpecial(input))
        return;

    if (str.length() == 1 && !std::isdigit(str[0])) {
        printDouble(str[0]);
        return;
    }

    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
        printDouble(str[1]);
        return;
    }

    double d_value;
    if (str[str.length() - 1] == 'f')
        str = str.substr(0, str.length() - 1);
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

void ScalarConverter::printDouble(double value) {
    bool isInt;

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
    
    isInt = (value == (int) value);
    if (isInt)
        std::cout << std::fixed << std::setprecision(1);

    if (value < -FLT_MAX || value > FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else {
        std::cout << "float: " << value << "f" << std::endl;
    }
    std::cout << "double: " << value << std::endl;
}

bool ScalarConverter::handleSpecial(const std::string& str) {

    const char *specials[5] = {"-inff", "+inff", "-inf", "+inf", "nan"};
    bool contains = false;
    std::string f_msg;
    std::string d_msg;

    for (int i = 0; i < 5; i++) {
        if (str == specials[i]) {
            if (i == 0 || i == 2) {
                f_msg = specials[0];
                d_msg = specials[2];
            } else if (i == 1 || i == 3) {
                f_msg = specials[1];
                d_msg = specials[3];
            } else {
                f_msg = "nanf";
                d_msg = specials[4];
            }
            contains = true;
            break;
        }
    }

    if (contains) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f_msg << std::endl;
        std::cout << "double: " << d_msg << std::endl;
    }

    return contains;
}