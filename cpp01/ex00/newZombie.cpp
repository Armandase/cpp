#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*value = new(std::nothrow) Zombie(name);
	if (value == NULL)
		std::cout << "Allocation failed." << std::endl;
	return (value);
}
