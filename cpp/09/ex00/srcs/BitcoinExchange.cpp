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
        throw FileOpenErrorException();
    std::getline(infile, line);
    while (std::getline(infile, line)) {
        pos = line.find(',');
        std::stringstream(line.substr(pos + 1)) >> value;
        this->_data.insert(std::make_pair(line.substr(0, pos), value));
    }
    infile.close();
}

const char *BitcoinExchange::FileOpenErrorException::what() const throw() {
    return "Error opening bitcoin database file";;
}

float BitcoinExchange::getValue(const std::string& date) const {
    BitcoinExchange::iterator it = this->_data.lower_bound(date);
    if (it->first == date)
        return it->second;
    if (it != this->_data.begin())
        return (--it)->second;
    return (++it)->second;
}
