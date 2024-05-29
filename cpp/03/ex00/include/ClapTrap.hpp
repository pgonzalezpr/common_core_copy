#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string          _name;
    unsigned int    _hitPoints;
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;

    bool    isDead();
    bool    hasNoEnergy();
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints,
        unsigned int attackDamage);
    ClapTrap(const ClapTrap& other);
    virtual ~ClapTrap();
    ClapTrap&   operator=(const ClapTrap& other);

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    virtual std::string  getName() const;
    unsigned int    getHitPoints() const;
    unsigned int    getEnergyPoints() const;
    unsigned int    getAttackDamage() const;

    void    setName(std::string name);
    void    setHitPoints(unsigned int hitPoints);
    void    setEnergyPoints(unsigned int energyPoints);
    void    setAttackDamage(unsigned int attackDamage);
};

std::ostream	&operator<<(std::ostream &stream, ClapTrap &clapTrap);

#endif
