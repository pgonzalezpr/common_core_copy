#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() {
    cout << "Default constructor called" << endl;
    _value = 0;
}

Fixed::Fixed(const Fixed& other) {
    cout << "Copy constructor called" << endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    cout << "Copy assignment operator called" << endl;
    if (this == &other)
        return *this;
    _value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    cout << "Destructor called" << endl;
}

int Fixed::getRawBits() const {
    cout << "getRawBits member function called" << endl;
    return _value;
}

void    Fixed::setRawBits(int const raw) {
    cout << "setRawBits member function called" << endl;
    _value = raw;
}