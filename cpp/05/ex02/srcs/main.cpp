#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Form *createForm(std::string& type, std::string& target) {
    if (type == "shrubbery")
        return new ShrubberyCreationForm(target);
    if (type == "robotomy")
        return new RobotomyRequestForm(target);
    if (type == "presidential")
        return new PresidentialPardonForm(target);
    return NULL;
}

void signExecuteTest(std::string type, std::string target, std::string name, int grade) {
    Form *form = NULL;
    Bureaucrat *bureaucrat = NULL;

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
    form = createForm(type, target);
    if (!form) {
        std::cout << "Invalid form type" << std::endl;
        delete bureaucrat;
        return;
    }

    std::cout << "Bureaucrat " << name << " attempting to sign and execute "
    << type << " format" << std::endl;
    bureaucrat->signForm(*form);
    try {
        form->execute(*bureaucrat);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    delete form;
    delete bureaucrat;
}

void printTestEnd() {
    std::cout << std::endl;
    std::cout << "=================================================" << std::endl;
    std::cout << std::endl;
}

int main() {
    std::cout << "Test 1: Not enough grade to sign shrubbery format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("shrubbery", "home", "jhon", 147);
    printTestEnd();

    std::cout << "Test 2: Not enough grade to execute shrubbery format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("shrubbery", "home", "peter", 142);
    printTestEnd();

    std::cout << "Test 3: Enough grade for shrubbery format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("shrubbery", "home", "gwen", 130);
    printTestEnd();

    std::cout << "Test 4: Not enough grade to sign robotomy format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("robotomy", "alex", "jhon", 75);
    printTestEnd();

    std::cout << "Test 5: Not enough grade to execute robotomy format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("robotomy", "alex", "peter", 48);
    printTestEnd();

    std::cout << "Test 6: Enough grade for robotomy format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("robotomy", "alex", "gwen", 40);
    printTestEnd();

    std::cout << "Test 7: Not enough grade to sign presidential format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("presidential", "andrea", "jhon", 27);
    printTestEnd();

    std::cout << "Test 8: Not enough grade to execute presidential format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("presidential", "andrea", "peter", 7);
    printTestEnd();

    std::cout << "Test 9: Enough grade for presidential format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("presidential", "andrea", "gwen", 3);
    printTestEnd();
}