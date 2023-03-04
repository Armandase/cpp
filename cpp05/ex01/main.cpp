#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	{
		Bureaucrat	humain("Brian", 24);
		Form		papier("contravention", false, 50, 25);

		std::cout << humain << std::endl;
		std::cout << papier << std::endl;
		papier.beSigned(humain);
		papier.beSigned(humain);
		std::cout << papier << std::endl;
	}
	{
		Bureaucrat herbe("hibou", 2);
		std::cout << "\n" << herbe << std::endl;
		herbe.incrementGrade();
		std::cout << herbe << std::endl;
		herbe.incrementGrade();
		std::cout << herbe << std::endl;
	}
	{
		Bureaucrat herbe("chouette", 149);
		std::cout << "\n" << herbe << std::endl;
		herbe.decrementGrade();
		std::cout << herbe << std::endl;
		herbe.decrementGrade();
		std::cout << "name : " << herbe.getName() << std::endl;
		std::cout << "grade : " << herbe.getGrade() << std::endl;
	}
}
