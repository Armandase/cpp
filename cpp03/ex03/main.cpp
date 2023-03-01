#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void){
	std::cout << "initialisation" << std::endl;
	DiamondTrap arbre("Sapin");
	{
		std::cout << "copy : "<< std::endl;
		DiamondTrap plante("tout");
		plante = arbre;
	}

	std::cout << "\narbre (DiamondTrap)" << std::endl;
	arbre.takeDamage(10);
	arbre.takeDamage(10);
	arbre.beRepaired(10);
	for (int i = 0; i < 9; i++){
		arbre.attack("chene");
	}
	arbre.attack("chene");
	arbre.beRepaired(10);
	arbre.takeDamage(2);
	arbre.takeDamage(1000);
	arbre.whoAmI();
	return (0);
}
