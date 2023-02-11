#include <iostream>
#include "Harl.hpp"

void	Harl::_debug()
{
	std::cout << "[ DEBUG  ]" << std::endl;
	std::cout << "The monkey tries to debug" << std::endl;
}

void	Harl::_info()
{
	std::cout << "[ INFO  ]" << std::endl;
	std::cout << "The monkey tries to get informations" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "[ WARNING  ]" << std::endl;
	std::cout << "The monkey gives a warning" << std::endl;
}

void	Harl::_error()
{
	std::cout << "[ ERROR  ]" << std::endl;
	std::cout << "The monkey is in danger" << std::endl;
}

void	defaultComplain(void){
	std::cout << "[ The monkey was waiting for something else ]" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*tab[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int		i;

	for (i = 0; i < 4; i++){
		if (level == levels[i])
			break ;
	}
	switch (i) {
		case 0:
			for (int j = i; j < 4; j++)
				(this->*tab[j])();
			break ;
		case 1:
			for (int j = i; j < 4; j++)
				(this->*tab[j])();
			break ;
		case 2:
			for (int j = i; j < 4; j++)
				(this->*tab[j])();
			break ;
		case 3:
			for (int j = i; j < 4; j++)
				(this->*tab[j])();
			break ;
		default:
			defaultComplain();
			break ;
	}
}
