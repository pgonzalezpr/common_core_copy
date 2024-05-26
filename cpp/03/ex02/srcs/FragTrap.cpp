#include "FragTrap.hpp"

#include <iostream>

using namespace std;

FragTrap::FragTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    cout << "FragTrap default constructor called" << endl;
}

FragTrap::FragTrap(const string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
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
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

void    FragTrap::highFivesGuys(void) {
    cout << "FragTrap " << _name << " HIGH FIVE GUYS!" << endl;
}