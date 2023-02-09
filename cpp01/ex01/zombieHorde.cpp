#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *value = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		value[i].setName(name);
	}
	return value;
}
