#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

#include <iostream>

class Zombie{

	public:
		Zombie();
		~Zombie();
		void	announce(void);
		void	setName(std::string name);

	private:
		std::string	_Name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
