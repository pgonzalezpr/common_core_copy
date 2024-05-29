#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    this->_name = "default";
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) {
    this->_name = name;
    this->_hitPoints = hitPoints;
    this->_energyPoints = energyPoints;
    this->_attackDamage = attackDamage;
    std::cout << "ClapTrap " << _name << " inheritance constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap " << _name << " created with copy constructor" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& other) {
    if (this == &other)
        return *this;
    this->_name = other.getName();
    this->_hitPoints = other.getHitPoints();
    this->_energyPoints = other.getHitPoints();
    this->_attackDamage = other.getAttackDamage();
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
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target) {
    if (isDead() || hasNoEnergy())
        return;
    this->_energyPoints--;
    std::cout << "ClapTrap "
        << _name
        << " attacks "
        << target
        << ", causing "
        << _attackDamage
        << " points of damage"
        << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    unsigned int    damage;

    if (isDead())
        return;
    damage = amount;
    if (this->_hitPoints < amount)
        damage = this->_hitPoints;
    this->_hitPoints -= damage;
    std::cout << "ClapTrap "
        << this->_name
        << " takes "
        << damage
        << " points of damage"
        << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (isDead() || hasNoEnergy())
        return;
    this->_hitPoints += amount;
    this->_energyPoints--;
    std::cout << "ClapTrap "
        << this->_name
        << " is repaired, receiving "
        << amount
        << " hit points"
        << std::endl;
}

bool    ClapTrap::isDead() { return this->_hitPoints == 0; }

bool    ClapTrap::hasNoEnergy() { return this->_energyPoints == 0; }

std::string          ClapTrap::getName() const { return this->_name; }
unsigned int    ClapTrap::getHitPoints() const { return this->_hitPoints; }
unsigned int    ClapTrap::getEnergyPoints() const { return this->_energyPoints; }
unsigned int    ClapTrap::getAttackDamage() const { return this->_attackDamage; }

void    ClapTrap::setName(std::string name) { this->_name = name; }
void    ClapTrap::setHitPoints(unsigned int hitPoints) { this->_hitPoints = hitPoints; }
void    ClapTrap::setEnergyPoints(unsigned int energyPoints) { this->_energyPoints = energyPoints; }
void    ClapTrap::setAttackDamage(unsigned int attackDamage) { this->_attackDamage = attackDamage; }
