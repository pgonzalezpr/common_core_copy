#include "Harl.hpp"

void    nonExistingTest() {
    Harl    harl;

    std::cout << "Non existing test:" << std::endl << std::endl;
    harl.complain("NONEXISTING");
    std::cout << std::endl;
}

void    randomOrderTest() {
    Harl    harl;

    std::cout << "Random order test:" << std::endl << std::endl;
    harl.complain("WARNING");
    harl.complain("INFO");
    harl.complain("ERROR");
    harl.complain("DEBUG");
    std::cout << std::endl;
}

void    simpleTest() {
    Harl    harl;

    std::cout << "Simple test:" << std::endl << std::endl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    std::cout << std::endl;
}

int main(void) {
    simpleTest();
    randomOrderTest();
    nonExistingTest();
}
