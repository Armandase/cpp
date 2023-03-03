#include "Bureaucrat.hpp"
#include <ostream>
#include <stdexcept>

Bureaucrat::Bureaucrat(){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy){
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &copy){
}

Bureaucrat::GradeTooLowExecption{

}

Bureaucrat::Bureaucrat(std::string name, int grade){
	try {
		if (grade < 1){
			throw std::exception_ptr(Bureaucrat::GradeTooLowExecption);
		} else if (grade > 150){
			throw std::exception_ptr(Bureaucrat::GradeTooHighExecption);
		} else {
			_grade = grade;
			_name = name;
		}
	} catch (std::exception & e) {
	statements
	}
}

int	Bureaucrat::getGrade(){
	return (_grade);
}

std::string	Bureaucrat::getName(){
	return (_name);
}

std::ostream &operator << (std::ostream& os, const Bureaucrat& crat){
	os << Bureaucrat::getName() << ", bureaucrat grade " << Bureaucrat::getGrade() ".";
	return (os);
}
