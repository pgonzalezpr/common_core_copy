#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(string name) : name(name) {}

Zombie::~Zombie(void) {
    cout << name
         << " died!"
         << endl;
}

void    Zombie::announce(void) {
    cout << name
         << ": "
         << ANNOUNCE_MSG
         << endl;
}