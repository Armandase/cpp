#include "Contact.hpp"
#include <iomanip>

Contact::Contact(void){

}

Contact::~Contact(void){

};

void	InputToContact(std::string request, std::string *var){
	std::string	buf;
	
	std::cout << request << std::endl;
	std::cout << "\033[1;32m-> \033[0m";
	std::getline(std::cin, buf);
	if (buf.length() == 0){
		buf = "\0";
	}
	*var = buf;
}

void	Contact::PrintReducedContact(void)
{
	std::string	tmp;
	if (Contact::_FirstName.length() > 10)
	{
		tmp = Contact::_FirstName;
		std::cout << "\033[1;32m|\033[0m" << std::setw(10) << tmp.replace(9, 10, ".").substr(0, 10); 
	}
	else
		std::cout << "\033[1;32m|\033[0m" << std::setw(10) << Contact::_FirstName;
	if (Contact::_LastName.length() > 10)
	{
		tmp = Contact::_LastName;
		std::cout << "\033[1;32m|\033[0m" << std::setw(10) << tmp.replace(9, 10, ".").substr(0, 10);
	}
	else
		std::cout << "\033[1;32m|\033[0m" << std::setw(10) << Contact::_LastName;
	if (Contact::_Nickname.length() > 10)
	{
		tmp = Contact::_Nickname;
		std::cout << "\033[1;32m|\033[0m" << std::setw(10) << tmp.replace(9, 10, ".").substr(0, 10);
	}
	else
		std::cout << "\033[1;32m|\033[0m" << std::setw(10) << Contact::_Nickname;
	std::cout << "\033[1;32m|\033[0m" << std::endl;
}

void	Contact::Add(int index)
{
	Contact::_Index = index;
	InputToContact("\033[1;32mfirst name :\033[0m", &this->_FirstName);
	InputToContact("\033[1;32mlast name :\033[0m", &this->_LastName);
	InputToContact("\033[1;32mnickname :\033[0m", &this->_Nickname);
	InputToContact("\033[1;32mphone number :\033[0m", &this->_PhoneNumber);
	InputToContact("\033[1;32mdarkest secret :\033[0m", &this->_Secret);
	std::cout << "\033[1;36mThe contact has been created\033[0m" << std::endl;
}

void Contact::PrintContact(void)
{
	std::cout << "\033[1;32mFirst name: \033[0m" << Contact::_FirstName <<std::endl;
	std::cout << "\033[1;32mLast name: \033[0m" << Contact::_LastName <<std::endl;
	std::cout << "\033[1;32mNickname: \033[0m" << Contact::_Nickname <<std::endl;
	std::cout << "\033[1;32mPhone number: \033[0m" << Contact::_PhoneNumber <<std::endl;
	std::cout << "\033[1;32mDarkest secret: \033[0m" << Contact::_Secret <<std::endl;
}
