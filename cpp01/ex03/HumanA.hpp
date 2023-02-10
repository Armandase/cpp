#ifndef _HUMANA_HPP_
# define _HUMANA_HPP_

#include <iostream>
#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	attack(void);
	private:
		std::string	_name;
		Weapon&		_weapon;
};

#endif
