#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() {
    _value = 0;
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed::Fixed(const int value) {
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float fValue) {
    _value = static_cast<int>(roundf(fValue * (1 << _fractionalBits)));
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this == &other)
        return *this;
    _value = other.getRawBits();
    return *this;
}

bool    Fixed::operator==(const Fixed& rhs) const {
    return _value == rhs.getRawBits();
}

bool    Fixed::operator>(const Fixed& rhs) const {
    return _value > rhs.getRawBits();
}

bool    Fixed::operator<(const Fixed& rhs) const {
    return _value < rhs.getRawBits();
}

bool    Fixed::operator<=(const Fixed& rhs) const {
    return _value <= rhs.getRawBits();
}

bool    Fixed::operator>=(const Fixed& rhs) const {
    return _value >= rhs.getRawBits();
}

bool    Fixed::operator!=(const Fixed& rhs) const {
    return _value != rhs.getRawBits();
}

Fixed   Fixed::operator+(const Fixed& rhs) const {
    Fixed   result;
    
    result.setRawBits(_value + rhs.getRawBits());
    return result;
}

Fixed   Fixed::operator-(const Fixed& rhs) const {
    Fixed   result;
    
    result.setRawBits(_value - rhs.getRawBits());
    return result;
}

Fixed   Fixed::operator*(const Fixed& rhs) const {
    Fixed   result;

    result.setRawBits((_value * rhs.getRawBits())
        / (1 << _fractionalBits));
    return result;
}

Fixed   Fixed::operator/(const Fixed& rhs) const {
    Fixed   result;

    result.setRawBits(static_cast<int>(roundf((_value << _fractionalBits)
        / static_cast<float>(rhs.getRawBits()))));
    return result;
}

Fixed&  Fixed::operator++() {
    _value++;
    return *this;
}

Fixed   Fixed::operator++(int) {
    Fixed   old = *this;
    operator++();
    return old;
}


Fixed&  Fixed::operator--() {
    _value--;
    return *this;
}

Fixed   Fixed::operator--(int) {
    Fixed   old = *this;
    operator--();
    return old;
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

Fixed&  Fixed::min(Fixed& first, Fixed& second) {
    return (first <= second) ? first : second;
}

Fixed&  Fixed::max(Fixed& first, Fixed& second) {
    return (first >= second) ? first : second;
}

const Fixed&    Fixed::min(const Fixed& first, const Fixed& second) {
    return (first <= second) ? first : second;
}

const Fixed&    Fixed::max(const Fixed& first, const Fixed& second) {
    return (first >= second) ? first : second;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
