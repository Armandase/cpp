#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap("anon")
{
	std::cout << "FragTrap anon is a FragTrap" << std::endl;
	_name = "anon";
	_hitPoints = 100;
	_energyPoints = 100;
	_attacksDamage = 30;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "FragTrap " << name <<" is a FragTrap" << std::endl;
	_name = name;
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
	std::cout << "FragTrap " << _name << " is asking for an high fives !!" << std::endl;
}
