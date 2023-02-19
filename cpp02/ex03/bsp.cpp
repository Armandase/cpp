# include "Point.hpp"

Fixed	abs(float to_check)
{
	if (to_check < 0)
		return (Fixed(-to_check));
	return (Fixed(to_check));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area = (Fixed(0.5f) * (a.getX() * (c.getY() - b.getY()) + c.getX() * (b.getY() - a.getY()) + b.getX() * (a.getY() - c.getY())));
	Fixed areaABP = (Fixed(0.5f) * (a.getX() * (point.getY() - b.getY()) + point.getX() * (b.getY() - a.getY()) + b.getX() * (a.getY() - point.getY())));
	Fixed areaAPC = (Fixed(0.5f) * (a.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - c.getY())));
	Fixed areaPBC = (Fixed(0.5f) * (point.getX() * (c.getY() - b.getY()) + c.getX() * (b.getY() - point.getY()) + b.getX() * (point.getY() - c.getY())));
	if (abs(areaABP.toFloat()) + abs(areaAPC.toFloat()) + abs(areaPBC.toFloat()) == abs(area.toFloat())
		&& areaABP.toFloat() != 0 && areaAPC.toFloat() != 0 && areaPBC.toFloat() != 0)
		return (true);
	else
		return (false);

}
