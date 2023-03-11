#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	 public:
		Span();
		Span(unsigned int N);
		~Span();
		Span (const Span &copy);
		Span &operator=(const Span&);
		void	addNumber(int nu);
		void	addMultipleNumbers(unsigned nbToAdd, int value);
		int		shortestSpan();
		int		longestSpan();
	 private:
		unsigned int _stored;
		unsigned int _N;
		std::vector<int>	_tab;
		
};

#endif
