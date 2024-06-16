#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
   /*
   std::stringstream ss(argv[1]);
   double value;
   (void) argc;
   ss >> value;
   if (ss.fail() || !ss.eof()) {
    std::cout << "error" << std::endl;
    return 0;
   }
   std::cout << value << std::endl;
   */

}