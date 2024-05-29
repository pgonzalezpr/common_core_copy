#include <iostream>
#include <string>
#include <cctype>

# define DEFAULT_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main (int argc, char *argv[]) {

  std::string str;

  if (argc == 1)
    std::cout << DEFAULT_MSG;
  for (int i = 1; i < argc; i++) {
    str = argv[i];
    for (std::string::size_type k = 0; k < str.length(); k++) {
      str[k] = toupper(static_cast<unsigned char>(str[k]));
    }
    std::cout << str;
  }
  std::cout << std::endl;
}