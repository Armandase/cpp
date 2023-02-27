#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{

public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& scav);
	void	guardGate();
	void	attack(const std::string& target);
};

#endif
