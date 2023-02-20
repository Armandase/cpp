#include "Zombie.hpp"

int main (void)
{
	Zombie*	normies;
	int		N;

	N = 8;
	normies = zombieHorde(N, "chimpanze");
	if (normies == NULL)
		return (1);
	for (int i = 0; i < N; i++)
	{
		normies[i].announce();
	}
	delete[] normies;
}
