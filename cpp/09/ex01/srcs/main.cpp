#include "RPN.hpp"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "Expected 1 argument" << std::endl;
        return 1;
    }

    std::string expr(argv[1]);
    if (!rpn(expr))
        std::cerr << "Error" << std::endl;
    return 0;
}