#include "Span.hpp"
#include <exception>

void	own_test(){
	std::vector<int> test;

	test.push_back(10);
	test.push_back(20);
	test.push_back(30);
	test.push_back(40);
	test.push_back(50);
	test.push_back(60);
	Span sp = Span(7);
	
	try{
		sp.addMultipleNumbers(test.begin(), test.end());
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	try{
		sp.addMultipleNumbers(test.begin(), test.end());
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	{
		Span ap = Span(100000000);
		try{
			for (int i = 0; i < 1000; i++)
				ap.addMultipleNumbers(test.begin(), test.end());
		} catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
		try {
			ap.addNumber(5);
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
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
