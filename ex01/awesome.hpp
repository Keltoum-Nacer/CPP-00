/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:48:42 by knacer            #+#    #+#             */
/*   Updated: 2024/10/09 10:16:06 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_HPP
#define AWESOME_HPP
#include<string>
#include<iostream>
#include<iomanip>
#include<cstdlib>

class contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_num;
        std::string darck_secret;
    public:
        contact()
        {
            this->first_name = "Unknown";
            this->last_name = "Unknown";
            this->nick_name = "Unknown";
            this->phone_num = "Unknown";
            this->darck_secret = "Unknown";   
        }
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
        phoneBook()
        {
            this->count = 0;
            this->old_indx = 0;
        }
        void add(std::string &f_name, std::string &l_name, std::string &n_name, std::string &phone_num, std::string &darck_secret);
        void search()const;
        void exit()const;
};

#endif