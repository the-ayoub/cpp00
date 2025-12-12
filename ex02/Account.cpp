#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount = _totalAmount + initial_deposit;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
}
void	Account::_displayTimestamp( void )
{
	char buffer[80];
	std::time_t now = std::time(NULL);
	std::tm* local = std::localtime(&now);
	std::strftime(buffer, 80, "[%Y%m%d_%H%M%S]", local);
	std::cout<<buffer<<" ";
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout<<"accounts:"<<_nbAccounts<<";total:"<<_totalAmount<<";deposits:"<<_totalNbDeposits<<";withdrawals:"<<_totalNbWithdrawals<<std::endl;
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = _amount;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_nbDeposits++;
	_amount += deposit;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<p_amount<<";deposit:"<<deposit<<";amount:"<<_amount<<";nb_deposits:"<<_nbDeposits<<std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	if(withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:refused"<<std::endl;
		return false;
	}
	else
	{
		int p_amount = _amount;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_amount -= withdrawal;
		_displayTimestamp();
		std::cout<<"index:"<<_accountIndex<<";p_amount:"<<p_amount<<";withdrawal:"<<withdrawal<<";amount:"<<_amount<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
	}
	return true;
}
int Account::checkAmount( void ) const
{
    return _amount;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
}