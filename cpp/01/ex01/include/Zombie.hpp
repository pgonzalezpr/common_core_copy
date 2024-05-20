#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define ANNOUNCE_MSG "BraiiiiiiinnnzzzZ..."

using namespace std;

class Zombie {
private:
    string  name;
public:
    Zombie(void);
    Zombie(string name);
    ~Zombie(void);
    void    announce(void);
};

Zombie  *zombieHorde(int N, string name);

#endif