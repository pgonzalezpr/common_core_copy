#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20) {
    this->guardState = false;
    cout << "ScavTrap default constructor called" << endl;
}

ScavTrap::ScavTrap(const string name) : ClapTrap(name, 100, 50, 20) {
    this->guardState = false;
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
    this->_name = other.getName();
    this->_hitPoints = other.getHitPoints();
    this->_energyPoints = other.getEnergyPoints();
    this->_attackDamage = other.getAttackDamage();
    this->guardState = other.getGuardState();
    return *this;
}

void    ScavTrap::attack(const string& target) {
    if (isDead() || hasNoEnergy())
        return;
    cout << "ScavTrap "
        << this->_name
        << " attacks "
        << target
        << ", causing "
        << this->_attackDamage
        << " points of damage"
        << endl;
    this->_energyPoints--;
}

void    ScavTrap::guardGate() {
    if (!isDead())
        return;
    cout << "ScavTrap "
        << this->_name
        << " has entered gatekeeper mode "
        << endl;
    this->_energyPoints--;   
}

bool    ScavTrap::getGuardState() const { return this->guardState; }