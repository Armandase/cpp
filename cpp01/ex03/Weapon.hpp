#ifndef _WEAPON_HPP_
# define _WEAPON_HPP_

#include <iostream>

class Weapon{

	public:
		Weapon(std::string);
		~Weapon();

		const std::string&	getType();
		void				setType(std::string value);
	private:
		std::string	_type;
};

#endif
