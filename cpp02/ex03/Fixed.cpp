#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

const int Fixed::_fract = 8;

Fixed::Fixed()
{
	_int = 0;
}

Fixed::Fixed(const int param)
{
	_int = param << _fract;
}

Fixed::Fixed(const float param)
{
	_int = roundf(param * (1 << _fract));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copy){
	Fixed::operator=(copy);
}

std::ostream& operator<<(std::ostream& os, const Fixed& data)
{
	os << data.toFloat();
	return (os);
}

int	Fixed::getRawBits(void) const{
	return (this->_int);
}

void	Fixed::setRawBits(const int nb)
{
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

Fixed& Fixed::operator=(const Fixed &fixed)
{
	this->_int = fixed._int;
	return *this;
}

bool Fixed::operator>(const Fixed& fixed)
{
	if (this->_int > fixed._int)	
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& fixed)
{
	if (this->_int < fixed._int)	
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& fixed)
{
	if (this->_int >= fixed._int)	
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& fixed)
{
	if (this->_int <= fixed._int)	
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& fixed)
{
	if (this->_int == fixed._int)	
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& fixed)
{
	if (this->_int != fixed._int)	
		return (true);
	return (false);
}

Fixed& Fixed::operator + (const Fixed& fixed)
{
	this->_int += fixed._int;
	return (*this);
}

Fixed& Fixed::operator - (const Fixed& fixed)
{
	this->_int -= fixed._int;
	return (*this);
}

Fixed& Fixed::operator * (const Fixed& fixed)
{
	this->_int = (toFloat() * fixed.toFloat()) * (1 << _fract);
	return (*this);
}

Fixed& Fixed::operator / (const Fixed& fixed)
{
	this->_int = (toFloat() / fixed.toFloat()) * (1 << _fract);
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed	ret = *this;
	_int++;
	return (ret);
}

Fixed& Fixed::operator ++ (void)
{
	_int++; 
	return (*this);
}

Fixed& Fixed::operator -- (void)
{
	_int--; 
	return (*this);
}

Fixed Fixed::operator -- (int)
{
	Fixed	ret = *this;
	_int--;
	return (ret);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (b < a)
		return (b);
	return (a);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	Fixed tmpA = a;
	Fixed tmpB = b;

	if (tmpB < tmpA)
		return (b);
	return (a);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (b > a)
		return (b);
	return (a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	Fixed tmpA = a;
	Fixed tmpB = b;

	if (tmpB > tmpA)
		return (b);
	return (a);
}
