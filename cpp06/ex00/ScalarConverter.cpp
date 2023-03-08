#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter(){
	_c = 0;
	_d = 0;
	_i = 0;
	_f = 0;
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	ScalarConverter::operator=(copy);
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &copy){
	(void)copy;
	return (*this);
}

ScalarConverter::ScalarConverter(char *string)
{
	convert(string);
	if (_c == -1 || std::isprint(_c) == 0)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << _c << std::endl;
	if (_d > 2147483647 || _d < -2147483648)
		std::cout << "int: " << "Overflow" << std::endl;
	else
		std::cout << "int: " << _i << std::endl;
	if (_f - roundl(_f) > 0)
		std::cout << "float: " << _f << "f" << std::endl;
	else
		std::cout << std::setprecision(1) << std::fixed << "float: " << _f << "f" << std::endl;
	if (_d - roundl(_d) > 0)
		std::cout << "double: " << _d << std::endl;
	else
		std::cout << std::setprecision(1) << std::fixed << "double: " << _d << std::endl;
}

void	ScalarConverter::convert(char *toConvert){
	isChar(toConvert);
	isInt(toConvert);
	isDouble(toConvert);
	isFloat(toConvert);
}

void	ScalarConverter::isChar(char *str){
	if ((*str == '.' && !*(str + 1))
			|| (*str == 'f' && !*(str + 1))
			|| ((*str < '0' || *str > '9') && !*(str + 1))){
		{
			_c = *str;
			_i = static_cast<int>(_c);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
		}
	}
}

void	ScalarConverter::isInt(char *str){
	for (int i = 0; str[i]; i++){
		if (str[i] == '-' && i == 0 && str[i + 1])
			continue ;
		if (str[i] < '0' || str[i] > '9'){
			return ;
		}
	}
	long	tmp;
	char	*endPtr;

	tmp = std::strtol(str, &endPtr, 10);
	if (endPtr == str || tmp > 2147483647 || tmp < -2147483648)
	{
		std::cout << "It's an overflow" << std::endl;
		std::exit(0);
	}
	else{
		_i = static_cast<int>(tmp);
		if (_i > 255 || _i < 0)
			_c = -1;
		else
			_c = static_cast<char>(_i);
		_f = static_cast<float>(_i);
		_d = static_cast<double>(_i);
	}
}

bool	ScalarConverter::isDouble(char *str){
	int	point = 0;

	for (int i = 0; str[i]; i++){
		if (str[i] == '-' && i == 0 && str[i + 1])
			continue ;
		if (str[i] == '.')
			point++;
		if (((str[i] < '0' || str[i] > '9') && str[i] != '.') || point > 1){
			return (false);
		}
	}
	if (point == 1)
	{
		char	*endPtr;
		_d = std::strtod(str, &endPtr);
		if (endPtr == str)
			std::cout << "It's an overflow" << std::endl;
		else{
			if (_d > 255 || _d < 0)
				_c = -1;
			else
				_c = static_cast<char>(_d);
			if (_d > 2147483647 || _d < -2147483648)
				_i = 0;
			else
				_i = static_cast<int>(_d);
			_f = static_cast<float>(_d);
		}
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isFloat(char *str){
	int	point = 0;
	int	i;

	for (i = 0; str[i + 1]; i++){
		if (str[i] == '-' && i == 0 && str[i + 1])
			continue ;
		if (str[i] == '.')
			point++;
		if (((str[i] < '0' || str[i] > '9') && str[i] != '.') || point > 1){
			return (false);
		}
	}
	if (str[i] == 'f' && std::strlen(str) > 1)
	{
		char	*endPtr;
		_f = std::strtof(str, &endPtr);
		if (endPtr == str)
			std::cout << "It's an overflow" << std::endl;
		else{
			if (_f > 255 || _f < 0)
				_c = -1;
			else
				_c = static_cast<char>(_f);
			if (_f > 2147483647.0 || _f < -2147483648.0)
				_i = 0;
			else
				_i = static_cast<int>(_f);
			_d = static_cast<double>(_f);
		}
		return (true);
	}
	return (false);
}
