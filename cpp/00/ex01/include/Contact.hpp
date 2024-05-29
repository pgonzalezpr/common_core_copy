#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class   Contact {
    public:
        Contact(const std::string& firstName = "", const std::string& lastName = "",
            const std::string& nickname = "", const std::string& phoneNumber = "",
            const std::string& darkestSecret = "");

        std::string  getFirstName() const;
        std::string  getLastName() const;
        std::string  getNickname() const;
        std::string  getPhoneNumber() const;
        std::string  getDarkestSecret() const;
        void    displayContact() const;

    private:
        std::string  firstName;
        std::string  lastName;
        std::string  nickname;
        std::string  phoneNumber;
        std::string  darkestSecret;
};

#endif 