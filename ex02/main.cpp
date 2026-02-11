#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        
        ShrubberyCreationForm home("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Costa Samundi");
        
        std::cout << "\n--- attemping to sign with low grade ---" << std::endl;
        intern.signForm(home);
        
        std::cout << "\n--- Boss signs all forms ---" << std::endl;
        boss.signForm(home);
        boss.signForm(robot);
        boss.signForm(pardon);
        
        std::cout << "\n--- intern tries to execute ---" << std::endl;
        intern.executeForm(home);
        
        std::cout << "\n--- Boss executes all ---" << std::endl;
        boss.executeForm(home);
        boss.executeForm(robot);
        boss.executeForm(pardon);
        

    } catch(const std::exception& e) {
        std::cout << "Erro geral: " << e.what() << std::endl;
    }
    return 0;
}
