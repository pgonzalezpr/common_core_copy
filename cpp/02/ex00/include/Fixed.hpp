#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    static const int    _fractionalBits;
    int                 _value;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int     getRawBits() const;
    void    setRawBits(int const raw);
};

#endif