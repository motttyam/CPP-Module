#include "Harl.hpp"

Harl::Harl () {    
    // マップに各レベルとそれに対応する関数を設定する
    levelComments[0].level = "DEBUG";
    levelComments[0].harlFunc = &Harl::debug;
    levelComments[1].level = "INFO";
    levelComments[1].harlFunc = &Harl::info;
    levelComments[2].level = "WARNING";
    levelComments[2].harlFunc = &Harl::warning;
    levelComments[3].level = "ERROR";
    levelComments[3].harlFunc = &Harl::error;
}

void Harl::debug () {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;    
}

void Harl::info () {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;    
}

void Harl::warning () {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;    
}

void Harl::error () {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;    
}

void Harl::complain (const std::string &level) {

    // 構造体からキーを探索
    for (int i = 0; i < MAX_LEVEL; i++){
        if (levelComments[i].level == level){
            (this->*(levelComments[i].harlFunc))();
        }
    }
}
