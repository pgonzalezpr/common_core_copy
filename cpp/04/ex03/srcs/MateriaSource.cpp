#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _next(0) {
    initMaterias();
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    MateriaSource();
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this == &other)
        return *this;
    cleanMaterias();
    this->_next = other.getNext();
    for (int i = 0; i < MAX_MATERIA; i++) {
        this->_learnedMaterias[i] = other.cloneMateria(i);
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    cleanMaterias();
}

void MateriaSource::learnMateria(AMateria *m) {
    if (m == NULL || this->_next >= MAX_MATERIA)
        return;
    this->_learnedMaterias[this->_next] = m;
    this->_next++;
}

AMateria *MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < this->_next; i++) {
        if (this->_learnedMaterias[i]->getType() == type)
            return this->_learnedMaterias[i]->clone();
    }
    return NULL;
}

void MateriaSource::initMaterias() {
    for (int i = 0; i < MAX_MATERIA; i++) {
        this->_learnedMaterias[i] = NULL;
    }
}

void MateriaSource::cleanMaterias() {
    for (int i = 0; i < _next; i++) {
        delete this->_learnedMaterias[i];
    }
}

AMateria *MateriaSource::cloneMateria(int idx) const {
    if (!isIndexValid(idx))
        return NULL;
    return this->_learnedMaterias[idx]->clone();
}

bool MateriaSource::isIndexValid(int idx) const {
    return idx >= 0 && idx <= MAX_MATERIA && this->_learnedMaterias[idx] != NULL;
}

int MateriaSource::getNext() const { return this->_next; }

void MateriaSource::printMaterias() const {
	std::string materia;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_learnedMaterias[i] != NULL)
		{
			materia = this->_learnedMaterias[i]->getType();
			std::cout << "MateriaSource " << " materia " << i << " is " << materia << std::endl;
		}
	}
}