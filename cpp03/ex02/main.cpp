#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	std::cout << "initialisation" << std::endl;
	FragTrap fermier("Emile");
	{
		std::cout << "copy : " << std::endl;
		FragTrap tmp (fermier);
	}

	std::cout << "\nfermier : " << std::endl;
	fermier.takeDamage(10);
	fermier.takeDamage(500);
	fermier.beRepaired(10);
	for (int i = 0; i < 9; i++){
		fermier.attack("orge");
	}
	fermier.attack("orge");
	fermier.beRepaired(10);
	fermier.takeDamage(2);
	fermier.takeDamage(1000);
	fermier.highFivesGuys();
	return (0);
}
