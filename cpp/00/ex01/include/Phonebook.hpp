#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <string>

# define MAX_CONTACTS 8
# define COLUMN_WIDTH 10

class   Phonebook {
    public:
        Phonebook();
        void    addContact(const Contact& contact);
        bool    isIndexValid(int index) const;
        bool    isEmpty() const;
        void    displayPhonebook() const;
        void    displayContactByIndex(int index) const;

    private:
        Contact list[MAX_CONTACTS];
        int     count;
        int     oldestIndex;

        std::string  formatField(const std::string& str) const;
};

#endif