#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {
    Ice();
    *this = other;    
}

Ice& Ice::operator=(const Ice& other) {
    if (this == &other)
        return *this;
    this->_type = other.getType();
    return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

