#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : FragTrap, ScavTrap{

public:
	~DiamondTrap();
	DiamondTrap(std::string _name);
	ClapTrap::name _clap_name;
	void whoAmI();	
private:
	std::string _name;

};

#endif
