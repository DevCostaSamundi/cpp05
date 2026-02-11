/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:58:19 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/11 09:58:20 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return (this->name);
}

int Bureaucrat::getGrade() const{
    return (this->grade);
}


void Bureaucrat::incrementGrade() {
    if (grade <= 1)
    {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150)
    {
        throw GradeTooLowException();
    }
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw (){
    return ("Nota muito elevada");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Nota muito Baixa");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", burocrata com classificacao " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(Form &f)
{
	try {
	f.beSigned(*this);
	std::cout << this->name << " assinou " << f.getName() << std::endl;
	} catch (std::exception &e) {
	std::cout << this->name << " não conseguiu assinar " << f.getName() 
		<< " Porque " << e.what() << std::endl;
	}
}
