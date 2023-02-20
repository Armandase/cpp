#include "Zombie.hpp"

int main (void)
{
	Zombie*	normies;

	normies = newZombie("chien");
	if (normies == NULL)
		return (1);
	normies->announce();
	randomChump("chat");
	delete normies;
	return (0);
}
