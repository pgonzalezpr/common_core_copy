#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form;

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException();
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        GradeTooLowException();
        const char *what() const throw();
    };
    
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    void signForm(Form& form);
    void incrementGrade();
    void decrementGrade();
    std::string getName() const;
    int getGrade() const;
private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif