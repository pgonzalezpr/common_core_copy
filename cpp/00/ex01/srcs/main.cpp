#include "Contact.hpp"
#include "Phonebook.hpp"
#include "Utils.hpp"
#include <sstream>
#include <stdlib.h>

# define ADD_CMD "ADD"
# define SEARCH_CMD "SEARCH"
# define EXIT_CMD "EXIT"

void    search(const Phonebook& phonebook) {
    string  input;

    cout << endl;
    phonebook.displayPhonebook();
    cout << endl;
    if (phonebook.isEmpty())
        return ;
    while (1) {
        input = readField("Enter contact index: ");
        if (is_numeric(input) && phonebook.isIndexValid(stringToInt(input)))
            break;
        else
            cout << "Invalid index. Try again" << endl;
    }
    cout << endl;
    phonebook.displayContactByIndex(stringToInt(input));
}

void    add(Phonebook& phonebook) {
    cout << endl;
    string  firstName = readField("Enter first name: ");
    string  lastName = readField("Enter last name: ");
    string  nickname = readField("Enter nickname: ");

    string  phoneNumber;
    while (1) {
        phoneNumber = readField("Enter phone number: ");
        if (is_numeric(phoneNumber))
            break;
        else
            cout << "Invalid phone number. Try again" << endl;
    }
    string  darkestSecret = readField("Enter darkest secret: ");

    phonebook.addContact(Contact(firstName, lastName, nickname, phoneNumber,
        darkestSecret));
}

int main() {
    string      cmd;
    Phonebook   phonebook;

    while (1) {
        cout << "Enter command: ";
        getline(cin, cmd);
        if (!cmd.compare(ADD_CMD))
            add(phonebook);
        else if (!cmd.compare(SEARCH_CMD))
            search(phonebook);
        else if (!cmd.compare(EXIT_CMD))
            exit(0);
        else 
            cout << "Unknown command. Please enter ADD, SEARCH, or EXIT.";
        cout << endl;
    }
}