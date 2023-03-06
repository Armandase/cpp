#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	_c = 0;
	_i = 0;
	_f = 0;
	_d = 0;
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	ScalarConverter::operator=(copy);
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &copy){
	_c = copy._c;
	_i = copy._i;
	_f = copy._f;
	_d = copy._d;
	return (*this);
}

void	convert(char *toConvert){

}
