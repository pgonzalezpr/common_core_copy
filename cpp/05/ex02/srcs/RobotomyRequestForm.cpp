#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy", 72, 45),
_target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
Form("robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
Form(other.getName(), other.getSignGrade(), other.getExecuteGrade()),
_target(other.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    (void) other;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        std::cout << "BzzzZZZZZZzzzzz..." << std::endl
                  << this->_target << " has been robotomized successfully." << std::endl;
    }
    else 
        std::cout << this->_target << " robotomy failed." << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const { return this->_target; }