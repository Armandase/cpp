#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat	humain("AAA", 24);
		
		rrf = someRandomIntern.makeForm("shrubbery creation", "home");
		if (rrf)
		{
			humain.signForm(rrf);
			humain.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;
	}	
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat	humain("BBB", 24);
		
		rrf = someRandomIntern.makeForm("robotomy request", "house");
		if (rrf)
		{
			humain.signForm(rrf);
			humain.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;
	}	
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat	humain("CCC", 24);
		
		rrf = someRandomIntern.makeForm("presidential pardon", "room");
		if (rrf)
		{
			humain.signForm(rrf);
			humain.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;
	}	
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat	humain("DDD", 24);
		
		rrf = someRandomIntern.makeForm("sequential questions", "kicthen");
		if (rrf)
		{
			humain.signForm(rrf);
			humain.executeForm(*rrf);
			delete rrf;
		}
	}	
}
