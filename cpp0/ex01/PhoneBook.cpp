#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>


PhoneBook::PhoneBook(void){
	for(size_t i = 0; i < 8; i++){
		PhoneBook::_Tab[i] = 0;
	}
	PhoneBook::_Oldest = 0;
}

PhoneBook::~PhoneBook(void){

}

void	PhoneBook::Exit(void)
{
	std::exit(EXIT_SUCCESS);
}

void PhoneBook::Fill()
{
	Contact		NewContact;
	size_t		i;

	for (i = 0; i < 8; i++)
	{
		if (PhoneBook::_Tab[i] != 1)
		{
			NewContact.Add(i);
			PhoneBook::_Contacts[i] = NewContact;
			PhoneBook::_Tab[i] = 1;
			break ;
		}
	}
	if (i == 8)
	{
		NewContact.Add(i);
		PhoneBook::_Contacts[PhoneBook::_Oldest] = NewContact;
		if (PhoneBook::_Oldest == 7)
			PhoneBook::_Oldest = 0;
		else
			PhoneBook::_Oldest++;
	}
}

void	PhoneBook::PrintBook()
{
	if (PhoneBook::_Tab[0] == 0)
	{
		std::cout << "\033[1;36mYour PhoneBook is empty\033[0m 🥺" << std::endl;
		return ;
	}
	std::cout << "\033[1;32m|     Index|First name| Last name|  Nickname|\033[0m" << std::endl;
	for (size_t	i = 0; i < 8 && PhoneBook::_Tab[i] == 1; i++)
	{
		std::cout << "\033[1;32m|\033[0m" << std::setw(10) << i + 1;
		this->_Contacts[i].PrintReducedContact();
	}
}

void	PhoneBook::Search()
{
	std::string tmp;
	char*		val;
	int	index;

	PrintBook();
	if (PhoneBook::_Tab[0] == 0)
		return ;
	std::cout << "\033[1;32mEnter an index\033[0m" << std::endl;
	while (1)
	{
		if (std::getline(std::cin, tmp) == false)
			std::exit(1);
		val = const_cast<char *>(tmp.c_str());
		index = std::atoi(val);
		if (index < 1 || index > 8)
			std::cout << "\033[1;32mEnter a digit between 1 and 8\033[0m" << std::endl;
		else
			break;
	}
	if (PhoneBook::_Tab[index - 1] == 0)
		std::cout << "\033[1;32mThis index doesn't exit\033[0m" << std::endl;
	else
		this->_Contacts[index - 1].PrintContact();
}
