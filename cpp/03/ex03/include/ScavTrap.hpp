#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>

using namespace std;

class ScavTrap : virtual public ClapTrap
{
protected:
    bool    guardState;
public:
    ScavTrap();
    ScavTrap(const string name);
    ScavTrap(const ScavTrap& other);
    virtual ~ScavTrap();
    ScavTrap&   operator=(const ScavTrap& other);

    void    attack(const string& target);
    void    guardGate();
    bool    getGuardState() const;
};

#endif