#include "Fixed.hpp"
#include <iostream>
#include <cmath>


Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_int = 0;
}

Fixed::Fixed(const int param)
{
	std::cout << "Int constructor called" << std::endl;
	_int = param;
}

Fixed::Fixed(const float param)
{
	std::cout << "Float constructor called" << std::endl;
	_int = param;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator=(copy);
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_int = fixed.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_int);
}

void	Fixed::setRawBits(const int nb)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_int = nb;
}

float	Fixed::toFloat(void) const
{
	return (_int - roundf(_int));
}

int	Fixed::toInt(void) const
{
	return (roundf(_int));
}
