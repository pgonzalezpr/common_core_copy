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
public:
    DiamondTrap();
    DiamondTrap(const string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    using ScavTrap::attack;
    void whoAmI() const;
};

std::ostream	&operator<<(std::ostream &stream, DiamondTrap &diamonTrap);

#endif