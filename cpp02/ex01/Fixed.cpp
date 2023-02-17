#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

const int Fixed::_fract = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_int = 0;
}

Fixed::Fixed(const int param)
{
	std::cout << "Int constructor called" << std::endl;
	_int = param << _fract;
}

Fixed::Fixed(const float param)
{
	std::cout << "Float constructor called" << std::endl;
	_int = roundf(param * (1 << _fract));
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
	this->_int = fixed._int;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& data)
{
	os << data.toFloat();
	return (os);
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_int);
}

void	Fixed::setRawBits(const int nb)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_int = nb;
}

float	Fixed::toFloat(void) const
{
	return ((float)_int / (1 << _fract));
}

int	Fixed::toInt(void) const
{
	return ((_int >> _fract));
}
