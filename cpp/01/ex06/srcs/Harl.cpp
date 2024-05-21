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

void    Harl::complain(string level) {
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
        cout << DEFAULT_MSG << endl;
    }
}

Level   Harl::getLevel(string level) {
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
    cout << "[DEBUG]"
         << endl
         << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger."
         << endl
         << "I really do!"
         << endl << endl;
}

void    Harl::info(void) {
    cout << "[INFO]"
         << endl
         << "I cannot believe adding extra bacon costs more money." 
         << "You didn’t put enough bacon in my burger!"
         << "If you did, I wouldn’t be asking for more!"
         << endl << endl;
}

void    Harl::warning(void) {
    cout << "[WARNING]"
         << endl
         << "I think I deserve to have some extra bacon for free."
         << endl
         << "I’ve been coming for years whereas you started working here since last month."
         << endl << endl;
}

void    Harl::error(void) {
    cout << "[ERROR]"
         << endl
         << "This is unacceptable! I want to speak to the manager now."
         << endl << endl;
}