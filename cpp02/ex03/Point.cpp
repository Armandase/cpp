#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void)
	:	_x(Fixed(0)),
		_y(Fixed(0))
{
}

Point::Point(const float x, const float y)
	:	_x(Fixed(x)),
		_y(Fixed(y))
{
}

Point::Point(const Point &copy){
	Point::operator=(copy);
}

Point& Point::operator=(const Point &point)
{
	this->~Point();
	new(this) Point(point.getX().toFloat(), point.getY().toFloat());
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
