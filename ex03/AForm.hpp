#ifndef	AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
public:
	AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm &other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	
	// Getters
	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	
	void beSigned(const Bureaucrat &b);
	void execute(const Bureaucrat &execute) const;
	
	virtual void executeAction() const = 0;
	
	class GradeToHighException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
	
	class FormNotSignedException : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream *out, const AForm &form);

#endif
