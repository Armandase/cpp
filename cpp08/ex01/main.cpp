#include "Span.hpp"

void	own_test(){
	Span sp = Span(70);
	
	try{
		sp.addMultipleNumbers(7000, -7000);
	} catch (const char * err){
		std::cout << err << std::endl;
	}
	try{
		sp.addMultipleNumbers(4, 7000);
	} catch (const char * err){
		std::cout << err << std::endl;
	}
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	{
		Span ap = Span(100000000);
		try{
			ap.addMultipleNumbers(1000000, 424242);
		} catch (const char * err){
			std::cout << err << std::endl;
		}
		ap.addNumber(5);
		std::cout << "shortest span: " << ap.shortestSpan() << std::endl;
		std::cout << "longest span: " << ap.longestSpan() << std::endl;
	}
}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	own_test();
	return 0;
}
