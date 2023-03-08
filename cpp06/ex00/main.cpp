#include <iostream>
#include <cstring>
#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "Too many parametres" << std::endl;
		return (1);
	} else if (!strlen(av[1])){
		std::cout << "Empty parametre" << std::endl;
		return (1);
	}

	ScalarConverter	convert(av[1]);

	convert.print();

	return (0);
}
