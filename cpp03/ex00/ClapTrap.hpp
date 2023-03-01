#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

# include <iostream>

class ClapTrap{

public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& clap);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attacksDamage;
};

#endif
