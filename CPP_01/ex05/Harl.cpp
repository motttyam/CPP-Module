#include "Harl.hpp"

Harl::Harl () {    
    // マップに各レベルとそれに対応する関数を設定する
    levelComment["DEBUG"] = &Harl::debug;
    levelComment["INFO"] = &Harl::info;
    levelComment["WARNING"] = &Harl::warning;
    levelComment["ERROR"] = &Harl::error;
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

    // マップからキーを探索
    std::map<std::string, ptrHarlFunc>::iterator it = levelComment.find(level);
    if (it != levelComment.end()) {
        (this->*(it->second))();
    }
    else {
        std::cout << "Unknown Level" << std::endl;
    }

}
