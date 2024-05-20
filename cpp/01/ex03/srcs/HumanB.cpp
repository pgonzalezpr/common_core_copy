#include "HumanB.hpp"

HumanB::HumanB(const string &name) : name(name) {
    weapon = NULL;
}

void    HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void    HumanB::attack() const {
    if (!weapon)
        return ;
    cout << name
         << " attacks with their "
         << (*weapon).getType()
         << endl;
}



