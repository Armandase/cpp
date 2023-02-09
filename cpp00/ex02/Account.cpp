#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <sstream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount; 
	_nbWithdrawals = 0;	
	_nbDeposits = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amout:" << _amount <<";created" << std::endl;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amout:" << _amount <<";closed" << std::endl;
}

void	Account::_displayTimestamp(void){
	std::time_t	t;
	struct tm	*time;
	std::stringstream date;

	t = std::time(0);
	time = std::localtime(&t);
	date << "[";
	date << (time->tm_year + 1900);
	date << (time->tm_mon + 1);
	date << (time->tm_mday);
	date << "_";
	date << (time->tm_hour);
	date << (time->tm_min);
	date << (time->tm_sec);
	std::cout << date.str() << "] ";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:"<< _totalAmount;
	std::cout << ";deposits:"<< _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amout:"<< _amount;
	std::cout << ";deposits:"<< _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:"<< _amount;
	std::cout << ";deposit:"<< deposit;
	_amount += deposit;
	_nbDeposits ++;
	std::cout << ";amount:" << _amount;
	std::cout << "nb_deposits:"<< _nbDeposits <<std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:"<< _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (1);
	}
	std::cout << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	std::cout << ";amount:"<< _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (0);
}
