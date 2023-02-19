#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void)
	:	_x(Fixed(0)),
		_y(Fixed(0))
{
}

Point::Point(const float xInit, const float yInit)
	:	_x(Fixed(xInit)),
		_y(Fixed(yInit))
{
}

Point::Point(const Point &copy){
	Point::operator=(copy);
}

Point& Point::operator=(const Point &point)
{
	(void)point;
	return (*this);
}

Point::~Point(){
	return ;
}

Fixed	Point::getX() const {
	return (_x);
}

Fixed	Point::getY() const {
	return (_y);
}
