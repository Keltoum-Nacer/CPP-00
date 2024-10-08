#include "phoneBook.hpp"
#include<iostream>

void phoneBook::add(std::string first_name, std::string last_name, std::string nick_name, std::string phone_num, std::string dark_secret)
{
    if (count < 8)
    {
        contacts[count].setFirst_name(first_name);
        contacts[count].setLast_name(last_name);
        contacts[count].setNick_name(nick_name);
        contacts[count].setPhone_num(phone_num);
        contacts[count].setDarck_secret(darck_secret);
        count++;
    }
    else
    {
        contacts[old_indx].setFirst_name(first_name);
        contacts[old_indx].setLast_name(last_name);
        contacts[old_indx].setNick_name(nick_name);
        contacts[old_indx].setPhone_num(phone_num);
        contacts[old_indx].setDarck_secret(darck_secret);
        old_indx = (old_indx + 1) % 8;
    }
}

std::string truncate(std::string &name)
{
    if (name.length() > 10)
        return name.substr(0, 9) + ".";
    return name;
}

void phoneBook::search() const
{
    int indx = 0;

    if (count == 0)
    {
        std::cerr << "contacts are unvailable!" << std::endl;
        return;
    }
    while(indx < count)
    {
        std::cout << std::setw(10) << indx << " | " 
                << std::setw(10) << truncate(contacts[indx].getFirst_name()) << " | " 
                << std::setw(10) << truncate(contacts[indx].getLast_name())<< " | " 
                << std::setw(10) << truncate(contacts[indx].getNick_name())<< std::endl;
        indx++;
    }
    std::cout << "enter the index of the contact want to search : "
    std::cin >> indx;
    if(indx < 0 || indx > count)
    {
        std::cerr << "error, index is invalid!" <<std::endl;
        return;
    }
    std::cout << "Index : " << indx << std::endl;
    std::cout << "First Name : " << contacts[indx].getFirst_name() << std::endl;
    std::cout << "Last Name : " << contacts[indx].getLast_name() << std::endl;
    std::cout << "Nick Name : " << contacts[indx].getNick_name() << std::endl;
    std::cout << "Phone Number : " << contacts[indx].getPhone_num() << std::endl;
    std::cout << "Darck Secret : " << contacts[indx].getDarck_secret() << std::endl; 
}

void phoneBook::exit() const
{
    std:: exit(0);
}

int main()
{
    phoneBook contact;
    std::string command;
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_num;
    std::string darck_secret;

    while(1)
    {
        std::cout << "COMMAND : ";
        std::cin >> command;
        if (!command.compare("ADD"))
        {
            std::cout << "First Name : "
            std::cin >> first_name >>std::endl;
            std::cout << "Last Name : "
            std::cin >> last_name >>std::endl;
            std::cout << "Nick Name : "
            std::cin >> nick_name >>std::endl;
            std::cout << "Phone Number : "
            std::cin >> phone_num >>std::endl;
            std::cout << "Darck Secret : "
            std::cin >> darck_secret >>std::endl;
            contact.add(first_name, last_name, nick_name, phone_num, darck_secret);
        }
        else if (!command.compare("SEARCH"))
            contact.search();
        else if (!command.compare("EXIT"))
            contact.exit();
        else
            std::cerr << "Enter the right command!" << std::endl;

    }
}