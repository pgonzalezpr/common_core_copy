#include "Contact.h"
#include "Phonebook.h"
#include "Utils.h"
#include <sstream>
#include <stdlib.h>

# define ADD_CMD "ADD"
# define SEARCH_CMD "SEARCH"
# define EXIT_CMD "EXIT"

void    search(const Phonebook& phonebook) {
    string  input;
    int     index;

    cout << endl;
    phonebook.displayPhonebook();
    cout << endl;
    if (phonebook.isEmpty())
        return ;
    while (1) {
        input = readField("Enter contact index: ");
        index = stringToInt(input);
        if (phonebook.isIndexValid(index))
            break;
        else
            cout << "Invalid index. Try again" << endl;
    }
    cout << endl;
    phonebook.displayContactByIndex(index);
}

void    add(Phonebook& phonebook) {
    cout << endl;
    string  firstName = readField("Enter first name: ");
    string  lastName = readField("Enter last name: ");
    string  nickname = readField("Enter nickname: ");
    string  phoneNumber = readField("Enter phone number: ");
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