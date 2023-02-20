#include "Harl.hpp"

int	main(void){
	Harl	exemple;

	std::cout << "debug : ";
	exemple.complain("DEBUG");
	std::cout << "info : ";
	exemple.complain("INFO");
	std::cout << "warning : ";
	exemple.complain("WARNING");
	std::cout << "error : ";
	exemple.complain("ERROR");
	std::cout << "wrong arg : ";
	exemple.complain("aa");
	return (0);
}
