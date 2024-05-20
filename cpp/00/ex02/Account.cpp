#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) { return _nbAccounts; }

int	Account::getTotalAmount( void ) { return _totalAmount; }

int	Account::getNbDeposits( void ) { return _totalNbDeposits; }

int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void    Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    cout << "accounts:" 
         << _nbAccounts
         << ";total:"
         << _totalAmount
         << ";deposits:"
         << _totalNbDeposits
         << ";withdrawals:"
         << _totalNbWithdrawals << endl;
}

void    Account::_displayTimestamp( void ) {
    time_t  current = time(0);
    tm      *local = localtime(&current);

    ostringstream output;
    output << '['
           << (local->tm_year + 1900)
           << std::setw(2) << std::setfill('0') << (local->tm_mon + 1)
           << std::setw(2) << std::setfill('0') << local->tm_mday
           << '_'
           << std::setw(2) << std::setfill('0') << local->tm_hour 
           << std::setw(2) << std::setfill('0') << local->tm_min
           << std::setw(2) << std::setfill('0') << local->tm_sec
           << ']';
    cout << output.str() << ' ';
}

Account::Account( int initial_deposit ) : _amount(initial_deposit) {
    _accountIndex = _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    cout << "index:"
         << _accountIndex
         << ";amount:"
         << _amount
         <<";created"
         << endl;
}

Account::~Account( void ) {
    _displayTimestamp();
    cout << "index:"
         << _accountIndex
         << ";amount:"
         << _amount
         << ";closed"
         << endl;
}

void	Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    cout << "index:"
         << _accountIndex
         << ";p_amount:"
         << _amount
         << ";deposit:"
         << deposit;
    _amount += deposit;
    _nbDeposits++;
    cout << ";amount:"
         << _amount
         << ";nb_deposits:"
         << _nbDeposits
         << endl;
    _totalNbDeposits++;
    _totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    cout << "index:"
         << _accountIndex
         << ";p_amount:"
         << _amount
         << ";withdrawal:";
    if (_amount >= withdrawal) {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        cout << withdrawal
             << ";amount:"
             << _amount
             << ";nb_withdrawals:"
             << _nbWithdrawals
             << endl;
        return true;
    }
    cout << "refused"
         << endl;
    return false;
}

int		Account::checkAmount( void ) const { return _amount; }

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    cout << "index:"
         << _accountIndex
         << ";amount:"
         << _amount
         << ";deposits:"
         << _nbDeposits
         << ";withdrawals:"
         << _nbWithdrawals
         << endl;
}
