#include <iostream>
#include <ostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	std::cout << a.getX() << std::endl;
	Fixed area = (Fixed(0.5f) * (a.getX() * (c.getY() - b.getY()) + c.getX() * (b.getY() - a.getY()) + b.getX() * (a.getY() - c.getY())));
	Fixed areaABP = (Fixed(0.5f) * (a.getX() * (point.getY() - b.getY()) + point.getX() * (b.getY() - a.getY()) + b.getX() * (a.getY() - point.getY())));
	Fixed areaAPC = (Fixed(0.5f) * (a.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - c.getY())));
	Fixed areaPBC = (Fixed(0.5f) * (point.getX() * (c.getY() - b.getY()) + c.getX() * (b.getY() - point.getY()) + b.getX() * (point.getY() - c.getY())));
	if (areaABP + areaAPC + areaPBC == area)
		return (true);
	else
		return (false);

}

int main( void ) {
	Point	a(2, 4);	
	Point	b(1, 1);	
	Point	c(6, 1);	
	Point	p(1, 3);	
	std::cout << a.getX() << std::endl;
	if (bsp(a, b, c, p))
		std::cout << "inside" << std::endl;
	else
		std::cout << "outside" << std::endl;
	return 0;
}
