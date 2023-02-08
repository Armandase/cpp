#ifndef _PHONE_BOOK_HPP_
# define _PHONE_BOOK_HPP_

# include "Contact.hpp"

class	PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		void	Fill();
		void	Search();
		void	Exit();
	private:
		void	PrintBook();
		Contact	_Contacts[8];
		int		_Tab[8];
		int		_Oldest;
};

#endif
