#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


void signExecuteTest(std::string type, std::string target, std::string name, int grade) {
    AForm *form = NULL;
    Bureaucrat *bureaucrat = NULL;
    Intern intern;

    std::cout << "Creating bureaucrat " << name << " with grade " 
    << grade << std::endl;
    try {
        bureaucrat = new Bureaucrat(name, grade);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    std::cout << "Creating " << type << " format with " << target 
    << " target" << std::endl;
    form = intern.makeForm(type, target);
    if (!form) {
        delete bureaucrat;
        return;
    }

    std::cout << "Bureaucrat " << name << " attempting to sign and execute "
    << type << " format" << std::endl;
    bureaucrat->signAForm(*form);
    bureaucrat->executeForm(*form);
    delete form;
    delete bureaucrat;
}

void printTestEnd() {
    std::cout << std::endl;
    std::cout << "=================================================" << std::endl;
    std::cout << std::endl;
}

int main() {
    std::cout << "Test 1: Not existing form type" << std::endl;
    std::cout << std::endl;
    signExecuteTest("nonexisting", "home", "gwen", 130);
    printTestEnd();

    std::cout << "Test 2: shrubbery creation form" << std::endl;
    std::cout << std::endl;
    signExecuteTest("shrubbery creation", "home", "gwen", 130);
    printTestEnd();

    std::cout << "Test 3: robotomy request forma" << std::endl;
    std::cout << std::endl;
    signExecuteTest("robotomy request", "alex", "gwen", 40);
    printTestEnd();

    std::cout << "Test 4: presidential pardon form" << std::endl;
    std::cout << std::endl;
    signExecuteTest("presidential pardon", "andrea", "gwen", 3);
    printTestEnd();
}