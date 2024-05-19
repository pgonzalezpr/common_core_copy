#include "Phonebook.h"

Phonebook::Phonebook() : count(0), oldestIndex(0) {}

void    Phonebook::addContact(const Contact& contact) {
    if (count < MAX_CONTACTS)
        list[count++] = contact;
    else {
        list[oldestIndex] = contact;
        oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;
    }
}

bool    Phonebook::isIndexValid(int index) const {
    return index >= 0 && index < count;
}

void    Phonebook::displayPhonebook() const {
    cout << setw(COLUMN_WIDTH) << right << "Index" << "|"
        << setw(COLUMN_WIDTH) << right << "First Name" << "|"
        << setw(COLUMN_WIDTH) << right << "Last Name" << "|"
        << setw(COLUMN_WIDTH) << right << "Nickname" << endl;

    for (int i = 0; i < count; ++i) {
        cout << setw(COLUMN_WIDTH) << right << i << "|"
            << setw(COLUMN_WIDTH) << right 
            << formatField(list[i].getFirstName()) << "|"
            << setw(COLUMN_WIDTH) << right 
            << formatField(list[i].getLastName()) << "|"
            << setw(COLUMN_WIDTH) << right 
            << formatField(list[i].getNickname()) << endl;
    }
}

void    Phonebook::displayContactByIndex(int index) const {
    if (index >= count)
        return ;
    list[index].displayContact();
}

string  Phonebook::formatField(const string& str) const {
    if (str.length() > COLUMN_WIDTH) {
        return str.substr(0, COLUMN_WIDTH - 1) + ".";
    } else {
        return str;
    }
}