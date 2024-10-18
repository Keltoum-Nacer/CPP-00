/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:13:01 by knacer            #+#    #+#             */
/*   Updated: 2024/10/16 10:32:18 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include<iostream>

int	Account::getNbAccounts( void )
{
    return(_nbAccounts);
}
int	Account::getTotalAmount( void )
{
    return(_totalAmount);
}
int	Account::getNbDeposits( void )
{
    return(_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
    return(_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
    std::cout << "Accounts informations : " << std::endl;
    std::cout << "NbAccounts : " << getNbAccounts() << std::endl;
    std::cout << "TotalAmount : " << getTotalAmount() << std::endl;
    std::cout << "NbDeposits : " << getNbDeposits() << std::endl;
    std::cout << "NbWithdrawals : " << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
    
}
~Account( void );
