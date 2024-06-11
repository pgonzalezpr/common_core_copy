#ifndef MATERIABAG_HPP
#define MATERIABAG_HPP

#include "AMateria.hpp"
#include <iostream>

#define DEFAULT_SIZE 5
class MateriaBag {
public:
    MateriaBag();
    MateriaBag(const MateriaBag& other);
    MateriaBag& operator=(const MateriaBag& other);
    ~MateriaBag();

    void add(AMateria *m);
    AMateria *cloneMateria(int idx) const;

    int getSize() const;
    int getNext() const;

private:
    AMateria **_materias;
    int _size;
    int _next;
    bool _isInit;

    bool contains(AMateria *m) const;
    void resize();
    void initMaterias();
    void cleanMaterias();
    bool isIndexValid(int idx) const;
};

#endif