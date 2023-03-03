#include "Bureaucrat.hpp"
#include <ostream>
#include <stdexcept>

Bureaucrat::Bureaucrat(){
}

Bureaucrat::~Bureaucrat() throw(){
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy){
	Bureaucrat::operator=(copy);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->~Bureaucrat();
	new(this) Bureaucrat(copy._name, copy._grade);
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:	_name(name)
{
	try {
		if (grade < 1){
			throw std::exception(Bureaucrat::GradeTooLowExecption);
		} else if (grade > 150){
			throw std::exception(Bureaucrat::GradeTooHighExecption);
		} else {
			_grade = grade;
		}
	} catch (std::exception & e) {
	}
}

int	Bureaucrat::getGrade(){
	return (_grade);
}

std::string	Bureaucrat::getName(){
	return (_name);
}

std::ostream &operator << (std::ostream& os, const Bureaucrat& crat){
	os << crat.getName() << ", bureaucrat grade " << crat.getGrade() ".";
	return (os);
}
