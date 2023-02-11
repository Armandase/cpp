#include <iostream>
#include "Harl.hpp"

void	Harl::_debug()
{
	std::cout << "The monkey tries to repair" << std::endl;
}

void	Harl::_info()
{
	std::cout << "The monkey has big muscles" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "The monkey detects a danger" << std::endl;
}

void	Harl::_error()
{
	std::cout << "The monkey fell into the void" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*tab[4])();
	int		index;

	tab[0] = &Harl::_debug;
	tab[1] = &Harl::_info;
	tab[2] = &Harl::_warning;
	tab[3] = &Harl::_error;
	
	if (level == "DEBUG")
		index = 0;
	else if (level == "INFO")
		index = 1;
	else if (level == "WARNING")
		index = 2;
	else if (level == "DANGER")
		index = 3;
	else
		index = -1;
	*(tab[index])();
}
