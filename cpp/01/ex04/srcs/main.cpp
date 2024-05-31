#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

#define ARGS_ERR "Invalid arguments"
#define OPEN_ERR "Error opening file"

void    error(std::string msg) {
    std::cerr << msg << std::endl;
    exit(EXIT_FAILURE);
}

std::string lineReplace(std::string &line, const std::string &s1, const std::string &s2) {
    std::size_t begin;
    std::size_t oldLen = s1.size();
    std::string newLine;

    while (1) {
        begin = line.find(s1);
        if (begin == std::string::npos)
            break;
        newLine += line.substr(0, begin) + s2;
        line.erase(0, begin + oldLen);
    }
    return (newLine + line + '\n');
}   

int main(int argc, char *argv[]) {

    std::string      line;
    std::string      processed;

    if (argc != 4 || !argv[2][0] || !argv[3][0])
        error(ARGS_ERR);

    std::ifstream    fileRead(argv[1]);
    if (!fileRead.is_open())
        error(OPEN_ERR);

    processed = "";
    while (std::getline(fileRead, line)) {
        processed += lineReplace(line, argv[2], argv[3]);
    }
    fileRead.close();

    std::ofstream    fileWrite(argv[1]);
    if (!fileWrite.is_open())
        error(OPEN_ERR);
    fileWrite << processed;
    fileWrite.close();

    return (0);
}
