#include <iostream>
#include <ostream>
#include "Fixed.hpp"

void	personnal_test()
{
	std::cout << std::endl << "! PERSONNAL TESTS !" << std::endl;
	Fixed a(5.05f);
	Fixed b(2);
	Fixed aa = a;
	std::cout << "a = " << a << " b = " << b << " aa = " << aa << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "a == b --> bool = " << (a == b) << std::endl;
	std::cout << "a == aa --> bool = " << (a == aa) << std::endl;
	std::cout << "a != b --> bool = " << (a != b) << std::endl;
	std::cout << "a != aa --> bool = " << (a != aa) << std::endl;
	std::cout << "a > b --> bool = " << (a > b) << std::endl;
	std::cout << "a > aa --> bool = " << (a > aa) << std::endl;
	std::cout << "a >= b --> bool = " << (a >= b) << std::endl;
	std::cout << "a >= aa --> bool = " << (a >= aa) << std::endl;
	std::cout << "a < b --> bool = " << (a < b) << std::endl;
	std::cout << "a < aa --> bool = " << (a < aa) << std::endl;
	std::cout << "a <= b --> bool = " << (a <= b) << std::endl;
	std::cout << "a <= aa --> bool = " << (a <= aa) << std::endl;
	std::cout << "a * b --> " << (a * b) << std::endl;
	std::cout << "a / b --> " << (a / b) << std::endl;
	std::cout << "a + b --> " << (a + b) << std::endl;
	std::cout << "a - b --> " << (a - b) << std::endl;
	std::cout << "before : a++ --> a = " << (a++) << " after a = " << a << std::endl;
	std::cout << "before : a-- --> a = " << (a--) << " after a = " << a << std::endl;
	std::cout << "before : ++a --> a = " << a << " after a = " << (++a) << std::endl;
	std::cout << "before : --a --> a = " << a << " after a = " << (--a) << std::endl;
	std::cout << "max between a & b --> " << Fixed::max(a, b) << std::endl;
	std::cout << "min between a & b --> " << Fixed::min(a, b) << std::endl;
	Fixed const aConst(5.05f);
	Fixed const bConst(2);
	std::cout << "max between const a & const b --> " << Fixed::max(a, b) << std::endl;
	std::cout << "min between const a & const b --> " << Fixed::min(a, b) << std::endl;
}

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	personnal_test();
	return 0;
}
