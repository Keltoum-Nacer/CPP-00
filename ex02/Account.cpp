/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:13:01 by knacer            #+#    #+#             */
/*   Updated: 2024/10/20 14:46:39 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include<iostream>
#include<ctime>
#include<iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGE    "\033[95m"
#define MAGENTA "\033[35m"
#define BLUE     "\033[94m"
#define CYAN    "\033[36m"
#define CY   "\033[96m"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

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
    _displayTimestamp();
    std::cout << CY <<"Accounts informations : " << RESET << std::endl;
    std::cout << "  -------------------------------------------------------------" << std::endl;
    std::cout << " | " << std::setw(12) << "NbAccounts" << " | "
                << std::setw(12) << "TotalAmount" << " | "
                << std::setw(12) << "NbDeposits" << " | "
                << std::setw(12) << "NbWithdrawals" << " | " << std::endl;
    std::cout << "  -------------------------------------------------------------" << std::endl;
    std::cout << " | " << CYAN << std::setw(12) << getNbAccounts() << RESET << " | "
                << CYAN << std::setw(12) << getTotalAmount() << RESET << " | "
                << CYAN << std::setw(12) << getNbDeposits() << RESET << " | "
                << CYAN << std::setw(12) << getNbWithdrawals() << RESET << "  | " << std::endl;
    std::cout << "  -------------------------------------------------------------" << std::endl << std::endl;
}

Account::Account( int initial_deposit )
{
    _displayTimestamp();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _nbAccounts++;
    _accountIndex = _nbAccounts;
    std::cout << "Account number " << _accountIndex << " with amount " << initial_deposit << " is created." << std::endl << std::endl;
}
Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "account number " << _accountIndex << " is deleted." << std::endl<< std::endl;
    _nbAccounts--;
}

Account:: Account(void)
{
    _displayTimestamp();
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _accountIndex = _nbAccounts;
    std::cout << "Account number " << _accountIndex << " is created." << std::endl << std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t curr_time;
    
    time(&curr_time);
    std::cout << BLUE << ctime(&curr_time) << RESET;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << "Deposit = " << deposit << std::endl;
    std::cout << "New amount = " << _amount << std::endl << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    if (_amount >= withdrawal)
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << "Withdrawals = " << withdrawal << std::endl;
        std::cout << "New amount = " << _amount << std::endl<< std::endl;
        return(true);
    }
    std::cout << "your amount is insufficient!" << std::endl<<std::endl;
    return(false);
}

int		Account::checkAmount( void ) const
{
    return(_amount);
}
    
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
        std::cout << MAGE << "Account's status : " << RESET << std::endl;
    std::cout << "  -------------------------------------------------------------" << std::endl;
    std::cout << " | " << std::setw(12) << "Account index" << " | "
            << std::setw(12) << "Amount" << " | "
            << std::setw(12) << "NbDeposits" << " | "
            << std::setw(12) << "NbWithdrawals" << " | " << std::endl;
    std::cout << "  -------------------------------------------------------------" << std::endl;
    std::cout << " | " << MAGENTA << std::setw(12) << _accountIndex << RESET << " | "
            << MAGENTA << std::setw(12) << checkAmount() << RESET << " | "
            << MAGENTA << std::setw(12) << _nbDeposits << RESET << " | "
            << MAGENTA << std::setw(12) << _nbWithdrawals << RESET << "  | " << std::endl;
    std::cout << "  -------------------------------------------------------------" << std::endl << std::endl;
}
