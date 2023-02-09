#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	std::string	buf;
	PhoneBook	folder;

	std::cout << "\033[1;33m    Phone Book: \033[0m" << std::endl;
	for(;;){
		std::cout << "\033[1;36mADD | SEARCH | EXIT\033[0m" << std::endl;
		if (std::getline(std::cin.ignore('\0', '\n'), buf) == false)
			break ;
		if (buf == "ADD" || buf == "add")
			folder.Fill();
		else if (buf == "SEARCH" || buf == "search")
			folder.Search();
		else if (buf == "EXIT" || buf == "exit")
			folder.Exit();
		else
			std::cout << "Wrong command." << std::endl;
	}
}
