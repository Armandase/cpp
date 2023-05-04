#include "RPN.hpp"
#include <exception>
#include <cstdlib>

RPN::RPN(){
	_result = 0;
	_input = "empty";
}

int	convert(std::string digit){
	long		tmp;
	char		*cmp;

	tmp = std::strtol(digit.c_str(), &cmp, 10);
	if (cmp == digit || tmp < 0 || tmp > 10){
		throw std::logic_error("RPN works only with digits");
	}
	return (static_cast<int>(tmp));
}

void	RPN::applyCalcul(std::string digit)
{
	std::string	op[4] = {"+", "-", "*", "/"};
	int	i;
	int	a;
	int	b;

	for (i = 0; i < 4; i++){
		if (op[i] == digit)
			break ;
	}
	if (_calcul.size() < 2)
		throw std::logic_error("The string given as parameter can't be use to a rpn");
	a = _calcul.top();
	_calcul.pop();
	b = _calcul.top();
	_calcul.pop();
	switch (i) {
		case 0:
			_calcul.push(b + a);
			break ;
		case 1:
			_calcul.push(b - a);
			break ;
		case 2:
			_calcul.push(b * a);
			break ;
		case 3:
			if (a == 0)
				throw std::logic_error("Can't divide by 0");
			_calcul.push(b / a);
			break ;
		default:
			throw std::logic_error("Calcul error with the string given as parameter");
	}
}

RPN::RPN(char *input){
	_input = input;
	size_t	pos = _input.find(" ");
	std::string digit;

	try {
		while (pos != std::string::npos)
		{
			digit = _input.substr(0, pos);
			if (digit >= "0" && digit <= "9")
				_calcul.push(convert(digit));
			else if (digit == "+" || digit == "-" || digit == "*" || digit == "/")
				applyCalcul(digit);
			else 
				throw std::logic_error(digit + " can't use in rpn format");
			_input.erase(0, pos + 1);
			pos = _input.find(" ");
		}
		digit = _input.substr(0, 2);
		if (digit >= "0" && digit <= "9")
			_calcul.push(convert(digit));
		else if (digit == "+" || digit == "-" || digit == "*" || digit == "/")
			applyCalcul(digit);
		else 
			throw std::logic_error(digit + " can't use in rpn format");
		_input.erase(0, 1);
		if (_input.length())
			throw std::logic_error("The string given as parameter can't be use to a rpn");
		_result = _calcul.top();
		_input = input;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		std::exit(1);
	}
}

RPN::~RPN(){
}

RPN::RPN(const RPN &copy){
	this->_result = copy._result;
	this->_calcul = copy._calcul;
}

RPN & RPN::operator=(const RPN &copy){
	this->_result = copy._result;
	this->_calcul = copy._calcul;
	return (*this);
}

void	RPN::printResult(){
	if (_calcul.size() != 1)
		throw std::logic_error("Too many numbers at the end of the calculation");
	std::cout << this->_input << " = " << _result << std::endl;
}
