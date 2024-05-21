#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

#define ARGS_ERR "Invalid number of arguments"
#define OPEN_ERR "Error opening file"

using namespace std;

void    error(string msg) {
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

void    lineReplace(string &line, const string &s1, const string &s2) {
    string  newLine;
    string  token;
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

    ifstream    fileRead(argv[1]);
    string      line;
    string      processed;

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
    ofstream    fileWrite(argv[1]);
    if (!fileWrite.is_open())
        error(OPEN_ERR);
    fileWrite << processed;
    fileWrite.close();
    return (0);
}