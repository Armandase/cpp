#include "ClapTrap.hpp"

int main(void){
	ClapTrap boulanger("Didier");

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
	return (0);
}
