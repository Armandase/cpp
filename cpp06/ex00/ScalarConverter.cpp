#include "ScalarConverter.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

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
	std::cout << "char :" << _c << std::endl;
	std::cout << "int :" << _i << std::endl;
	std::cout << "float :" << _f << std::endl;
	std::cout << "double :" << _d << std::endl;
}

void	ScalarConverter::convert(char *toConvert){
	if (isChar(toConvert))
	{
		_c = *toConvert;
		_i = static_cast<int>(_c);
		_f = static_cast<float>(_c);
		_d = static_cast<double>(_c);
	}
	if (isInt(toConvert))
	{
		long	tmp;
		char	*endPtr;

		tmp = std::strtol(toConvert, &endPtr, 10);
		if (endPtr == toConvert || tmp > 2147483647 || tmp < -2147483648)
			std::cout << "It's an overflow" << std::endl;
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
	if (isDouble(toConvert))
	{
		char	*endPtr;
		_d = std::strtod(toConvert, &endPtr);
		if (endPtr == toConvert)
			std::cout << "It's an overflow" << std::endl;
		else{
			if (_i > 255 || _i < 0)
				_c = -1;
			else
				_c = static_cast<char>(_i);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
		}
	}
	if (isFloat(toConvert))
	{
		char	*endPtr;
		_f = std::strtof(toConvert, &endPtr);
		if (endPtr == toConvert)
			std::cout << "It's an overflow" << std::endl;
	}
}

bool	ScalarConverter::isChar(char *str){
	if ((*str == '.' && !*(str + 1))
			|| (*str == 'f' && !*(str + 1))
			|| ((*str < '0' || *str > '9') && !*(str + 1))){
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isInt(char *str){
	for (int i = 0; str[i]; i++){
		if (str[i] == '-' && i == 0 && str[i + 1])
			continue ;
		if (str[i] < '0' || str[i] > '9'){
			return (false);
		}
	}
	return (true);
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
		return (true);
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
		return (true);
	return (false);
}
