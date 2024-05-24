#include "ClapTrap.hpp"

int main() {
    ClapTrap    red;
    ClapTrap    blue("blue");
    ClapTrap    green("green");

    blue.attack("red");
    blue.attack("green");
    green.takeDamage(3);
    green.takeDamage(10);
    green.attack("blue");
    blue.beRepaired(2);
    ClapTrap    black(blue);
    black.beRepaired(1);
    green.beRepaired(3);
}