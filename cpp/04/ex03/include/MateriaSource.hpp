#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <iostream>

#define MAX_MATERIA 4

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const & type);
    int getNext() const;
    void printMaterias() const; 
private:
    int _next;

    AMateria *_learnedMaterias[MAX_MATERIA];
    void initMaterias();
    void cleanMaterias();
    AMateria *cloneMateria(int idx) const;
    bool isIndexValid(int idx) const;
};

#endif