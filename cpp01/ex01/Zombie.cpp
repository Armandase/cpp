#include "Zombie.hpp"

Zombie::Zombie(void)
{

}

Zombie::~Zombie()
{
	std::cout << Zombie::_Name << ": died of starvation" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << Zombie::_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_Name = name;
}

