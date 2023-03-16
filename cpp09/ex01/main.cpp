#include <iostream>
#include <string>
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)	
	{
		std::cout << "Wrong number of argument" << std::endl;
		return (0);
	}
	RPN	calcul(av[1]);
	RPN tmp(calcul);

	calcul.printResult();

	return (0);
}
