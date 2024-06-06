#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat default constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this == &other)
        return *this;
    this->_type = other.getType();
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound() const {
    std::cout << "WRONG MEOW! WRONG MEOW!" << std::endl;
}