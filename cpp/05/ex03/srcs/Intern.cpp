#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void) other; }

Intern& Intern::operator=(const Intern& other) {
    (void) other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string& name, const std::string& target) {
    const char *forms[3] = FORMS;

    int i = 0;
    while (i < 3 && forms[i] != name)
        i++;
    
    switch (i) {
        case 0:
            std::cout << "Intern creates " << name << " form with target " 
            << target << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates " << name << " form with target " 
            << target << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << name << " form with target " 
            << target << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cerr << "Invalid form type" << std::endl;
            break;
    }
    return NULL;
}