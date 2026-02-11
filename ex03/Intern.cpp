/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:00:49 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/11 10:04:53 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern& Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	AForm* (*creators[3])(const std::string&) = {
		&ShrubberyCreationForm::create,
		&RobotomyRequestForm::create,
		&PresidentialPardonForm::create
	};
	
	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}
	
	std::cout << "Error: form name not recognezid" << std::endl;
	return NULL;
}
