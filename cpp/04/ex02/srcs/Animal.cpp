#include "Animal.hpp"

Animal::Animal() : _type("default") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    if (this == &other)
        return *this;
    this->_type = other.getType();
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const { return this->_type; }

void    Animal::setType(std::string& type) { this->_type = type; }