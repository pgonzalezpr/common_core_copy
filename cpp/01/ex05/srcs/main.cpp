#include "Harl.hpp"

void    nonExistingTest() {
    Harl    harl;

    cout << "Non existing test:" << endl << endl;
    harl.complain("NONEXISTING");
    cout << endl;
}

void    randomOrderTest() {
    Harl    harl;

    cout << "Random order test:" << endl << endl;
    harl.complain("WARNING");
    harl.complain("INFO");
    harl.complain("ERROR");
    harl.complain("DEBUG");
    cout << endl;
}

void    simpleTest() {
    Harl    harl;

    cout << "Simple test:" << endl << endl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    cout << endl;
}

int main(void) {
    simpleTest();
    randomOrderTest();
    nonExistingTest();
}