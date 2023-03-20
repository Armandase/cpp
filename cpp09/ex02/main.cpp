#include <exception>
#include <iostream>
#include <string>
#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)	
	{
		std::cout << "Wrong number of argument" << std::endl;
		return (0);
	}
	av++;
	try {
		PmergeMe	calcul(av);
		PmergeMe	tmp(calcul);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
