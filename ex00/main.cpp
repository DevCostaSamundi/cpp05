/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:58:09 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/11 09:58:10 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try
    {
        Bureaucrat a("Costa", 42);
        Bureaucrat b("Dev", 1);
        Bureaucrat c("Luanda", 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;

        b.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat d("Erro", 151);
    }
    catch(const std::exception& e)
    {
        std::cout << "Erro no construtor: " << e.what() << std::endl;
    }
    return 0;
}