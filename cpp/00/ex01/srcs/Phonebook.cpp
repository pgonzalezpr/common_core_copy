#include "Phonebook.hpp"

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

bool    Phonebook::isEmpty() const {
    return count == 0;
}

void    Phonebook::displayPhonebook() const {
    std::cout << std::setw(COLUMN_WIDTH) << std::right << "Index" << "|"
        << std::setw(COLUMN_WIDTH) << std::right << "First Name" << "|"
        << std::setw(COLUMN_WIDTH) << std::right << "Last Name" << "|"
        << std::setw(COLUMN_WIDTH) << std::right << "Nickname" << std::endl;

    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(COLUMN_WIDTH) << std::right << i << "|"
            << std::setw(COLUMN_WIDTH) << std::right 
            << formatField(list[i].getFirstName()) << "|"
            << std::setw(COLUMN_WIDTH) << std::right 
            << formatField(list[i].getLastName()) << "|"
            << std::setw(COLUMN_WIDTH) << std::right 
            << formatField(list[i].getNickname()) << std::endl;
    }
}

void    Phonebook::displayContactByIndex(int index) const {
    if (index >= count)
        return ;
    list[index].displayContact();
}

std::string  Phonebook::formatField(const std::string& str) const {
    if (str.length() > COLUMN_WIDTH) {
        return str.substr(0, COLUMN_WIDTH - 1) + ".";
    } else {
        return str;
    }
}
