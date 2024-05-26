#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

using namespace std;

class ClapTrap
{
protected:
    string          _name;
    unsigned int    _hitPoints;
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;

    bool    isDead();
    bool    hasNoEnergy();
public:
    ClapTrap();
    ClapTrap(const string& name);
    ClapTrap(const ClapTrap& other);
    ~ClapTrap();
    ClapTrap&   operator=(const ClapTrap& other);

    void    attack(const string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    string& getName();
    unsigned int    getHitPoints();
    unsigned int    getEnergyPoints();
    unsigned int    getAttackDamage();

};

std::ostream	&operator<<(std::ostream &stream, ClapTrap &clapTrap);

#endif