#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *value = new(std::nothrow) Zombie[N];
	if (value == NULL)
	{
		std::cout << "Allocation failed" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
		value[i].setName(name);
	}
	return value;
}
