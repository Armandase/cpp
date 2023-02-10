#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type){
	setType(type);
}

Weapon::~Weapon(){
	return ;
}

const std::string&	Weapon::getType(void){
	return (this->_type);
}

void	Weapon::setType(std::string value){
	this->_type = value;
}
