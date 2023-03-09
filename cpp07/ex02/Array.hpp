#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
#include <exception>

class Array
{
	 public:
		Array();
		Array(unsigned int n);
		~Array();
		Array (const Array &copy);
		Array &operator=(const Array&);
		Array &operator[](unsigned int i);
		class OutOfArray : public std::exception
		{
			virtual const char * what() const throw(){
				return ("You can't acces at this memory");
			}
		};
		unsigned int size(void);
	 private:
		T* 				_array;
		unsigned int	_len;
};

#endif
