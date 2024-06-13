#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery", 145, 137),
_target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
Form("shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
Form(other.getName(), other.getSignGrade(), other.getExecuteGrade()),
_target(other.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    (void) other;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
    std::string file(this->_target + "_shrubbery");
    std::ofstream out(file.c_str());
    if (!out) 
	{
        std::cerr << "can't open/create" << this->_target + "_shrubbery" << std::endl;
        return ;
    }
    out << 
    "            # #### ####\n"
    "        ### \\/#|### |/####\n"
    "        ##\\/#/ \\||/##/_/##/_#\n"
    "       ###  \\/###|/ \\/ # ###\n"
    "    ##_\\_#\\_\\## | #/###_/_####\n"
    "    ## #### # \\ #| /  #### ##/##\n"
    "    __#_--###`  |{,###---###-~\n"
    "                \\ }{\n"
    "                }}{\n"
    "                }}{\n"
    "        akarafi {{}\n"
    "        , -=-~{ .-^- _\n"
    "                `}\n"
    "                 {"
    << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const { return this->_target; }

