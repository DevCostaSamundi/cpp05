#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
		
}

Form::Form(const Form &other)
	: name(other.name), isSigned(other.isSigned),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

	

Form& Form::operator=(const Form &other) {
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}



Form::~Form() {
}

const std::string& Form::getName() const {
	return (this->name);
}

bool Form::getIsSigned() const {
	return (false);
}

int Form::getGradeToSign() const {
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->gradeToExecute);
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form grade too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form grade too low");
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form: " << f.getName()
		<< " | Signed: " << (f.getIsSigned() ? "yes" : "no")
		<< " | Grade to sign: " << f.getGradeToSign()
		<< " | Grade to execute: " << f.getGradeToExecute();
	return (os);
}
