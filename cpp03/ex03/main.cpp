#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void){
	std::cout << "initialisation" << std::endl;
	DiamondTrap fermier("Emile");

	std::cout << "\nfermier (FragTrap)" << std::endl;
	fermier.takeDamage(10);
	fermier.takeDamage(10);
	fermier.beRepaired(10);
	for (int i = 0; i < 9; i++){
		fermier.attack("orge");
	}
	fermier.attack("orge");
	fermier.beRepaired(10);
	fermier.takeDamage(2);
	fermier.takeDamage(1000);
	fermier.whoAmI();
	return (0);
}
