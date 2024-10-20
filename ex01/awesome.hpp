/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:48:42 by knacer            #+#    #+#             */
/*   Updated: 2024/10/21 16:06:34 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_HPP
#define AWESOME_HPP
#include<string>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<limits>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[92m"
#define YELLOW  "\033[33m"
#define MAGE    "\033[95m"
#define MAGENTA "\033[35m"
#define BLUE     "\033[94m"
#define CYAN    "\033[36m"
#define CY   "\033[96m"

class contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_num;
        std::string darck_secret;
    public:
        contact();
        std::string getFirst_name()const;
        std::string getLast_name()const;
        std::string getNick_name()const;
        std::string getPhone_num()const;
        std::string getDarck_secret()const;
        void setFirst_name(std::string &fname);
        void setLast_name(std::string &lname);
        void setNick_name(std::string &nname);
        void setPhone_num(std::string &phoneNum);
        void setDarck_secret(std::string &secret);
};    

class phoneBook
{
    private:
        contact contacts[8];
        int count;
        int old_indx ;
    public:
        phoneBook();
        void add(std::string &f_name, std::string &l_name, std::string &n_name, std::string &phone_num, std::string &darck_secret);
        void search()const;
        void exit()const;
};

#endif