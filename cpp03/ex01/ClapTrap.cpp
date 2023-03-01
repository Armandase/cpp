#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << _name << " pass away." << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& copy){
	ClapTrap::operator=(copy);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clap){
	_name = clap._name;
	_energyPoints = clap._energyPoints;
	_hitPoints = clap._hitPoints;
	_attacksDamage = clap._attacksDamage;
	return (*this);
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << name << " was born." << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attacksDamage = 0;
};

void	ClapTrap::attack(const std::string &target)
{
	if (!_energyPoints){
		std::cout << _name << "'s energy points is too low." << std::endl;
		return ;
	} else if (!_hitPoints){
		std::cout << _name << "'s hit points is too low." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attacksDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints){
		std::cout << _name << "'s health is already null." << std::endl;
		return ;
	}
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " take " << amount << " damage, his current health is " << _hitPoints << " hit points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energyPoints){
		std::cout << _name << "'s energy points is too low." << std::endl;
		return ;
	}
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points. His current health is " << _hitPoints  << " hit points." << std::endl;
	_energyPoints--;

}
