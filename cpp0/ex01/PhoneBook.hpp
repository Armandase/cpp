#ifndef _PHONE_BOOK_HPP_
# define _PHONE_BOOK_HPP_

# include "Contact.hpp"

class	PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		void	fill();
		void	search();
		void	exit();
	private:
		Contact	_Contacts[8];
};

#endif
