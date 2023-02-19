#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point{

public:
	Point();
	Point(const float x, const float y);
	Point(const Point& copy);
	~Point();
	Point&	operator = (const Point& point);
	Fixed	getX(void) const;
	Fixed	getY(void) const;
private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
