#include "Span.hpp"

Span::Span(){
	_N = 0;
	_stored = 0;
}

Span::Span(unsigned int N){
	_N = N;
	_stored = 0;
}

Span::~Span(){
}

Span::Span(const Span &copy){
	Span::operator=(copy);
}

Span & Span::operator=(const Span &copy){
	this->_stored = copy._stored;
	this->_N = copy._N;
	this->_tab = copy._tab;
	return (*this);
}

void	Span::addNumber(int nu){
	if (_stored >= _N){
		throw "The Span if full";
	}
	_tab.push_back(nu);
	_stored ++;
}

int	Span::shortestSpan(){
	int	ret = 2147483647;
	if (_stored <= 1){
		throw "There are not enough values";
	}
	std::sort(_tab.begin(), _tab.end());
	for(std::vector<int>::iterator it = _tab.begin(); it + 1 != _tab.end(); ++it){
		if (*(it + 1) - (*it) < ret){
			ret = *(it + 1) - (*it);
		}
	}
	return ret;
}

int	Span::longestSpan(){
	int	ret = 0;
	if (_stored <= 1){
		throw "There are not enough values";
	}
	std::sort(_tab.begin(), _tab.end());
	ret = _tab.at(_tab.size() - 1) - _tab.at(0);
	return ret;
}

void	Span::addMultipleNumbers(unsigned int nbToAdd, int value)
{
	if (nbToAdd >= _N - _stored){
		throw "Wrong parametres";
	}
	_tab.insert(_tab.end(), nbToAdd, value);
	_stored += nbToAdd;
}
