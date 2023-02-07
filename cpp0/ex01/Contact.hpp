#ifndef _CONTACT_HPP_
# define _CONTACT_HPP_
# include <iostream>

class	Contact{
	public:
		Contact();
		~Contact();
		void	add(void);
	private:
		int			_index;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_secret;
};

#endif
