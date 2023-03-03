#include "AAnimal.hpp"
#include "iostream"

AAnimal::AAnimal(){
	std::cout << "AAnimal constructor call" << std::endl;
	_type = "vie";
}

AAnimal::AAnimal(const std::string type){
	std::cout << "AAnimal constructor call" << std::endl;
	_type = type;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor call" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy){
	AAnimal::operator=(copy);
}

AAnimal& AAnimal::operator = (const AAnimal &aanimal){
	_type = aanimal._type;
	return (*this);
}

std::string AAnimal::getType(void) const{
	return(_type);
}
