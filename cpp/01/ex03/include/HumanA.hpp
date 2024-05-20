#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

using namespace std;

class HumanA {
public:
    HumanA(const string &name, Weapon &weapon);
    void    attack() const;
private:
    string  name;
    Weapon  &weapon;
};

#endif