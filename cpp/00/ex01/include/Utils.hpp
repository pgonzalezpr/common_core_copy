#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string  readField(const string& prompt);
int     stringToInt(const string& str);
bool    is_numeric(const string& str);

#endif
