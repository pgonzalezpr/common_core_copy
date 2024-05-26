#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>

using namespace std;

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const string& name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();
    ScavTrap&   operator=(const ScavTrap& other);

    void    attack(const string& target);
    void    guardGate();
};

std::ostream	&operator<<(std::ostream &stream, ScavTrap &scavTrap);

#endif