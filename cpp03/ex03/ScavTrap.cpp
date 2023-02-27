#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "Scavtrap " << name <<" is a ScavTrap" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attacksDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "A ScavTrap will be detroyed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
	: ClapTrap(copy)
{
	ScavTrap::operator=(copy);
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scav)
{
	_name = scav._name;
	_hitPoints = scav._hitPoints;
	_energyPoints = scav._energyPoints;
	_attacksDamage = scav._attacksDamage;
	return (*this);
}

void	ScavTrap::guardGate(){
	std::cout << _name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!_energyPoints){
		std::cout << _name << "'s energy points is too low." << std::endl;
		return ;
	} else if (!_hitPoints){
		std::cout << _name << "'s hit points is too low." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attacksDamage << " points of damage!" << std::endl;
	_energyPoints--;
}
