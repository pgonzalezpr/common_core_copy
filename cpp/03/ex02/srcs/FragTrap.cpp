#include "FragTrap.hpp"

#include <iostream>

using namespace std;

FragTrap::FragTrap() : ClapTrap("default", 100, 100, 30) {
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap " << _name << " created with copy constructor" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& other) {
    if (this == &other)
        return *this;
    this->_name = other.getName();
    this->_hitPoints = other.getHitPoints();
    this->_energyPoints = other.getEnergyPoints();
    this->_attackDamage = other.getAttackDamage();
    return *this;
}

void    FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " HIGH FIVE GUYS!" << std::endl;
}
