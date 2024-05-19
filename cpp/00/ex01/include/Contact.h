#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

using namespace std;

class   Contact {
    public:
        Contact(const string& firstName = "", const string& lastName = "",
            const string& nickname = "", const string& phoneNumber = "",
            const string& darkestSecret = "");

        string  getFirstName() const;
        string  getLastName() const;
        string  getNickname() const;
        string  getPhoneNumber() const;
        string  getDarkestSecret() const;
        void    displayContact() const;

    private:
        string  firstName;
        string  lastName;
        string  nickname;
        string  phoneNumber;
        string  darkestSecret;
};

#endif 