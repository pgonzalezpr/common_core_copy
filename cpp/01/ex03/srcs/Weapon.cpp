#include "Weapon.hpp"

Weapon::Weapon(const string &type) : type(type) {}

const string    &Weapon::getType() const {
    const string &ref = type;
    return ref;
}

void    Weapon::setType(const string &newType) {
    type = newType;
}