/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:43:52 by knacer            #+#    #+#             */
/*   Updated: 2024/10/09 10:17:17 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awesome.hpp"

void phoneBook::add(std::string &fname, std::string &lname, std::string &nname, std::string &phone, std::string &secret)
{
    if( count < 8)
    {
        contacts[count].setFirst_name(fname);
        contacts[count].setLast_name(lname);
        contacts[count].setNick_name(nname);
        contacts[count].setPhone_num(phone);
        contacts[count].setDarck_secret(secret);
        count++;
    }
    else
    {
        contacts[old_indx].setFirst_name(fname);
        contacts[old_indx].setLast_name(lname);
        contacts[old_indx].setNick_name(nname);
        contacts[old_indx].setPhone_num(phone);
        contacts[old_indx].setDarck_secret(secret);
        old_indx = (old_indx + 1) % 8;
    }
}

std::string trunc(std::string name)
{
    if (name.length() > 10)
        return (name.substr(0, 9) + ".");
    return (name);
}

void phoneBook::search() const
{
    int indx = 0;
    
    if (count == 0)
    {
        std::cerr << "contacts are unvailable!" << std::endl;
        return;
    }
    while (indx < count)
    {
        std::cout << std::setw(10) << indx << " | "
                    << std::setw(10) << trunc(contacts[indx].getFirst_name()) << " | "
                    << std::setw(10) << trunc(contacts[indx].getLast_name()) << " | "
                    << std::setw(10) << trunc(contacts[indx].getNick_name()) << std::endl;
        indx++;
    }
    std::cout << "Enter the index of the contact you want to search for : " ;
    std::cin >> indx;
    if (indx < 0 || indx >= count)
    {
        std::cerr << "the conatct is unvailable!" << std::endl;
        return;
    }
    std::cout << "First Name : " << contacts[indx].getFirst_name() << std::endl;
    std::cout << "Last Name : " << contacts[indx].getLast_name() << std::endl;
    std::cout << "Nick Name : " << contacts[indx].getNick_name() << std::endl;
    std::cout << "Phone Number : " << contacts[indx].getPhone_num() << std::endl;
    std::cout << "Darck Secret : " << contacts[indx].getDarck_secret() << std::endl;
}

void phoneBook::exit() const
{
    std::exit(0);
}

int main()
{
    phoneBook cont;
    std::string command;
    std::string fname;
    std::string lname;
    std::string nname;
    std::string phone;
    std::string secret;
    
    while(1)
    {
        std::cout << "COMMAND : ";
        std::cin >> command ;
        if (!command.compare("ADD"))
        {
            std::cout << "i am here" << std::endl;
            std::cout << "First Name : ";
            std::cin >> fname;
            std::cout << "Last Name : ";
            std::cin >> lname;
            std::cout << "Nick Name : ";
            std::cin >> nname;
            std::cout << "Phone Number : ";
            std::cin >> phone;
            std::cout << "Darck Secret : ";
            std::cin >> secret;
            cont.add(fname, lname, nname, phone, secret);
        }
        else if (!command.compare("SEARCH"))
            cont.search();
        else if (!command.compare("EXIT"))
            cont.exit();
        else
            std::cerr << "error, enter the right comand." << std::endl;
    }
    
}
