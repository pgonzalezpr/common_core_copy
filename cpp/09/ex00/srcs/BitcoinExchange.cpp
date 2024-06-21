#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this == &other)
        return *this;
    this->_data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() { this->_data.clear(); }

void BitcoinExchange::init(const char *filename) {
    std::ifstream infile;
    std::string line;
    size_t pos;
    float value;

    infile.open(filename);
    if (!infile.is_open())
        throw FileReadErrorException();
    std::getline(infile, line);
    while (std::getline(infile, line)) {
        pos = line.find(',');
        std::stringstream(line.substr(pos + 1)) >> value;
        this->_data.insert(std::make_pair(line.substr(0, pos), value));
    }
    infile.close();
    for (std::map<std::string, float>::iterator it = this->_data.begin(); it != this->_data.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value = " << it->second << std::endl;
    }
}

const char *BitcoinExchange::FileReadErrorException::what() const throw() {
    return "Error reading file";;
}



