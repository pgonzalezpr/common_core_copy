#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), 
    ScavTrap() {
        this-> _name = "default";
        this->ClapTrap::setHitPoints(100);
        this->ClapTrap::setEnergyPoints(50);
        this->ClapTrap::setAttackDamage(30);
        std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), 
    FragTrap(name), ScavTrap(name) {
        this->_name = name;
        this->ClapTrap::setHitPoints(100);
        this->ClapTrap::setEnergyPoints(50);
        this->ClapTrap::setAttackDamage(30);     
        std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
    ClapTrap(other.getName() + "_clap_name"), FragTrap(other.getName()),
        ScavTrap(other.getName()) {
            *this = other;
            std::cout << "DiamondTrap " << _name << " created with copy constructor" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}
    
DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& other) {
    if (this == &other)
        return *this;
    this->_name = other.getName();
    this->ClapTrap::setName(other.getName() + "_clap_name");
    this->_hitPoints = other.getHitPoints();
    this->_energyPoints = other.getEnergyPoints();
    this->_attackDamage = other.getAttackDamage();
    
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

std::ostream	&operator<<(std::ostream &stream, DiamondTrap &diamondTrap)
{
	stream << "Name: " << diamondTrap.ClapTrap::getName() << \
	" Hitpoints: " << diamondTrap.ClapTrap::getHitPoints() << \
	" Energy Points: " << diamondTrap.ClapTrap::getEnergyPoints() << \
	" Energy Points: " << diamondTrap.ClapTrap::getEnergyPoints() << \
	" Attack Damage: " << diamondTrap.ClapTrap::getAttackDamage() << \
    " Guard State: " << diamondTrap.ScavTrap::getGuardState();
	return (stream);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "Hello i am a DiamondTrap named " 
         << this->_name 
         << " and i am originated from the ClapTrap named " 
         << ClapTrap::getName() 
         << "." 
         << std::endl;
}

std::string  DiamondTrap::getName() const {  return this->_name; }


