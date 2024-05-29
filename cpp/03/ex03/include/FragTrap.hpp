#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>

using namespace std;

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const string name);
    FragTrap(const FragTrap& other);
    virtual ~FragTrap();
    FragTrap&   operator=(const FragTrap& other);

    void    highFivesGuys(void);
};

#endif