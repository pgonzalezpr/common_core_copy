#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat exception: grade is too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat exception: grade is too low";
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(MIN_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()) {
    if (other.getGrade() < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (other.getGrade() > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = other.getGrade();  
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    (void) other;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << "Bureaucrat " << this->_name << " signed format "
        << form.getName() << std::endl;
    } catch(const Form::GradeTooLowException& e) {
        std::cerr << "Bureaucrat " << this->_name << " can't sign format "
        << form.getName() << " because its grade is too low" << std::endl;
    }
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}