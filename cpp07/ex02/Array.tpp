#include "Array.hpp"

template <typename T>
Array<T>::Array(){
	_array = new T;
	_len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n){
	_array = new T[n];
	_len = n;
}

template <typename T>
Array<T>::~Array(){
	delete [] _array;
}

template <typename T>
Array<T>::Array(const Array &copy){
	Array::operator=(copy);
}

template <typename T>
Array<T> & Array<T>::operator=(const Array &copy){
	_array = new T[copy._len];
	for (unsigned int i = 0; i < copy._len; i++)
		_array[i] = copy._array[i];
	_len = copy._len;
	return (*this);
}

template <typename T>
T & Array<T>::operator[](unsigned int i){
	if (i >= _len){
		throw Array::OutOfArray();
	}
	return (this->_array[i]);
}

template <typename T>
unsigned int Array<T>::size(void){
	return (_len);
}
