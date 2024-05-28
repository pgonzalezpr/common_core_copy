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
    ClapTrap(string name);
    ClapTrap(string name, unsigned int hitPoints, unsigned int energyPoints,
        unsigned int attackDamage);
    ClapTrap(const ClapTrap& other);
    virtual ~ClapTrap();
    ClapTrap&   operator=(const ClapTrap& other);

    void    attack(const string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    virtual string  getName() const;
    unsigned int    getHitPoints() const;
    unsigned int    getEnergyPoints() const;
    unsigned int    getAttackDamage() const;

    void    setName(string name);
    void    setHitPoints(unsigned int hitPoints);
    void    setEnergyPoints(unsigned int energyPoints);
    void    setAttackDamage(unsigned int attackDamage);
};

std::ostream	&operator<<(std::ostream &stream, ClapTrap &clapTrap);

#endif