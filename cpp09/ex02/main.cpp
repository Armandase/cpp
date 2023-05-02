#include <cctype>
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
		for (int i = 0; av[i]; i++)
			for (int j = 0; av[i][j]; j++)
				if (isdigit(av[i][j]) == false)
					throw std::logic_error("just numbers");
		PmergeMe	calcul(av);
		PmergeMe	tmp(calcul);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
