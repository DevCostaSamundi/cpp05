#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try
    {
        Bureaucrat dev("Dev", 50);
        Bureaucrat boss("Boss", 1);
        
        
        Form tax("TaxForm", 30, 10);
        Form leave("LeaveForm", 100, 50);

        std::cout << tax << std::endl;
        std::cout << leave << std::endl;

        dev.signForm(tax);
        boss.signForm(tax);
        
        dev.signForm(leave);
        
        std::cout << tax << std::endl;
        std::cout << leave << std::endl;
    } catch(const std::exception& e) {
        std::cout << "Erro geral: " << e.what() << std::endl;
    }
    return 0;
}
