#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

using namespace std;

class Weapon {
public:
    Weapon(const string &type);
    const string&   getType() const;
    void            setType(const string &newType);
private:
    string  type;
};

#endif