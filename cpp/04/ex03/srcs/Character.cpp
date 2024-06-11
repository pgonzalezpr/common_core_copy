#include "Character.hpp"

Character::Character() : _name("default"), _nextSlot(0) {
    this->_bag = new MateriaBag();
    initInventory();
    this->_isInit = true;
}

Character::Character(const std::string& name) : _name(name), _nextSlot(0) {
    this->_bag = new MateriaBag();
    initInventory();
    this->_isInit = true;
}

Character::Character(const Character& other) {
    this->_isInit = false;
    *this = other;
}

Character& Character::operator=(const Character& other) {
    if (this == &other)
        return *this;
    if (this->_isInit) {
        cleanInventory();
        delete this->_bag;
    }
    this->_name = other.getName();
    this->_nextSlot = other.getNextSlot();
    this->_bag = new MateriaBag();
    for (int i = 0; i < inventorySize; i++) {
        this->_inventory[i] = other.cloneMateria(i);
    }
    this->_isInit = true;
    return *this;
}

Character::~Character() {
    cleanInventory();
    delete(this->_bag);
}

void Character::equip(AMateria  *m) {
    if (m == NULL || this->_nextSlot == -1) {
        this->_bag->add(m);
        return;
    }
    this->_inventory[this->_nextSlot] = m;
    updateNextSlot();
}

void Character::unequip(int idx) {
    if (!isIndexValid(idx))
        return;
    this->_bag->add(this->_inventory[idx]);
    this->_inventory[idx] = NULL;
    updateNextSlot();
}

void Character::use(int idx, ICharacter& target) {
    if (!isIndexValid(idx))
        return;
    this->_inventory[idx]->use(target);
}

AMateria *Character::cloneMateria(int idx) const {
    if (!isIndexValid(idx))
        return NULL;
    return this->_inventory[idx]->clone();
}

void Character::updateNextSlot() {
    for (int i = 0; i < inventorySize; i++) {
        if (this->_inventory[i] == NULL) {
            this->_nextSlot = i;
            return;
        }
    }
    this->_nextSlot = -1;
}

bool Character::isIndexValid(int idx) const {
    return idx >= 0 && idx < inventorySize && this->_inventory[idx] != NULL;
}

void Character::initInventory() {
    for (int i = 0; i < inventorySize; i++) {
        this->_inventory[i] = NULL;
    }
}

void Character::cleanInventory() {
    for (int i = 0; i < inventorySize; i++) {
        if(this->_inventory[i] != NULL) {
            this->_bag->add(this->_inventory[i]);
            this->_inventory[i] = NULL;
        }
    }
}

void Character::printMaterias() const {
	std::string materia;
	for (int i = 0; i < inventorySize; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			materia = this->_inventory[i]->getType();
			std::cout << this->_name << " materia " << i << " is " << materia << std::endl;
		}
	}
}

std::string const & Character::getName() const { return this->_name; }

int Character::getNextSlot() const { return this->_nextSlot; }

void Character::setName(const std::string& name) { this->_name = name; }

