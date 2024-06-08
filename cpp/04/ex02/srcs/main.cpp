#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    {
        size_t size = 4;
        Animal  *animals[size];

        std::cout << "-----------------------------------" << std::endl;

        Dog first_dog;
        first_dog.getBrain()->setIdeaAtIndex("Great idea", 0);
        first_dog.getBrain()->setIdeaAtIndex("Wrong idea", 1);
        first_dog.getBrain()->setIdeaAtIndex("Good idea", 2);

        Dog second_dog(first_dog);
        second_dog.getBrain()->setIdeaAtIndex("Second great idea", 0);
        second_dog.getBrain()->setIdeaAtIndex("Second wrong idea", 1);
        second_dog.getBrain()->setIdeaAtIndex("Second good idea", 2);

        std::cout << first_dog.getBrain()->getIdeaAtIndex(0) << std::endl;
        std::cout << first_dog.getBrain()->getIdeaAtIndex(1) << std::endl;
        std::cout << first_dog.getBrain()->getIdeaAtIndex(2) << std::endl;

        std::cout << second_dog.getBrain()->getIdeaAtIndex(0) << std::endl;
        std::cout << second_dog.getBrain()->getIdeaAtIndex(1) << std::endl;
        std::cout << second_dog.getBrain()->getIdeaAtIndex(2) << std::endl;

        std::cout << "-----------------------------------" << std::endl;

        
        for (size_t i = 0; i < size / 2; i++) {
            animals[i] = new Dog();
        }

        for (size_t i = size / 2; i < size; i++) {
            animals[i] = new Cat();
        }

        for (size_t i = 0; i < size; i++) {
            animals[i]->makeSound();
        }

        std::cout << "-----------------------------------" << std::endl;

        for (size_t i = 0; i < size; i++) {
            delete animals[i];
        }

        std::cout << "-----------------------------------" << std::endl;

    }

    return 0;
}