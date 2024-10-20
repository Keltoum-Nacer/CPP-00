/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:00:16 by knacer            #+#    #+#             */
/*   Updated: 2024/10/21 15:59:18 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main(int ac, char **av)
{
    if (ac >=2)
    {
        int i = 1;
        while (av[i])
        {
            int j = 0;
            while(av[i][j])
            {
                av[i][j] = toupper(av[i][j]);
                j++;
            }
            std::cout << av[i] << " ";
            i++;
        }
        std::cout << std::endl;
    }
    else
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}