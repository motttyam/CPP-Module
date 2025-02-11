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
        << "amount" << this->_amount << ";"
        << "created" << std::endl;
}

Account::Account(void) : _amount(0) {
    this->_accountIndex = _nbAccounts++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";"
        << "amount" << this->_amount << ";"
        << "created" << std::endl;
}

Account::~Account(){
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";"
        << "amount" << this->_amount << ";"
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

}

void Account::makeDeposit(int deposit){

}

bool Account::makeWithdrawal(int withdrawal) {
}

int Account::checkAmount() const {

}

void Account::displayStatus() const {
    
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