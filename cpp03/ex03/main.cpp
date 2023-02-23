#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	std::cout << "initialisation" << std::endl;
	ClapTrap boulanger("Didier");
	ScavTrap patissier("Edouard");
	FragTrap fermier("Emile");

	std::cout << "\nboulanger (ClapTrap)" << std::endl;
	boulanger.takeDamage(10);
	boulanger.takeDamage(10);
	boulanger.beRepaired(10);
	for (int i = 0; i < 9; i++){
		boulanger.attack("farine");
	}
	boulanger.attack("farine");
	boulanger.beRepaired(10);
	boulanger.takeDamage(2);
	boulanger.takeDamage(1000);
	std::cout << "\npatissier (ScavTrap)" << std::endl;
	patissier.takeDamage(10);
	patissier.takeDamage(10);
	patissier.beRepaired(10);
	for (int i = 0; i < 9; i++){
		patissier.attack("croissant");
	}
	patissier.attack("croissant");
	patissier.beRepaired(10);
	patissier.takeDamage(2);
	patissier.takeDamage(1000);
	patissier.guardGate();
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
	fermier.highFivesGuys();
	return (0);
}
