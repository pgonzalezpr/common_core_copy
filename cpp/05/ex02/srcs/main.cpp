#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    ShrubberyCreationForm shrubbery("home");
    Bureaucrat bureaucrat("bureaucrat", 4);

    bureaucrat.signForm(shrubbery);
    try {
        shrubbery.execute(bureaucrat);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    RobotomyRequestForm robotomy("jhon");

    bureaucrat.signForm(robotomy);
    try {
        robotomy.execute(bureaucrat);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    PresidentialPardonForm presidential("laura");

    bureaucrat.signForm(presidential);
    try {
        presidential.execute(bureaucrat);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}