#include "FragTrap.hpp"

#include <iostream>

using namespace std;

FragTrap::FragTrap() : ClapTrap("default", 100, 100, 30) {
    cout << "FragTrap default constructor called" << endl;
}

FragTrap::FragTrap(const string name) : ClapTrap(name, 100, 100, 30) {
    cout << "FragTrap " << _name << " constructor called" << endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    *this = other;
    cout << "FragTrap " << _name << " created with copy constructor" << endl;
}

FragTrap::~FragTrap() {
    cout << "FragTrap " << _name << " destructor called" << endl;
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
    cout << "FragTrap " << _name << " HIGH FIVE GUYS!" << endl;
}