#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {}

Point::~Point() {}

Point&  Point::operator=(const Point& other) {
    (void) other;
    return *this;
}

Point   Point::operator-(const Point& other) const {
    Point   result((_x - other.getX()).toFloat(), (_y - other.getY()).toFloat());
    return result;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.getX().toFloat() << ", " << point.getY().toFloat() << ")";
    return os;
}

const Fixed&    Point::getX() const { return _x; }

const Fixed&    Point::getY() const { return _y; }
