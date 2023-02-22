#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void){
	std::cout << "initialisation" << std::endl;
	ClapTrap boulanger("Didier");
	ScavTrap patissier("Edouard");

	std::cout << "\nboulanger" << std::endl;
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
	std::cout << "\npatissier" << std::endl;
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
	return (0);
}
