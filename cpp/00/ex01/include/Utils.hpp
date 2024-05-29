#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <sstream>

std::string readField(const std::string& prompt);
int     stringToInt(const std::string& str);
bool    is_numeric(const std::string& str);

#endif
