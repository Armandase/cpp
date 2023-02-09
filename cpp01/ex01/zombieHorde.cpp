#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	new Zombie[N];
	for (size_t i = 0; i < N; i++)
	{
		value[i] = Zombie(name);
	}
	return value;
}
