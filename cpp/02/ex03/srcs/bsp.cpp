#include "Fixed.hpp"
#include "Point.hpp"

float   dot(const Point& a, const Point& b) {
    return ((a.getX() * b.getX()).toFloat() + (a.getY() * b.getY()).toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Point   edge1 = b - a;
    Point   edge2 = c - b;
    Point   edge3 = a - c;

    Point   normal1(edge1.getY().toFloat(), -edge1.getX().toFloat());
    Point   normal2(edge2.getY().toFloat(), -edge2.getX().toFloat());
    Point   normal3(edge3.getY().toFloat(), -edge3.getX().toFloat());

    Point   vector1((point.getX() - a.getX()).toFloat(),
        (point.getY() - a.getY()).toFloat());
    Point   vector2((point.getX() - b.getX()).toFloat(),
        (point.getY() - b.getY()).toFloat());
    Point   vector3((point.getX() - c.getX()).toFloat(),
        (point.getY() - c.getY()).toFloat());
    
    float   dot1 = dot(normal1, vector1);
    float   dot2 = dot(normal2, vector2);
    float   dot3 = dot(normal3, vector3);

    return ((dot1 >= 0 && dot2 >= 0 && dot3 >= 0)
        || (dot1 <= 0 && dot2 <= 0 && dot3 <= 0));
}

void    test(Point const a, Point const b, Point const c, Point const point) {
    if (bsp(a, b, c, point))
        std::cout << "Point " << point << " is inside triangle "
                  << a << ", " << b << ", " << c << std::endl;
    else
        std::cout << "Point " << point << " is not inside triangle "
                  << a << ", " << b << ", " << c << std::endl;
}

int main() {
    Point   a(0, 0);
    Point   b(5, 0);
    Point   c(2.5, 5);

    Point   point1(2.5, 3);
    Point   point2(5,0);
    Point   point3(8,5);

    float	area = a.getX().toFloat() * (b.getY() - c.getY()).toFloat()
				+ b.getX().toFloat() * (c.getY() - a.getY()).toFloat()
				+ c.getX().toFloat() * (a.getY() - b.getY()).toFloat();

    if (area == 0)
		return (std::cerr << "Error: Invalid triangle" << std::endl, 1);
    
    test(a, b, c, point1);
    test(a, c, b, point1);
    test(b, a, c, point1);

    std::cout << std::endl;

    test(b, c, a, point2);
    test(c, a, b, point2);
    test(c, b, a, point2);

    std::cout << std::endl;

    test(a, b, c, point3);
    test(c, a, b, point3);
    test(b, a, c, point3);
}
