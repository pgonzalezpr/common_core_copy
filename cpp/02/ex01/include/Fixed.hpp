#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    static const int    _fractionalBits;
    int                 _value;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int value);
    Fixed(const float fValue);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int     getRawBits() const;
    void    setRawBits(int const raw);
    float   toFloat() const;
    int     toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif