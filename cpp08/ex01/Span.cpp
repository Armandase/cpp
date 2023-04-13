#include "Span.hpp"
#include <stdexcept>

Span::Span(){
	_N = 0;
}

Span::Span(unsigned int N){
	_N = N;
}

Span::~Span(){
}

Span::Span(const Span &copy){
	*this = copy;
}

Span & Span::operator=(const Span &copy){
	if (this != &copy){
		this->_N = copy._N;
		this->_tab = copy._tab;
	}
	return (*this);
}

void	Span::addNumber(int nu){
	if (_tab.size() >= _N){
		throw std::logic_error("The Span if full");
	}
	_tab.push_back(nu);
}

int	Span::shortestSpan(){
	int	ret = 2147483647;
	if (_tab.size() <= 1){
		throw std::logic_error("There are not enough values");
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
	if (_tab.size() <= 1){
		throw std::logic_error("There are not enough values");
	}
	std::sort(_tab.begin(), _tab.end());
	ret = _tab.at(_tab.size() - 1) - _tab.at(0);
	return ret;
}

void	Span::addMultipleNumbers(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	while (it != ite)
	{
		if (_tab.size() >= _N)
			throw std::logic_error("Too many numbers to add inside tab\n");
		_tab.push_back(*it);
		it++;
	}
}
