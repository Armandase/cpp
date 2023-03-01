#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap("anon")
{
	std::cout << "Scavtrap anon is a ScavTrap" << std::endl;
	_name = "anon";
	_hitPoints = 100;
	_energyPoints = 50;
	_attacksDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "Scavtrap " << name <<" is a ScavTrap" << std::endl;
	_name = name;
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
