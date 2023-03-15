#include "BitcoinExchange.hpp"



int	main(int ac, char **av)
{
	BitcoinExchange	convert;
	if (ac != 2){
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	convert.getDataBase();
	convert.getInputFile(av[1]);
	return (0);
}
