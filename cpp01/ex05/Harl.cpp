#include <iostream>
#include "Harl.hpp"

void	Harl::_debug()
{
	std::cout << "The monkey tries to debug" << std::endl;
}

void	Harl::_info()
{
	std::cout << "The monkey tries to get informations" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "The monkey gives a warning" << std::endl;
}

void	Harl::_error()
{
	std::cout << "The monkey is in danger" << std::endl;
}

void	defaultComplain(void){
	std::cout << "The monkey was waiting for something else" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*tab[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++){
		if (level == levels[i]){
			(this->*tab[i])();
			return ;
		}
	}
	defaultComplain();
}
