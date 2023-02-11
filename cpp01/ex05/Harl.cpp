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
<<<<<<< HEAD
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
=======
	void	(Harl::*tab[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++){
		if (level == levels[i]){
			(this->*tab[i])();
			return ;
		}
	}
	defaultComplain();
>>>>>>> f7bce103a478daa02cd1b34de086c94da0dd8e80
}
