#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	std::string	buf;
	PhoneBook	folder;

	std::cout << "\033[1;33m    Phone Book: \033[0m" << std::endl;
	std::cout << "\033[1;36mADD | SEARCH | EXIT\033[0m" << std::endl;
	for(;;){
		std::getline (std::cin, buf);
		if (buf == "ADD" || buf == "add")
			folder.fill();
		else if (buf == "SEARCH" || buf == "search")
			folder.search();
		else if (buf == "EXIT" || buf == "exit")
			folder.exit();
		else if (buf.length() == 0){
			return (1);
		}
		else
			std::cout << "Wrong command." << std::endl;
	}
}
