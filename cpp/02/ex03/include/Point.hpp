#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed _x;
    const Fixed _y;
public:
    Point();
    Point(const Point& other);
    Point&  operator=(const Point& other);
    Point   operator-(const Point& other) const;
    ~Point();

    Point(const float x, const float y);

    const Fixed&  getX() const;
    const Fixed&  getY() const ;
};

#endif