#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotmyRequestForm", 72, 45), target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}


void RobotomyRequestForm::executeAction() const {
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized successfully " << std::endl;
	else
		std::cout << "Robotomy Failed on " << this->target << "." << std::endl;
	
}

AForm* RobotomyRequestForm::create(const std::string& target) {
	return new RobotomyRequestForm(target);
}
