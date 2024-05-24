#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed   _x;
    Fixed   _y;
public:
    Point();
    Point(const Point& other);
    Point&  operator=(const Point& other);
    ~Point();

    Point(const float x, const float y);

    const Fixed&  getX() const;
    const Fixed&  getY() const ;
};

#endif