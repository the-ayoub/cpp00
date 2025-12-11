#include "Account.hpp"
#include <iostream>


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