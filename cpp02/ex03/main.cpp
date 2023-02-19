#include <iostream>
#include <iterator>
#include <ostream>
#include "Point.hpp"

/*
    c
	|\
	| \
	|  \
	|   \
	|    \
	|     \
	|      \  o
	|       \
	|  i     \
	|         \
   a|__________\b
*/
int main( void ) {
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(0, 10);
	Point	in(2, 3);
	Point	out(9, 5);
	Point	edge(5, 5);

	std::cout << "param : " << std::endl;
	std::cout << "  a(" << a.getX().toInt() << ";" << a.getY().toInt() << ")" << std::endl;
	std::cout << "  b(" << b.getX().toInt() << ";" << b.getY().toInt() << ")" << std::endl;
	std::cout << "  c(" << c.getX().toInt() << ";" << c.getY().toInt() << ")\n" << std::endl;
	std::cout << "  in(" << in.getX().toInt() << ";" << in.getY().toInt() << ")" << std::endl;
	std::cout << "  out(" << out.getX().toInt() << ";" << out.getY().toInt() << ")" << std::endl;
	std::cout << "  edge(" << edge.getX().toInt() << ";" << edge.getY().toInt() << ")" << std::endl;
	if (bsp(a, b, c, in))
		std::cout << "in is inside the triangle" << std::endl;
	else
		std::cout << "in is outside the triangle" << std::endl;
	if (bsp(a, b, c, out))
		std::cout << "out is inside the triangle" << std::endl;
	else
		std::cout << "out is outside the triangle" << std::endl;
	if (bsp(a, b, c, edge))
		std::cout << "edge is inside the triangle" << std::endl;
	else
		std::cout << "edge is outside the triangle" << std::endl;
	return 0;
}
