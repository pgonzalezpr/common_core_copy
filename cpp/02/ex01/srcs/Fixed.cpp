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

Fixed::Fixed(const int value) {
    cout << "Int constructor called" << endl;
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float fValue) {
    cout << "Float constructor called" << endl;
    _value = static_cast<int>(roundf(fValue * (1 << _fractionalBits)));
}

Fixed::~Fixed() {
    cout << "Destructor called" << endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    cout << "Copy assignment operator called" << endl;
    if (this == &other)
        return *this;
    _value = other.getRawBits();
    return *this;
}

float   Fixed::toFloat() const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _value >> _fractionalBits;
}

int Fixed::getRawBits() const {
    return _value;
}

void    Fixed::setRawBits(int const raw) {
    _value = raw;
}

ostream& operator<<(ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}