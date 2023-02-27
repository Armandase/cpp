#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap :virtual public ClapTrap{

public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap& copy);
	FragTrap& operator=(const FragTrap& frag);
	void	highFivesGuys();
	void	attack(const std::string& target);
};

#endif
