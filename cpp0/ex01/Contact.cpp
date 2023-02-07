#include "Contact.hpp"

Contact::Contact(void){}

void	Contact::add()
{
	std::string	buf;
	
	std::cout << "first name :" << std::endl;
	std::getline(std::cin, buf);
	this->_first_name = buf;
	std::cout << "last name :" << std::endl;
	std::getline(std::cin, buf);
	this->_last_name = buf;
	std::cout << "nickname :" << std::endl;
	std::getline(std::cin, buf);
	this->_nickname = buf;
	std::cout << "phone number :" << std::endl;
	std::getline(std::cin, buf);
	this->_nickname = buf;
	std::cout << "darkest secret :" << std::endl;
	std::getline(std::cin, buf);
	this->_nickname = buf;
}
