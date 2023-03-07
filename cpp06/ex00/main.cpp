#include <iostream>
#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Too many parametres" << std::endl;

	ScalarConverter	convert(av[1]);

	return (0);
}
