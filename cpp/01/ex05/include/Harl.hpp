#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
private:
    struct _map
	{
		std::string	level;
		void	(Harl::*f)(void);
	};
    struct _map map[4];
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
public:
    Harl();
    void    complain(std::string level);
};

#endif
