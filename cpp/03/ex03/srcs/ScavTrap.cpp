#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    cout << "ScavTrap default constructor called" << endl;
}

ScavTrap::ScavTrap(const string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    cout << "ScavTrap " << _name << " constructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    *this = other;
    cout << "ScavTrap " << _name << " created with copy constructor" << endl;
}

ScavTrap::~ScavTrap() {
    cout << "ScavTrap " << _name << " destructor called" << endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& other) {
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

std::ostream	&operator<<(std::ostream &stream, ScavTrap &scavTrap)
{
	stream << "Name: " << scavTrap.getName() << \
	" Hitpoints: " << scavTrap.getHitPoints() << \
	" Energy Points: " << scavTrap.getEnergyPoints() << \
	" Attack Damage: " << scavTrap.getAttackDamage();
	return (stream);
}

void    ScavTrap::attack(const string& target) {
    if (isDead() || hasNoEnergy())
        return;
    cout << "ScavTrap "
        << _name
        << " attacks "
        << target
        << ", causing "
        << _attackDamage
        << " points of damage"
        << endl;
    _energyPoints--;
}

void    ScavTrap::guardGate() {
    if (!isDead())
        return;
    cout << "ScavTrap "
        << _name
        << " has entered gatekeeper mode "
        << endl;
    _energyPoints--;   
}