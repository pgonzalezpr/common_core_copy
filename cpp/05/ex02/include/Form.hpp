#ifndef FORMAT_HPP
#define FORMAT_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat; 

class Form {
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

    class FormNotSignedException : public std::exception {
    public:
        FormNotSignedException();
        const char *what() const throw();
    };

    Form();
    Form(const std::string& name, int signGrade, int executeGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    virtual ~Form();

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(Bureaucrat const & executor);
    virtual void action() const = 0;
    
    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
};

std::ostream&  operator<<(std::ostream& os, const Form& obj);

#endif
