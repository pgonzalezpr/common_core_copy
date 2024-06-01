#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20) {
    this->guardState = false;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {
    this->guardState = false;
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    *this = other;
    std::cout << "ScavTrap " << _name << " created with copy constructor" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
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

void    ScavTrap::attack(const std::string& target) {
    if (isDead() || hasNoEnergy())
        return;
    std::cout << "ScavTrap "
        << this->_name
        << " attacks "
        << target
        << ", causing "
        << this->_attackDamage
        << " points of damage"
        << std::endl;
    this->_energyPoints--;
}

void    ScavTrap::guardGate() {
    if (isDead())
        return;
    this->guardState = 1;
    std::cout << "ScavTrap "
        << this->_name
        << " has entered gatekeeper mode "
        << std::endl;
    this->_energyPoints--;   
}

bool    ScavTrap::getGuardState() const { return this->guardState; }
