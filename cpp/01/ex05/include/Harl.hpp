#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

using namespace std;

class Harl
{
private:
    struct _map
	{
		string	level;
		void	(Harl::*f)(void);
	};
    struct _map map[4];
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
public:
    Harl();
    void    complain(string level);
};

#endif