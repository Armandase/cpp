#include "Array.hpp"

Array::Array(){
	_array = new T();
}

Array::Array(unsigned int n){
	_array = new T[n]{};
}

Array::~Array(){
	delete [] _array;
}

Array::Array(const Array &copy){
}

Array & Array::operator=(const Array &copy){
}

Array & Array::operator[](unsigned int i){
	if (i > n){
		throw Array::OutOfArray();
	}
	return (_array[i]);
}

unsigned int size(void){
	return (_len);
}
