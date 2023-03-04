#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main ()
{
	{
		std::cout << "Permisson ok" << std::endl;
		Bureaucrat	humain("Brian", 24);
		AForm		papier("contravention", false, 50, 25);

		std::cout << humain << std::endl;
		std::cout << papier << std::endl;
		humain.signAForm(&papier);
		std::cout << papier << std::endl;
		humain.signAForm(&papier);
		std::cout << papier << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Permisson denied for bureacrat" << std::endl;
		Bureaucrat	humain("Brian", 120);
		AForm		papier("contravention", false, 50, 25);

		std::cout << humain << std::endl;
		std::cout << papier << std::endl;
		humain.signAForm(&papier);
		std::cout << papier << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "new and copy" << std::endl;
		Bureaucrat	*humain;
		humain = new Bureaucrat();
		Bureaucrat	parquet = *humain;
		AForm		*papier;
		papier = new AForm();
		AForm journal = *papier;

		std::cout << *humain << std::endl;
		std::cout << parquet << std::endl;
		std::cout << *papier << std::endl;
		std::cout << journal << std::endl;
		humain->signAForm(papier);
		std::cout << *papier << std::endl;
		std::cout << journal << std::endl;
		delete papier;
		delete humain;
	}
}
