#ifndef CURE_HPP
#define CURE_HPP

#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria {
public:
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();
    AMateria *clone() const;
    void use(ICharacter& target);
};

#endif