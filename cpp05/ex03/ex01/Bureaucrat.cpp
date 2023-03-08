#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <stdexcept>

Bureaucrat::Bureaucrat()
	:	_name("anon")
{
	_grade = 150/2;
}

Bureaucrat::~Bureaucrat(){ 
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
			throw Bureaucrat::GradeTooHighExecption();
		} else if (grade > 150){
			throw Bureaucrat::GradeTooLowExecption();
		} else {
			_grade = grade;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

std::string	Bureaucrat::getName() const {
	return (_name);
}

std::ostream &operator << (std::ostream& os, const Bureaucrat& crat){
	os << crat.getName() << ", bureaucrat grade " << crat.getGrade() << ".";
	return (os);
}

void	Bureaucrat::incrementGrade(){
	try {
		if (_grade <= 1)
			throw Bureaucrat::GradeTooHighExecption();
		else
			_grade--;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade(){
	try {
		if (_grade >= 150)
			throw Bureaucrat::GradeTooLowExecption();
		else
			_grade++;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(Form *form){
	try {
		if (form->getSigned())
			std::cout << form->getName() << " is already signed." << std::endl;
		else {
			form->beSigned(*this);
			std::cout << getName() << " signed " << form->getName() << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << getName() << " couldn't sign " << form->getName() << " because " << e.what() << std::endl;
	}
}
