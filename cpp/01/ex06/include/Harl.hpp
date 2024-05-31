#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

#define NBR_MSG 4
#define DEFAULT_MSG "[ Probably complaining about insignificant problems ]"
#define ARGC_ERR "Incorrect number of arguments"

enum Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN
};

class Harl
{
public:
    Harl();
    void    complain(std::string level);
private:
    struct _map
	{
		Level       level;
        std::string level_str;
		void	(Harl::*f)(void);
	};

    Level   mapLevel(std::string level);
    struct _map map[NBR_MSG];
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
};

#endif
