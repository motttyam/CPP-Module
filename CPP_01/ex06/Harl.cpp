#include "Harl.hpp"

Harl::Harl () {    
    // マップに各レベルとそれに対応する関数を設定する
    levelComment["DEBUG"] = &Harl::debug;
    levelComment["INFO"] = &Harl::info;
    levelComment["WARNING"] = &Harl::warning;
    levelComment["ERROR"] = &Harl::error;

    //  マップに各レベルとそれに対応するPriorityValueを設定する
    levelPriority["DEBUG"] = 0;
    levelPriority["INFO"] = 1;
    levelPriority["WARNING"] = 2;
    levelPriority["ERROR"] = 3;
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

    // levelCommentマップからキーを探索
    std::map<std::string, ptrHarlFunc>::iterator it = levelComment.find(level);
    if (it != levelComment.end()) {
        (this->*(it->second))();
    }

}

void Harl::complainFilter (const std::string &level){

    // levelPriorityマップからキーを探索
    std::map<std::string, int>::iterator it = levelPriority.find(level);
    if (it != levelPriority.end()){
        switch (it->second) {
            case 0:
                std::cout << "[DEBUG]" << std::endl;
                this->complain("DEBUG");
                // fall through
            case 1:
                std::cout << "[INFO]" << std::endl;
                this->complain("INFO");
                // fall through
            case 2:
                std::cout << "[WARNING]" << std::endl;
                this->complain("WARNING");
                // fall through
            case 3:
                std::cout << "[ERROR]" << std::endl;
                this->complain("ERROR");
                // fall through

        }
    } else {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    } 
}
