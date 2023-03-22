#include "iter.hpp"
#include <cctype>
#include <iostream>

void	increment(int &nu){
	nu++;
}

void	toLowercase(std::string &str){
	for (int i = 0; str[i]; i++){
		if (str[i] >= 'a' && str[i] <= 'z'){
			str[i] -= 32;
		}
	}
}

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }


int	main(void)
{
	{
		std::cout << "Correction main:" << std::endl;
		int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
		Awesome tab2[5];

		iter( tab, 5, print<int> );
		iter( tab2, 5, print<Awesome> );
	}
	std::cout << std::endl;
	{
		std::cout << "int tab - function add 1 on each elements" << std::endl;
		int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
		std::cout << "initiale : ";
		for (int i = 0; i < 8; i++){
			std::cout << array[i]  << " ; ";
		}
		std::cout << std::endl;
		iter(array, 8, &increment);
		std::cout << "after iter : ";
		for (int i = 0; i < 8; i++){
			std::cout << array[i]  << " ; ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "string tab - function to upper" << std::endl;
		std::string strs[7] = {"aBon", "Bon", "Cuit", "Druide" , "etoile", "FOIRE", "glObe"};
		std::cout << "initiale : ";
		for (int i = 0; i < 7; i++){
			std::cout << strs[i]  << " ; ";
		}
		std::cout << std::endl;
		iter(strs, 7, &toLowercase);
		std::cout << "after iter : ";
		for (int i = 0; i < 7; i++){
			std::cout << strs[i]  << " ; ";
		}
		std::cout << std::endl;
	}
	return (0);
}
