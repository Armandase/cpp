#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	exemple;

	for (int i = 1; i < ac; i++)
	{
		exemple.complain(av[i]);
	}
	return (0);
}
