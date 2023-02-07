#include "Contact.hpp"
#include <cstdlib>

Contact::Contact(void){

}

Contact::~Contact(void){

};

void	input_to_contact(std::string request, std::string *var){
	std::string	buf;
	
	std::cout << request << std::endl;
	std::cout << "\033[1;32m-> \033[0m";
	std::getline(std::cin, buf);
	if (buf.length() == 0){
		std::cout << std::endl;
		std::exit(EXIT_FAILURE);
	}
	*var = buf;
}

void	Contact::add()
{
	input_to_contact("\033[1;32mfirst name :\033[0m", &this->_first_name);
	input_to_contact("\033[1;32mlast name :\033[0m", &this->_last_name);
	input_to_contact("\033[1;32mnickname :\033[0m", &this->_nickname);
	input_to_contact("\033[1;32mdarkest secret :\033[0m", &this->_secret);
}
