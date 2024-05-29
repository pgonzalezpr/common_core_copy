#include "Harl.hpp"

Harl::Harl(void)
{
    map[0].level = DEBUG;
    map[0].f = &Harl::debug;
    map[1].level = INFO;
    map[1].f = &Harl::info;
    map[2].level = WARNING;
    map[2].f = &Harl::warning;
    map[3].level = ERROR;
    map[3].f = &Harl::error;
}

void    Harl::complain(std::string level) {
    switch (getLevel(level))
    {
    case DEBUG:
        debug();
        info();
        warning();
        error();
        break;
    case INFO:
        info();
        warning();
        error();
        break;
    case WARNING:
        warning();
        error();
        break;
    case ERROR:
        error();
        break;
    default:
        std::cout << DEFAULT_MSG << std::endl;
    }
}

Level   Harl::getLevel(std::string level) {
    if (level == "DEBUG")
        return DEBUG;
    if (level == "INFO")
        return INFO;
    if (level == "WARNING")
        return WARNING;
    if (level == "ERROR")
        return ERROR;
    return UNKNOWN;
}

void    Harl::debug(void) {
    std::cout << "[DEBUG]"
         << std::endl
         << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger."
         << std::endl
         << "I really do!"
         << std::endl << std::endl;
}

void    Harl::info(void) {
    std::cout << "[INFO]"
         << std::endl
         << "I cannot believe adding extra bacon costs more money." 
         << "You didn’t put enough bacon in my burger!"
         << "If you did, I wouldn’t be asking for more!"
         << std::endl << std::endl;
}

void    Harl::warning(void) {
    std::cout << "[WARNING]"
         << std::endl
         << "I think I deserve to have some extra bacon for free."
         << std::endl
         << "I’ve been coming for years whereas you started working here since last month."
         << std::endl << std::endl;
}

void    Harl::error(void) {
    std::cout << "[ERROR]"
         << std::endl
         << "This is unacceptable! I want to speak to the manager now."
         << std::endl << std::endl;
}
