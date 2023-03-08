#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer(){
}

Serializer::~Serializer(){
}

Serializer::Serializer(const Serializer &copy){
	(void)copy;
}

Serializer & Serializer::operator=(const Serializer &copy){
	(void)copy;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t ret;
	ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}

Data*	Serializer::deserialize(uintptr_t raw){
	Data *ret;
	ret = reinterpret_cast<Data *>(raw);
	return (ret);
}
