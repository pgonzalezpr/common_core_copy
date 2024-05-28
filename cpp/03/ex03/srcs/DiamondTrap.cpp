#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), 
    ScavTrap() {
        this-> _name = "default";
        this->ClapTrap::setHitPoints(100);
        this->ClapTrap::setEnergyPoints(50);
        this->ClapTrap::setAttackDamage(30);
        cout << "DiamondTrap default constructor called" << endl;
}

DiamondTrap::DiamondTrap(const string name) : ClapTrap(name + "_clap_name"), 
    FragTrap(name), ScavTrap(name) {
        this->_name = name;
        this->ClapTrap::setHitPoints(100);
        this->ClapTrap::setEnergyPoints(50);
        this->ClapTrap::setAttackDamage(30);     
        cout << "DiamondTrap " << _name << " constructor called" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
    ClapTrap(other.getName() + "_clap_name"), FragTrap(other.getName()),
        ScavTrap(other.getName()) {
            *this = other;
            cout << "DiamondTrap " << _name << " created with copy constructor" << endl;
}

DiamondTrap::~DiamondTrap() {
    cout << "DiamondTrap " << _name << " destructor called" << endl;
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

void DiamondTrap::attack(const string& target) {
    ScavTrap::attack(target);
}

std::ostream	&operator<<(std::ostream &stream, DiamondTrap &diamondTrap)
{
	stream << "Name: " << diamondTrap.ClapTrap::getName() << \
	" Hitpoints: " << diamondTrap.ClapTrap::getHitPoints() << \
	" Energy Points: " << diamondTrap.ClapTrap::getEnergyPoints() << \
	" Attack Damage: " << diamondTrap.ClapTrap::getAttackDamage();
	return (stream);
}

void	DiamondTrap::whoAmI(void) {
	cout << "Hello i am a DiamondTrap named " 
         << this->_name 
         << " and i am originated from the ClapTrap named " 
         << ClapTrap::getName() 
         << "." 
         << endl;
}

string  DiamondTrap::getName() const {  return this->_name; }


