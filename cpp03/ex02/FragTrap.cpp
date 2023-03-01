#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "FragTrap " << name <<" is a FragTrap" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attacksDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< _name << " will be detroyed." << std::endl;
}


FragTrap::FragTrap(const FragTrap& copy)
	: ClapTrap(copy)
{
	std::cout << "FragTrap " << copy._name <<" has been copied into " << _name << std::endl;
	FragTrap::operator=(copy);
}

FragTrap& FragTrap::operator=(const FragTrap &frag)
{
	std::cout << "FragTrap " << _name <<" is now equal to " << frag._name << std::endl;
	this->_name = frag._name;
	this->_attacksDamage = frag._attacksDamage;
	this->_energyPoints = frag._energyPoints;
	this->_hitPoints = frag._hitPoints;
	return (*this);
}

void	FragTrap::highFivesGuys(){
	std::cout << _name << " is asking for an high fives !!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (!_energyPoints){
		std::cout << _name << "'s energy points is too low." << std::endl;
		return ;
	} else if (!_hitPoints){
		std::cout << _name << "'s hit points is too low." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attacksDamage << " points of damage!" << std::endl;
	_energyPoints--;
}
