/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:00:55 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/11 10:04:53 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);
	
	AForm* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* f2 = someRandomIntern.makeForm("presidebntial pardon", "Ford Prefect");
	AForm* f3 = someRandomIntern.makeForm("shrubbery creation", "Garden");
	AForm* f4 = someRandomIntern.makeForm("coffe making", "Intern");
	
	if (f1) {
		boss.signForm(*f1);
		boss.executeForm(*f1);
		delete f1;
	}
	if (f2) {
		boss.signForm(*f2);
		boss.executeForm(*f2);
		delete f2;
	}
	if (f3) {
		boss.signForm(*f3);
		boss.executeForm(*f3);
		delete f3;
	}
	if (f4) {
		delete f4;
	}
	return (0);
}
