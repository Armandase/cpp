#ifndef _CONTACT_HPP_
# define _CONTACT_HPP_
# include <iostream>

class	Contact{
	public:
		Contact();
		~Contact();
		void	Add(int index);
		void	PrintReducedContact(void);
		void	PrintContact(void);
	private:
		int			_Index;
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_Secret;
};

#endif
