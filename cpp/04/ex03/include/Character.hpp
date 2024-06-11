#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "MateriaBag.hpp"
#include <iostream>

#define inventorySize 4

class Character : public ICharacter {
public:
    Character();
    Character(const std::string& name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    void equip(AMateria  *m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    AMateria *cloneMateria(int idx) const;

    std::string const & getName() const;
    int getNextSlot() const;
    void printMaterias() const; 
    void setName(const std::string& name);
private:
    std::string _name;
    AMateria *_inventory[inventorySize];
    MateriaBag *_bag;
    int _nextSlot;
    bool _isInit;

    void updateNextSlot();
    bool isIndexValid(int idx) const;
    void initInventory();
    void cleanInventory();
};

#endif
