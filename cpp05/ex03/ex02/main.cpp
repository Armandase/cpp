#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	Shrubbery()
{
	{
		std::cout << "\033[1;33mShrubbery:\033[0mPermisson ok" << std::endl;
		Bureaucrat	humain("Brian", 24);
		ShrubberyCreationForm	papier("Peigne");

		humain.signForm(&papier);
		humain.executeForm(papier);
		std::cout << std::endl;
	}
	{
		std::cout << "Sign ok but cant exec" << std::endl;
		Bureaucrat	alien("Jimmy", 140);
		ShrubberyCreationForm	papier("seche-cheveux");

		alien.signForm(&papier);
		alien.executeForm(papier);
		std::cout << std::endl;
	}
	{
		std::cout << "cant sign and cant exec" << std::endl;
		Bureaucrat	alien("Alban", 147);
		ShrubberyCreationForm	papier("loop");

		alien.signForm(&papier);
		alien.executeForm(papier);
		std::cout << std::endl;
	}
}

void	Robotomy()
{
	{
		std::cout << "\033[1;33mRobotomy:\033[0m Permisson ok" << std::endl;
		Bureaucrat	humain("Brian", 24);
		RobotomyRequestForm	droide("boulon");

		humain.signForm(&droide);
		humain.executeForm(droide);
		std::cout << std::endl;
	}
	{
		std::cout << "Sign ok but cant exec" << std::endl;
		Bureaucrat	alien("Jimmy", 50);
		RobotomyRequestForm	robot("ecrou");

		alien.signForm(&robot);
		alien.executeForm(robot);
		std::cout << std::endl;
	}
	{
		std::cout << "cant sign and cant exec" << std::endl;
		Bureaucrat	alien("Alban", 147);
		RobotomyRequestForm	cyborg("vis");

		alien.signForm(&cyborg);
		alien.executeForm(cyborg);
		std::cout << std::endl;
	}
}

void	Presidential()
{
	{
		std::cout << "\033[1;33mPresidential:\033[0m Permisson ok" << std::endl;
		Bureaucrat	god("***", 1);
		PresidentialPardonForm	hom("objs");

		god.signForm(&hom);
		god.executeForm(hom);
		std::cout << std::endl;
	}
	{
		std::cout << "Sign ok but cant exec" << std::endl;
		Bureaucrat	alien("^.^", 20);
		PresidentialPardonForm	ter("argile");

		alien.signForm(&ter);
		alien.executeForm(ter);
		std::cout << std::endl;
	}
	{
		std::cout << "cant sign and cant exec" << std::endl;
		Bureaucrat	hom("objet", 147);
		PresidentialPardonForm	vivre("besoin");

		hom.signForm(&vivre);
		hom.executeForm(vivre);
		std::cout << std::endl;
	}
}

int main ()
{
	Shrubbery();
	Robotomy();
	Presidential();
}
