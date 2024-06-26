#include "Contact.hpp"
#include "Phonebook.hpp"
#include "Utils.hpp"
#include <sstream>
#include <stdlib.h>

# define ADD_CMD "ADD"
# define SEARCH_CMD "SEARCH"
# define EXIT_CMD "EXIT"

void    search(const Phonebook& phonebook) {
    std::string  input;

    std::cout << std::endl;
    phonebook.displayPhonebook();
    std::cout << std::endl;
    if (phonebook.isEmpty())
        return ;
    while (1) {
        input = readField("Enter contact index: ");
        if (is_numeric(input) && phonebook.isIndexValid(stringToInt(input)))
            break;
        else
            std::cout << "Invalid index. Try again" << std::endl;
    }
    std::cout << std::endl;
    phonebook.displayContactByIndex(stringToInt(input));
}

void    add(Phonebook& phonebook) {
    std::cout << std::endl;
    std::string  firstName = readField("Enter first name: ");
    std::string  lastName = readField("Enter last name: ");
    std::string  nickname = readField("Enter nickname: ");

    std::string  phoneNumber;
    while (1) {
        phoneNumber = readField("Enter phone number: ");
        if (is_numeric(phoneNumber))
            break;
        else
            std::cout << "Invalid phone number. Try again" << std::endl;
    }
    std::string  darkestSecret = readField("Enter darkest secret: ");

    phonebook.addContact(Contact(firstName, lastName, nickname, phoneNumber,
        darkestSecret));
}

int main() {
    std::string      cmd;
    Phonebook   phonebook;

    while (1) {
        std::cout << "Enter command: ";
        getline(std::cin, cmd);
        if (std::cin.eof())
            exit(EXIT_SUCCESS);
        if (!cmd.compare(ADD_CMD))
            add(phonebook);
        else if (!cmd.compare(SEARCH_CMD))
            search(phonebook);
        else if (!cmd.compare(EXIT_CMD))
            exit(0);
        else 
            std::cout << "Unknown command. Please enter ADD, SEARCH, or EXIT.";
        std::cout << std::endl;
    }
}
