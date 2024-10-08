#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class phoneBook
{
    private:
        Contact contacts[8];
        int count = 0;
        int old_indx = 0;
    public:
        void add(std::string &fname, std::string &lname, std::string &nname, std::string &phone, std::string &secret);
        void search();
        void exit();
}

#endif