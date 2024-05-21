#include "Harl.hpp"

Harl::Harl(void)
{
    map[0].level = "DEBUG";
    map[0].f = &Harl::debug;
    map[1].level = "INFO";
    map[1].f = &Harl::info;
    map[2].level = "WARNING";
    map[2].f = &Harl::warning;
    map[3].level = "ERROR";
    map[3].f = &Harl::error;
}

void    Harl::complain(string level) {
    static int  i = -1;

    if (i <= 3)
        level ==map[++i].level ? (this->*map[i].f)(): complain(level);
    i = -1;
}   

void    Harl::debug(void) {
    cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
         << "pickle-special ketchup burger. I really do!"
         << endl;
}

void    Harl::info(void) {
    cout << "I cannot believe adding extra bacon costs more money. "
         << "You didn’t put enough bacon in my burger! If you did, "
         << "I wouldn’t be asking for more!"
         << endl;
}

void    Harl::warning(void) {
    cout << "I think I deserve to have some extra bacon for free. "
         << "’ve been coming for years whereas you started working "
         << "here since last month."
         << endl;
}

void    Harl::error(void) {
    cout << "This is unacceptable! I want to speak to the manager now."
         << endl;
}