#include "Utils.hpp"

string  readField(const string& prompt) {
    string  field;

    field = "";
    while (!field.compare("")) {
        cout << prompt;
        getline(cin, field);
    }
    return field;
}   

int stringToInt(const string& str) {
    int value;

    stringstream stream(str);
    stream >> value;
    if (stream.fail() || !stream.eof()) {
        cout << "Error parsing integer" << endl;
    }
    return value;
}
