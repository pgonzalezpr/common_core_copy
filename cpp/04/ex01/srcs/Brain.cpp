#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    if (this == &other)
        return *this;
    for (size_t i = 0; i < SIZE; i++) {
        this->_ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdeaAtIndex(size_t idx) {
    if (idx < SIZE)
        return this->_ideas[idx];
    std::cout << "Invalid idea index" << std::endl;
    return "";
}

void    Brain::setIdeaAtIndex(std::string str, size_t idx) {
    if (idx < SIZE)
        this->_ideas[idx] = str;
}
