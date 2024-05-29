#include "Utils.hpp"

std::string  readField(const std::string& prompt) {
    std::string  field;

    field = "";
    while (!field.compare("")) {
        std::cout << prompt;
        getline(std::cin, field);
    }
    return field;
}   

bool    is_numeric(const std::string& str) {
    for (std::string::size_type k = 0; k < str.length(); k++) {
      if (!isdigit(str[k]))
        return 0;
    }
    return 1;
}

int stringToInt(const std::string& str) {
    int value;

    std::stringstream stream(str);
    stream >> value;
    if (stream.fail() || !stream.eof()) {
        std::cout << "Error parsing integer" << std::endl;
    }
    return value;
}
