#include "BitcoinExchange.hpp"
#include <exception>



int	main(int ac, char **av)
{
	BitcoinExchange	convert;
	if (ac != 2){
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try {
		convert.getDataBase();
		convert.getInputFile(av[1]);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
