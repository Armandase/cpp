#ifndef _HUMANB_HPP_
# define _HUMANB_HPP_


#include <iostream>
#include "Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon &weapon);
		void	attack(void);
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif
