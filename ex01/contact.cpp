/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:13:03 by knacer            #+#    #+#             */
/*   Updated: 2024/10/09 10:15:22 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awesome.hpp"

std::string contact::getFirst_name()const
{
    return(first_name);
}

std::string contact::getLast_name()const
{
    return(last_name);
}

std::string contact::getNick_name()const
{
    return(nick_name);
}

std::string contact::getPhone_num()const
{
    return(phone_num);
}

std::string contact::getDarck_secret()const
{
    return(first_name);
}

void contact::setFirst_name(std::string &fname)
{
    first_name = fname;
}

void contact::setLast_name(std::string &lname)
{
    last_name = lname;
}

void contact::setNick_name(std::string &nname)
{
    nick_name = nname;
}

void contact::setPhone_num(std::string &phoneNum)
{
    phone_num = phoneNum;
}

void contact::setDarck_secret(std::string &secret)
{
    darck_secret = secret;
}