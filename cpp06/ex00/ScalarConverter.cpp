#include "ScalarConverter.hpp"
#include "stdlib.h"
#include <iostream>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	ScalarConverter::operator=(copy);
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &copy){
	return (*this);
}

ScalarConverter::ScalarConverter(char *string)
{
	findType(string);
}

void	ScalarConverter::convert(char *toConvert){

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
		if (str[i] < '0' || str[i] > '9'){
			return (false);
		}
	}
	return (true);
}

bool	ScalarConverter::isDouble(char *str){
	int	point = 0;;

	for (int i = 0; str[i]; i++){
		if (str[i] == '.')
			point++;
		if (((str[i] < '0' || str[i] > '9') && str[i] != '.') || point > 1){
			return (false);
		}
	}
	return (false);
}

bool	ScalarConverter::isFloat(char *str){
	int	point = 0;;

	for (int i = 0; str[i]; i++){
		if (str[i] == '.')
			point++;
		if (((str[i] < '0' || str[i] > '9') && str[i] != '.') || point > 1){
			return (false);
		}
	}
	return (false);
}
