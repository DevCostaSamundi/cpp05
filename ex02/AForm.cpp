#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("AForm"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeToHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();	
}
	
AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
	return (this->name);
}

bool AForm::getIsSigned() const {
	return (this->isSigned);
}

int AForm::getGradeToSign() const {
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (this->gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

void AForm::execute(const Bureaucrat &execute) const {
	if (!this->isSigned)
		throw FormNotSignedException();
	if (execute.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();
	this->executeAction();
}

const char *AForm::GradeToHighException::what() const throw() {
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Form is not signed";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << form.getName()
		<< ", form sign grade " << form.getGradeToSign()
		<< ", execute grade " << form.getGradeToExecute()
		<< ", signed: " << (form.getIsSigned() ?  "yes" : "no");
	return out;
}
