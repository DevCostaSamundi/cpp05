/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:01:01 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/11 10:04:53 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentailPardonFrom", 25, 5), target("default"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentailPardonFrom", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target){}
	
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		this->target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblerox." << std::endl;
}

AForm* PresidentialPardonForm::create(const std::string& target) {
	return new PresidentialPardonForm(target);
}
