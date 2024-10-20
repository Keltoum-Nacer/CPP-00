/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:43:52 by knacer            #+#    #+#             */
/*   Updated: 2024/10/20 16:20:48 by knacer           ###   ########.fr       */
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
    std::cout << "  -----------------------------------------------------" << std::endl;
    while (indx < count)
    {
        std::cout << " | " << std::setw(10) << GREEN << indx << RESET<< " | "
                    << std::setw(10) << trunc(contacts[indx].getFirst_name()) << " | "
                    << std::setw(10) << trunc(contacts[indx].getLast_name()) << " | "
                    << std::setw(10) << trunc(contacts[indx].getNick_name()) << " | " << std::endl;
        std::cout << "  ----------------------------------------------------" << std::endl;
        indx++;
    }
    std::cout << "Enter the index of the contact you want to search for : " ;
    std::cin >> indx;
    if (indx < 0 || indx >= count)
    {
        std::cerr << RED << "the conatct is unvailable!" << RESET << std::endl;
        return;
    }
    std::cout << std::setw(18) << "First Name : " << CYAN << contacts[indx].getFirst_name() << RESET << std::endl;
    std::cout << std::setw(18) << "Last Name : " << CYAN << contacts[indx].getLast_name() << RESET << std::endl;
    std::cout << std::setw(18) << "Nick Name : " << CYAN << contacts[indx].getNick_name() << RESET << std::endl;
    std::cout << std::setw(18) << "Phone Number : " << CYAN << contacts[indx].getPhone_num() << RESET << std::endl;
    std::cout << std::setw(18) << "Darck Secret : "  << CYAN << contacts[indx].getDarck_secret() << RESET << std::endl;
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
        std::cout << "COMMAND : " << RED ;
        //std::cin  >> command ;
        if (!(std::cin >> command)) 
        {
            if (std::cin.eof()) 
                break; 
        }
        std::cout << RESET;
        if (!command.compare("ADD"))
        {
            std::cout << GREEN << "First Name : " << RESET;
            std::cin >> fname;
            std::cout << GREEN << "Last Name : " << RESET;
            std::cin >> lname;
            std::cout << GREEN << "Nick Name : " << RESET;
            std::cin >> nname;
            std::cout << GREEN << "Phone Number : " << RESET;
            std::cin >> phone;
            std::cout << GREEN << "Darck Secret : " << RESET;
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
