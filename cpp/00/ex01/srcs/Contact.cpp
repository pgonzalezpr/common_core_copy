#include "Contact.h"

Contact::Contact(const string& firstName, const string& lastName,
            const string& nickname, const string& phoneNumber,
            const string& darkestSecret) : firstName(firstName),
            lastName(lastName), nickname(nickname), phoneNumber(phoneNumber),
            darkestSecret(darkestSecret) {};

string  Contact::getFirstName() const { return firstName; }

string  Contact::getLastName() const { return lastName; }

string  Contact::getNickname() const { return nickname; }

string  Contact::getPhoneNumber() const { return phoneNumber; }

string  Contact::getDarkestSecret() const { return darkestSecret; }

void    Contact::displayContact() const { 
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Nickname: " << nickname << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Darkest Secret: " << darkestSecret << endl;
}