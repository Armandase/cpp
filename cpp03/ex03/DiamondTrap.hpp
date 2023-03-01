#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap{

public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& copy);
	DiamondTrap& operator=(const DiamondTrap &diamond);
	void	attack(const std::string &target);
	void	whoAmI();
private:
	std::string _name;
};

#endif
