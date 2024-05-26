#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default") , _hitPoints(10), _energyPoints(0),
        _attackDamage(0) {
            cout << "ClapTrap default constructor called" << endl;
}

ClapTrap::ClapTrap(const string& name) : _name(name) , _hitPoints(10),
    _energyPoints(10), _attackDamage(0) {
        cout << "ClapTrap " << _name << " constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    cout << "ClapTrap " << _name << " created with copy constructor" << endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& other) {
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

std::ostream	&operator<<(std::ostream &stream, ClapTrap &clapTrap)
{
	stream << "Name: " << clapTrap.getName() << \
	" Hitpoints: " << clapTrap.getHitPoints() << \
	" Energy Points: " << clapTrap.getEnergyPoints() << \
	" Attack Damage: " << clapTrap.getAttackDamage();
	return (stream);
}

ClapTrap::~ClapTrap() {
    cout << "ClapTrap " << _name << " destructor called" << endl;
}

void    ClapTrap::attack(const string& target) {
    if (isDead() || hasNoEnergy())
        return;
    _energyPoints--;
    cout << "ClapTrap "
        << _name
        << " attacks "
        << target
        << ", causing "
        << _attackDamage
        << " points of damage"
        << endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    unsigned int    damage;

    if (isDead())
        return;
    damage = amount;
    if (_hitPoints < amount)
        damage = _hitPoints;
    _hitPoints -= damage;
    cout << "ClapTrap "
        << _name
        << " takes "
        << damage
        << " points of damage"
        << endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (isDead() || hasNoEnergy())
        return;
    _hitPoints += amount;
    _energyPoints--;
    cout << "ClapTrap "
        << _name
        << " is repaired, receiving "
        << amount
        << " hit points"
        << endl;
}

bool    ClapTrap::isDead() { return _hitPoints == 0; }

bool    ClapTrap::hasNoEnergy() { return _energyPoints == 0; }

string&         ClapTrap::getName() { return _name; }
unsigned int    ClapTrap::getHitPoints() { return _hitPoints; }
unsigned int    ClapTrap::getEnergyPoints() { return _energyPoints; }
unsigned int    ClapTrap::getAttackDamage() { return _attackDamage; }