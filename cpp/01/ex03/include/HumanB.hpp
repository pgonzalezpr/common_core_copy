#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

using namespace std;

class HumanB {
public:
    HumanB(const string &name);
    void    attack() const;
    void    setWeapon(Weapon &weapon);
private:
    string  name;
    Weapon  *weapon;
};

#endif