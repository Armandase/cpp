#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	{
		std::cout << "Permisson ok" << std::endl;
		Bureaucrat	humain("Brian", 24);
		ShrubberyCreationForm	papier("Peigne");

		humain.signForm(&papier);
		humain.executeForm(papier);
	}
}
