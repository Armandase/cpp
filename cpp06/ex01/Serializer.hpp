#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "data.hpp"

class Serializer
{
	 public:
		Serializer();
		~Serializer();
		Serializer (const Serializer &copy);
		Serializer &operator=(const Serializer&);

		static uintptr_t serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);
};

#endif
