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
	_special = -1;
	_str = "\0";
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	ScalarConverter::operator=(copy);
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &copy){
	_c = copy._c;
	_d = copy._d;
	_f = copy._f;
	_i = copy._i;
	_special = copy._special;
	_str = copy._str;
	return (*this);
}

ScalarConverter::ScalarConverter(char *string)
{
	int	i = 0;

	_special = -1;
	std::string tab[6] = {"nanf", "+inff", "-inff", "nan", "+inf", "-inf"};
	for (int i = 0; i < 6; i++){
		if (tab[i] == string){
			_str = tab[i];
			_special = i;
			break ;
		}
	}
	if (_special == -1){
		i += isChar(string);
		i += isInt(string);
		i += isDouble(string);
		i += isFloat(string);
		if (i == 4){
			std::cout << "Your input isn't a char/int/float/double" << std::endl;
			std::exit(1);
		}
	}
}

void	ScalarConverter::print(){
	if (_special == -1){
		if (std::isprint(_c) == 0)
			std::cout << "char: " << "Non displayable" << std::endl;
		else
			std::cout << "char: " << _c << std::endl;
		if (_d > 2147483647 || _d < -2147483648)
			std::cout << "int: " << "Overflow" << std::endl;
		else
			std::cout << "int: " << _i << std::endl;
		if (_f - roundf(_f) > 0)
			std::cout << "float: " << _f << "f" << std::endl;
		else
			std::cout << std::setprecision(1) << std::fixed << "float: " << _f << "f" << std::endl;
		if (_d - round(_d) > 0)
			std::cout << "double: " << _d << std::endl;
		else
			std::cout << std::setprecision(1) << std::fixed << "double: " << _d << std::endl;
	} else {
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		if (_special > 2){
			std::cout << "float: " << _str << "f" << std::endl;
			std::cout << "double: " << _str << std::endl;
		} else {
			std::cout << "float: " << _str << std::endl;
			std::string tmp = _str;
			tmp = tmp.substr(0, (tmp.length()-1));
			std::cout << "double: " << tmp << std::endl;
		}
	}
}

bool	ScalarConverter::isChar(char *str){
	if ((*str == '.' && !*(str + 1))
			|| (*str == 'f' && !*(str + 1))
			|| ((*str < '0' || *str > '9') && !*(str + 1))){
		{
			_c = *str;
			_i = static_cast<int>(_c);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
			return (0);
		}
	}
	return (1);
}

bool	ScalarConverter::isInt(char *str){
	for (int i = 0; str[i]; i++){
		if (str[i] == '-' && i == 0 && str[i + 1])
			continue ;
		if (str[i] < '0' || str[i] > '9'){
			return (1);
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
	return (0);
}

bool	ScalarConverter::isDouble(char *str){
	int	point = 0;

	for (int i = 0; str[i]; i++){
		if (str[i] == '-' && i == 0 && str[i + 1])
			continue ;
		if (str[i] == '.')
			point++;
		if (((str[i] < '0' || str[i] > '9') && str[i] != '.') || point > 1){
			return (1);
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
		return (0);
	}
	return (1);
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
			return (1);
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
		return (0);
	}
	return (1);
}
