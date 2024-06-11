#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other.getType()) {}

AMateria&   AMateria::operator=(const AMateria& other) {
    (void) other;
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return this->_type; }

void AMateria::use(ICharacter& target) { (void) target; }
