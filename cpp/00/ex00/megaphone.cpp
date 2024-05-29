#include <iostream>
#include <string>
#include <cctype>

using namespace std;

# define DEFAULT_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main (int argc, char *argv[]) {

  string str;

  if (argc == 1)
    cout << DEFAULT_MSG;
  for (int i = 1; i < argc; i++) {
    str = argv[i];
    for (string::size_type k = 0; k < str.length(); k++) {
      str[k] = toupper(static_cast<unsigned char>(str[k]));
    }
    cout << str;
  }
  cout << endl;
}