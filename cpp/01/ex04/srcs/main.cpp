#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

#define ARGS_ERR "Invalid number of arguments"
#define OPEN_ERR "Error opening file"

void    error(std::string msg) {
    std::cerr << msg << std::endl;
    exit(EXIT_FAILURE);
}

void    lineReplace(std::string &line, const std::string &s1, const std::string &s2) {
    std::string  newLine;
    std::string  token;
    char    c;
    bool    inToken;

    inToken = false;
    for (size_t i = 0; i < line.size(); i++) {
        c = line[i];
        if (isspace(c)) {
            if (inToken && !token.compare(s1)) {
                token = s2;
            }
            if (inToken)
            {
                newLine += token;
                token.clear();
                inToken = false;
            }
            newLine += c;
        }
        else {
            token += c;
            inToken = true;
        }
    }
    if (inToken) {
        if (!token.compare(s1))
            token = s2;
        newLine += token;
    }
    line = newLine += '\n';
}

int main(int argc, char *argv[]) {

    std::ifstream    fileRead(argv[1]);
    std::string      line;
    std::string      processed;

    if (argc != 4)
        error(ARGS_ERR);
    if (!fileRead.is_open())
        error(OPEN_ERR);
    processed = "";
    while (getline(fileRead, line)) {
        lineReplace(line, argv[2], argv[3]);
        processed += line;
    }
    fileRead.close();
    std::ofstream    fileWrite(argv[1]);
    if (!fileWrite.is_open())
        error(OPEN_ERR);
    fileWrite << processed;
    fileWrite.close();
    return (0);
}
