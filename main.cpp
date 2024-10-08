#include "phoneBook.hpp"

contact :: void add(std::string first_name, std::string last_name, std::string nick_name, std::string phone_num, std::string dark_secret)
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
        old_indx++;
    }
}

contact :: void search()
{
    int indx;

    std::cin >> indx;
    while(indx < 0 || indx >= 8)
    {
        std::cerr << "error, enter another number!" <<std::endl;
        std::cin >> indx;
    }
    std::cout << indx << " | " << contacts[indx].getFirst_name() << " | " <<
                contacts[indx].getLast_name() << " | " << contacts[indx].getNick_name() << std::endl;
}

contact :: void exit()
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