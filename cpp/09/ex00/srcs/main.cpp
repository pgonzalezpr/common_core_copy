#include "BitcoinExchange.hpp"

bool validateInputFormat(const std::string& line) {
    size_t pos;

    pos = line.find(' ');
    if (pos == std::string::npos || pos + 2 >= line.size()
        || line[pos + 1] != '|' || line[pos + 2] != ' ')
        return false;
    pos += 3;
    if (line.find(' ', pos) != std::string::npos)
        return false;
    return true;
}

bool validateDate(const std::string& date) {

    size_t pos;
    size_t prev;
    unsigned int nbr;

    pos = date.find('-');
    if (pos == std::string::npos || pos + 1 >= date.size())
        return false;
    std::stringstream year(date.substr(0, pos));
    year >> nbr;
    if (year.fail() || !year.eof())
        return false;

    pos++;
    prev = pos;
    pos = date.find('-', pos);
    if (pos == std::string::npos || pos + 1 >= date.size())
        return false;
    std::stringstream month(date.substr(prev, pos - prev));
    month >> nbr;
    if (month.fail() || !month.eof() || nbr < 1 || nbr > 12)
        return false;

    pos++;
    std::stringstream day(date.substr(pos));
    day >> nbr;
    if (day.fail() || !day.eof() || nbr < 1 || nbr > 31)
        return false;
    return true;
}

float getFValue(const std::string& sValue) {

    float fValue;

    std::stringstream ss(sValue);
    ss >> fValue;
    if (ss.fail() || !ss.eof()) {
        std::cout << "Error: Bad value => " << sValue << std::endl;
        return -1;
    }
    if (fValue < 0) {
        std::cout << "Error: Not a positive value " << sValue << std::endl;
        return -1;
    }
    if (fValue > 1000) {
        std::cout << "Error: too large of a number: " << sValue << std::endl;
        return -1;
    }
    return fValue;
}

void run(std::ifstream& infile, BitcoinExchange& ex) {

    std::string line;
    std::string date;
    size_t pos;

    std::getline(infile, line);
    while (std::getline(infile, line)) {
        if (!validateInputFormat(line)) {
            std::cout << "Error: Bad input => " << line << std::endl;
            continue;
        }

        pos = line.find(' ');
        date = line.substr(0, pos);
        if (!validateDate(date)) {
            std::cout << "Error: Bad date => " << date << std::endl;
            continue;
        }

        pos += 3;
        float fValue = getFValue(line.substr(pos));
        if (fValue == -1)
            continue;
    
        std::cout << date << " => " << fValue << " = "
        << fValue * ex.getValue(date) << std::endl;
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "Incorrect number of arguments" << std::endl;
        return 1;
    }

    BitcoinExchange ex = BitcoinExchange();
    try {
        std::string file("data.csv");
        ex.init(file.c_str());
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::ifstream infile;
    infile.open(argv[1]);
    if (!infile.is_open()) {
        std::cerr << "Error opening " << argv[1] << " file" << std::endl;
        return 1;
    }

    run(infile, ex);
    infile.close();
}