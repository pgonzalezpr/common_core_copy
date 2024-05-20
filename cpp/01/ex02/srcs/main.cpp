#include <iostream>

using namespace std;

int main(void) {

    string  str = "HI THIS IS BRAIN";
    string  *stringPTR = &str;
    string& stringREF = str;

    cout << "String variable address: " << &str << endl;
    cout << "Address held by stringPTR: " << stringPTR << endl;
    cout << "Address held by stringREF: " << &stringREF << endl;
    cout << endl;
    cout << "String variable value: " << str << endl;
    cout << "Value pointed to by stringPTR: " << *stringPTR << endl;
    cout << "Value pointed to by stringREF: " << stringREF << endl;
}