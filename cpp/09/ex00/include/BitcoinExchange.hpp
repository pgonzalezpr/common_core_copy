#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

class BitcoinExchange {
public:

    class FileOpenErrorException : public std::exception {
    public:
        const char *what() const throw();
    };
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void init(const char *filename);
    float getValue(const std::string& date) const;
private:
    std::map<std::string, float> _data;
    typedef std::map<std::string, float>::const_iterator iterator;
};

#endif