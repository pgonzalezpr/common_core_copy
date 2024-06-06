#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this == &other)
        return *this;
    this->_type = other.getType();
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::makeSound() const {
    std::cout << "* WRONGANIMAL MAKES DEFAULT SOUND *" << std::endl;
}

std::string WrongAnimal::getType() const { return this->_type; }

void    WrongAnimal::setType(std::string& type) { this->_type = type; }