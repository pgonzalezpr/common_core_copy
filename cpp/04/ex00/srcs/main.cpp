#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;

        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
    	const WrongAnimal* a = new WrongCat();
        std::cout << a->getType() << " " << std::endl;
        a->makeSound();
        delete a;

        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        WrongCat b;
        std::cout << b.getType() << " " << std::endl;
        b.makeSound();
    }
    return 0;
}