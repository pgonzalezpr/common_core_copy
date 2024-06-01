#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>

class ScavTrap : virtual public ClapTrap
{
protected:
    bool    guardState;
public:
    ScavTrap();
    ScavTrap(const std::string name);
    ScavTrap(const ScavTrap& other);
    virtual ~ScavTrap();
    ScavTrap&   operator=(const ScavTrap& other);

    void    attack(const std::string& target);
    void    guardGate();
    bool    getGuardState() const;
};

std::ostream	&operator<<(std::ostream &stream, ScavTrap &ScavTrap);

#endif
