#include "Contact.hpp"

Contact::Contact(const std::string& firstName, const std::string& lastName,
            const std::string& nickname, const std::string& phoneNumber,
            const std::string& darkestSecret) : firstName(firstName),
            lastName(lastName), nickname(nickname), phoneNumber(phoneNumber),
            darkestSecret(darkestSecret) {};

std::string  Contact::getFirstName() const { return firstName; }

std::string  Contact::getLastName() const { return lastName; }

std::string  Contact::getNickname() const { return nickname; }

std::string  Contact::getPhoneNumber() const { return phoneNumber; }

std::string  Contact::getDarkestSecret() const { return darkestSecret; }

void    Contact::displayContact() const { 
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
