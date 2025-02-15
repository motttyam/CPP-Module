#include "Account.hpp"
#include "iostream"
#include "ctime"
#include "iomanip"

// staticなメンバ変数の初期化
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


// 引数付きコンストラクタ・引数なしコンストラクタ・デストラクタの実装
Account::Account(int initial_deposit) : _amount(initial_deposit) {
    this->_accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;

    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "created" << std::endl;
}

Account::Account(void) : _amount(0) {
    this->_accountIndex = _nbAccounts++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "created" << std::endl;
}

Account::~Account(){
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "closed" << std::endl;
}

// 静的メソッドの実装
int Account::getNbAccounts(){
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(){
    return (Account::_totalAmount);
}

int Account::getNbDeposits(){
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(){
    return (Account::_totalNbWithdrawals);
}

// インスタンスメソッドの実装

void Account::displayAccountsInfos(){
    Account::_displayTimestamp();
    std::cout << " " << "accounts:" << Account::getNbAccounts() << ";"
        << "total:" << Account::getTotalAmount() << ";"
        << "deposits:" << Account::getNbDeposits() << ";"
        << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const {
    Account::_displayTimestamp();
    std::cout << " " << "index:" << this->_accountIndex << ";"
        << "amount" << this->_amount << ";"
        << "deposits:" << this->_nbDeposits << ";"
        << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit){
    int p_amount = Account::checkAmount();
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;

    Account::_displayTimestamp();
    std::cout << " " << "index:" << this->_accountIndex << ";"
        << "p_amount:" << p_amount << ";"
        << "deposit:" << deposit << ";"
        << "amount:" << Account::checkAmount() << ';'
        << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (this->_amount < withdrawal)
    {
        Account::_displayTimestamp();
        std::cout << " " << "index:" << this->_accountIndex << ";"
            << "p_amount:" << Account::checkAmount() << ";"
            << "withdrwal: refused" << std::endl;
        return (false);
    }
    Account::_displayTimestamp();
    int p_amount = Account::checkAmount();
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    this->_nbWithdrawals++;

    std::cout << " " << "index:" << this->_accountIndex << ";"
    << "p_amount:" << p_amount << ";"
    << "withdrawal:" << withdrawal << ";"
    << "amount:" << Account::checkAmount() << ";"
    << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount() const {
    return (this->_amount);
}

void Account::_displayTimestamp(void) {
    time_t now = std::time(0);
    std::tm *time = std::localtime(&now);

    // 1900年からの経過年数
    std::cout << "[" 
        << std::setw(2) << std::setfill('0') << time->tm_year + 1900 
        << std::setw(2) << std::setfill('0') << time->tm_mon + 1
        << std::setw(2) << std::setfill('0') << time->tm_mday
        << "_"
        << std::setw(2) << std::setfill('0') << time->tm_hour
        << std::setw(2) << std::setfill('0') << time->tm_min 
        << std::setw(2) << std::setfill('0') << time->tm_sec
        << "]" ;
}