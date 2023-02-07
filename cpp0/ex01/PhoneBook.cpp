#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>


PhoneBook::PhoneBook(void){}

void PhoneBook::fill()
{
	Contact		NewContact;

	NewContact.add();
}

void	PhoneBook::exit(void)
{
	std::exit(EXIT_SUCCESS);
}

void	PhoneBook::search()
{
	int	index;

	std::cin >> index;
}

