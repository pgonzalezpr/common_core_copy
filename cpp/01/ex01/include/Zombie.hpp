#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define ANNOUNCE_MSG "BraiiiiiiinnnzzzZ..."

class Zombie {
public:
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    void    announce(void);
private:
    std::string  name;
};

Zombie  *zombieHorde(int N, std::string name);

#endif
