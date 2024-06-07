#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define SIZE 100

class Brain
{
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();
    void        setIdeaAtIndex(std::string str, size_t idx);
    std::string getIdeaAtIndex(size_t idx);
private:
    std::string _ideas[SIZE];
};

#endif