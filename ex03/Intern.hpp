#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	Intern& operator=(const Intern &other);
	~Intern();
	AForm* makeForm(const std::string& forName, const std::string& target) const;
};

#endif
