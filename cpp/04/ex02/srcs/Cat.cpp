#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain =  new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    if (this == &other)
        return *this;
    this->_type = other.getType();
    *this->_brain = *other.getBrain();
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete(this->_brain);
}

void    Cat::makeSound() const {
    std::cout << "MEOW! MEOW!" << std::endl;
}

Brain   *Cat::getBrain() const { return this->_brain; }