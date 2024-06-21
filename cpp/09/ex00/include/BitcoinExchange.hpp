#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

class BitcoinExchange {
public:

    class FileReadErrorException : public std::exception {
    public:
        const char *what() const throw();
    };
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void init(const char *filename);
    //float getTotalValue(const std::string& date, int amount) const;
private:
    std::map<std::string, float> _data;
};

#endif