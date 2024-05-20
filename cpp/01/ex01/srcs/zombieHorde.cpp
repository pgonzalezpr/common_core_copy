#include "Zombie.hpp"

Zombie  *zombieHorde(int N, string name) {
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        new (&zombies[i]) Zombie(name);
    }
    return zombies;
}
