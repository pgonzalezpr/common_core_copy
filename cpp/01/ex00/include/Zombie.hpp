#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define ANNOUNCE_MSG "BraiiiiiiinnnzzzZ..."

using namespace std;

class Zombie
{
private:
    string  name;
public:
    Zombie(string name);
    ~Zombie(void);
    void    announce(void);
};

Zombie* newZombie(string name);
void    randomChump(string name);

#endif