#include "Zombie.hpp"

int main(void) {
    Zombie  *zombie_ptr;

    zombie_ptr = newZombie("heap_zombie");
    (*zombie_ptr).announce();
    randomChump("first_stack_zombie");
    randomChump("second_stack_zombie");
    std::cout << "Deleting heap zombie" << std::endl;
    delete(zombie_ptr);
    return 0;
}
