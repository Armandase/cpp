#ifndef POINT_H
# define POINT_H

class Point{

public:
	Point();
	Point(const float x, const float y);
	~Point();
	Point& operator = (const Point& point);
};

#endif
