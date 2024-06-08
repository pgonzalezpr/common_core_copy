#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain();
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    if (this == &other)
        return *this;
    this->_type = other.getType();
    *(this->_brain) = *(other.getBrain());
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete(this->_brain);
}

void    Dog::makeSound() const {
    std::cout << "WOOF! WOOF!" << std::endl;
}

Brain   *Dog::getBrain() const { return this->_brain; }