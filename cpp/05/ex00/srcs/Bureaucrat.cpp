#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()) {
    if (other.getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    if (other.getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = other.getGrade();  
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    (void) other;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}