#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(const std::string name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI();
    std::string  getName() const;
};

std::ostream	&operator<<(std::ostream &stream, DiamondTrap &diamondTrap);

#endif
