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
	void	(Harl::*tab[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "DANGER"};

	for (int i = 0; i < 4; i++){
		if (level == levels[i]){
			((*this).tab[i])();
			break ;
		}
	}
}
