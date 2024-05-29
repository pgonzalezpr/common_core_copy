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

bool    is_numeric(const string& str) {
    for (string::size_type k = 0; k < str.length(); k++) {
      if (!isdigit(str[k]))
        return 0;
    }
    return 1;
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
