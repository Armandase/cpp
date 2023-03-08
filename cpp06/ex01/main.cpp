#include <iostream>
#include "Serializer.hpp"

int	main()
{
	Serializer	cast;
	Data		value;
	uintptr_t	ptr;

	ptr = cast.serialize(&value);
	std::cout << "addr Data: " << &value << std::endl;
	std::cout << "data as uintptr_t: " << ptr  << std::endl;
	std::cout << "addr uintptr_t as Data: " << cast.deserialize(ptr) << std::endl;
	return (0);
}
