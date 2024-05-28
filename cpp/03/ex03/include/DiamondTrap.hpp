#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

using namespace std;

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    string _name;
public:
    DiamondTrap();
    DiamondTrap(const string name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    void attack(const string& target);
    void whoAmI();
    string  getName() const;
};

#endif