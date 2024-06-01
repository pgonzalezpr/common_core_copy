#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) {
    *this = other;
}

Point::~Point() {}

Point&  Point::operator=(const Point& other) {
    if (this == &other)
        return *this;
    return *this;
}

Point   Point::operator-(const Point& other) const {
    Point   result((_x - other.getX()).toFloat(), (_y - other.getY()).toFloat());
    return result;
}

const Fixed&    Point::getX() const { return _x; }

const Fixed&    Point::getY() const { return _y; }
