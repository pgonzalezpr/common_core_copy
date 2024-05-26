#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_trap"), FragTrap(),
    ScavTrap() {
        _name = "default";
        _hitPoints = FragTrap::_hitPoints;
        _energyPoints = ScavTrap::_energyPoints;
        _attackDamage = FragTrap::_attackDamage;
        cout << "DiamondTrap default constructor called" << endl;
}

DiamondTrap::DiamondTrap(const string& name) : ClapTrap(name + "_clap_trap"),
    FragTrap(), ScavTrap() {
        _name = name;
        _hitPoints = FragTrap::_hitPoints;
        _energyPoints = ScavTrap::_energyPoints;
        _attackDamage = FragTrap::_attackDamage;        
        cout << "DiamondTrap " << _name << " constructor called" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other),
    FragTrap(other), ScavTrap(other) {
        *this = other;
        cout << "DiamondTrap " << _name << " created with copy constructor" << endl;
}

DiamondTrap::~DiamondTrap() {
    cout << "DiamondTrap " << _name << " destructor called" << endl;
}
    
DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& other) {
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

std::ostream	&operator<<(std::ostream &stream, DiamondTrap &diamondTrap)
{
	stream << "Name: " << diamondTrap.getName() << \
	" Hitpoints: " << diamondTrap.getHitPoints() << \
	" Energy Points: " << diamondTrap.getEnergyPoints() << \
	" Attack Damage: " << diamondTrap.getAttackDamage();
	return (stream);
}

void	DiamondTrap::whoAmI(void) const {
	cout << "Hello i am a DiamondTrap named " 
         << this->_name 
         << " and i am originated from the ClapTrap named " 
         << ClapTrap::_name 
         << "." 
         << endl;
}


