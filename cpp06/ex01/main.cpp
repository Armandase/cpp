#include <iostream>
#include "Serializer.hpp"

int	main()
{
	Serializer	cast;
	Data		value;
	Data		*casted;
	value.a = 5;
	uintptr_t	ptr;

	ptr = cast.serialize(&value);
	std::cout << "addr Data: " << &value << std::endl;
	std::cout << "value.a == " << value.a << std::endl;
	std::cout << "data as uintptr_t: " << ptr  << std::endl;
	casted = cast.deserialize(ptr);
	std::cout << "addr uintptr_t as Data: " << casted << std::endl;
	std::cout << "casted.a == " << casted->a << std::endl;
	return (0);
}
