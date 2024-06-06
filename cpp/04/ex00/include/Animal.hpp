#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType() const;
    void setType(std::string& type);
protected:
    std::string _type;
};

#endif