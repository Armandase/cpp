#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << _name << " pass away." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	:	ClapTrap(name),
		ScavTrap(name),
		FragTrap(name)
{
	_name = name;
	_attacksDamage = 30;
	_energyPoints = 50;
	_hitPoints = 100;
	ClapTrap::_name += "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
	:	ClapTrap(copy),
		ScavTrap(copy),
		FragTrap(copy)
{
	DiamondTrap::operator=(copy);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamond){
	_name = diamond._name;
	_attacksDamage = diamond._attacksDamage;
	_energyPoints = diamond._energyPoints;
	_hitPoints = diamond._hitPoints;
	return (*this);
}

void	DiamondTrap::attack(const std::string &target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(){
	std::cout << _name << " is come from " << ClapTrap::_name << std::endl;
}
