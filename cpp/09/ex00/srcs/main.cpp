#include "BitcoinExchange.hpp"

int main() {
    BitcoinExchange ex = BitcoinExchange();
    try {
        std::string file("data.csv");
        ex.init(file.c_str());
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}