#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Fixed
{
private:
    static const int    _fractionalBits;
    int                 _value;
public:
    static Fixed& min(Fixed& first, Fixed& second);
    static Fixed& max(Fixed& first, Fixed& second);
    static const Fixed& min(const Fixed& first, const Fixed& second);
    static const Fixed& max(const Fixed& first, const Fixed& second);

    Fixed();
    Fixed(const Fixed& other);
    Fixed&  operator=(const Fixed& other);
    ~Fixed();
    
    Fixed(const int value);
    Fixed(const float fValue);

    bool    operator==(const Fixed& rhs) const;
    bool    operator<(const Fixed& rhs) const;
    bool    operator>(const Fixed& rhs) const; 
    bool    operator>=(const Fixed& rhs) const;
    bool    operator<=(const Fixed& rhs) const;
    bool    operator!=(const Fixed& rhs) const;

    Fixed   operator+(const Fixed& rhs) const;
    Fixed   operator-(const Fixed& rhs) const;
    Fixed   operator*(const Fixed& rhs) const;
    Fixed   operator/(const Fixed& rhs) const;

    Fixed&  operator++();
    Fixed   operator++(int);
    Fixed&  operator--();
    Fixed   operator--(int);

    int     getRawBits() const;
    void    setRawBits(int const raw);
    float   toFloat() const;
    int     toInt() const;
};

ostream& operator<<(ostream& os, const Fixed& obj);

#endif