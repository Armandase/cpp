#include "Bureaucrat.hpp"

int main ()
{
	{
		Bureaucrat humain("tube", 24);
		Bureaucrat b(humain);

		std::cout << humain << std::endl;
		std::cout << b << std::endl;
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
