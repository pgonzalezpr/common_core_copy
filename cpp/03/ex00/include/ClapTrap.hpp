#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

using namespace std;

class ClapTrap
{
private:
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
};

#endif