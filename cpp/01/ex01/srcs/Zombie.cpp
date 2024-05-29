#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie(void) {
    std::cout << name
         << " died!"
         << std::endl;
}

void    Zombie::announce(void) {
    std::cout << name
         << ": "
         << ANNOUNCE_MSG
         << std::endl;
}
