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
	PmergeMe	calcul(av);
	PmergeMe	tmp(calcul);

	return (0);
}
