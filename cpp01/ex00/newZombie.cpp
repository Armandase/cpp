#include "Zombie.hpp"
#include <new>

Zombie* newZombie(std::string name)
{
	try
	{
		Zombie	*value = new Zombie(name);
		return value;
	}
	catch (std::bad_alloc &e)
	{
		std::cout << "new Failed" << std::endl;
	}
	return NULL;
}
