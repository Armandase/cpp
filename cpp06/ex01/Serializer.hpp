#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

class Serializer
{
	 public:
		Serializer();
		~Serializer();
		Serializer (const Serializer &copy);
		Serializer &operator=(const Serializer&);
	 private:
		
};


//A deplacer dans Serializer.cpp
Serializer::Serializer(){
}

Serializer::~Serializer(){
}

Serializer::Serializer(const Serializer &copy){
}

Serializer & Serializer::operator=(const Serializer &copy){
}



#endif
