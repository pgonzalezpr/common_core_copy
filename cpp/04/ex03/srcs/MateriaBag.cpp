#include "MateriaBag.hpp"

MateriaBag::MateriaBag() : _size(DEFAULT_SIZE) , _next(0) {
    initMaterias();
    this->_isInit = true;
}

MateriaBag::MateriaBag(const MateriaBag& other) {
    this->_isInit = false;
    *this = other;
}

MateriaBag& MateriaBag::operator=(const MateriaBag& other) {
    if (this == &other)
        return *this;
    if (this->_isInit)
        cleanMaterias();
    this->_size = other.getSize();
    this->_next = other.getNext();
    initMaterias();
    for (int i = 0; i < this->_next; i++) {
        this->_materias[i] = other.cloneMateria(i);
    }
    return *this;
}

MateriaBag::~MateriaBag() {
    cleanMaterias();
}

void MateriaBag::add(AMateria *m) {
    if (m == NULL || contains(m))
        return;
    if (this->_next >= this->_size)
        resize();
    this->_materias[this->_next] = m;
    this->_next++;
}

bool MateriaBag::contains(AMateria *m) const {
    if (!m)
        return false;
    for (int i = 0; i < this->_next; i++) {
        if (this->_materias[i] == m)
            return true;
    }
    return false;
}

void MateriaBag::resize() {
    AMateria **old = this->_materias;
    this->_size *= 2;
    initMaterias();
    for (int i = 0; i < this->_next; i++) {
        this->_materias[i] = old[i];
    }
    this->_next++;
    delete[] old;
}

void MateriaBag::initMaterias() {
    this->_materias = new AMateria*[this->_size];
    for (int i = 0; i < this->_size; i++) {
        this->_materias[i] = NULL;
    }
}

void MateriaBag::cleanMaterias() {
    for (int i = 0; i < this->_next; i++) {
        delete this->_materias[i];
    }
    delete[] this->_materias;
}

AMateria *MateriaBag::cloneMateria(int idx) const {
    if (!isIndexValid(idx))
        return NULL;
    return this->_materias[idx]->clone();
}

bool MateriaBag::isIndexValid(int idx) const {
    return idx >= 0 && idx < this->_size && this->_materias[idx] != NULL;
}

int MateriaBag::getSize() const { return this->_size; }

int MateriaBag::getNext() const { return this->_next; }
